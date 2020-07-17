/* ************************************************************************** */
/*																			  */
/*														:::	  ::::::::        */
/*   asm.c											  :+:	  :+:	:+:       */
/*													+:+ +:+		 +:+	      */
/*   By: etuffleb <etuffleb@student.42.fr>		  +#+  +:+	   +#+	          */
/*												+#+#+#+#+#+   +#+		      */
/*   Created: 2019/11/28 18:07:51 by etuffleb		  #+#	#+#			      */
/*   Updated: 2020/03/15 20:57:39 by etuffleb		 ###   ########.fr	      */
/*																			  */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "../libft/libft.h"
#include "../includes/op.h"
#include "../includes/asm.h"

void	print_error_message(enum err_message num)
{
	static char *ch[] = {
			NULL,
			"usage: ./asm file_name\n",											//USAGE
			"Wrong file name. Should have an \".s\" extension.\n",				//FILE_NAME
			"Syntax error - unexpected end of input. Missing end of line.\n",	//END_INPUT
			"Can't open the file.\n",											//NO_FILE
			"Name and comment should be at the top of file.\n",					//TOP_FILE
			"Only a name or a comment can begin with a \'.\'\n",				//DOT_START
			"Memory allocation failed.\n",										//MALLOC_FAIL
			"Champion name is too long.\n",										//LONG_NAME
			"Champion comment is too long.\n",									//LONG_COMM
			"Name and comment should start with the quotes.\n",					//QUOTES_BEGIN
			"Name and comment should end with the quotes.\n",					//QUOTES_END
			"Syntax error.\n",													//SYNTAX_ERROR
			"Wrong register number.\n",											//WRONG_REG
			"Wrong number.\n",													//WRONG_NUM
			"Error: duplicate labels.\n",										//DUPL_LABEL
			"File doesn't exist.\n",											//NOT_EXIST
			"Multiple champion names.\n",										//MULTIPLE_NAME
			"Multiple champion comments.\n",									//MULTIPLE_COMMENT

	};
	ft_putstr_fd(ch[num], 2);
}

char 		*trim_start(char *str, t_struct *data)
{
	if (str)
	{
		while(*str == ' ' || *str == '\t')
		{
			str++;
			data->position += 1;
		}
	}
	return (str);
}

int		check_ending(char *str)
{
	if (str)
	{
		while (*str == ' ' || *str == '\t')
			str++;
		if (!*str || *str == COMMENT_CHAR)
			return (0);
	}
	return (1);
}

void	free_data(t_struct *data)
{
	free(data);//TODO write more later
}

void	error_management(int err, t_struct *data)
{
	if (err)
	{
		if (data)
		{
			ft_putstr_fd("Error on line ", 2);
			ft_putnbr_fd(data->line, 2);
			ft_putstr_fd(", position ", 2);
			ft_putnbr_fd(data->position, 2);
			ft_putstr_fd(": ", 2);
		}
		print_error_message(err);
		if (data)
		{
			ft_putendl_fd(data->str, 2);
			while ((data->position)--)
				ft_putchar_fd(' ', 2);
			ft_putendl_fd("^", 2);
		}
	}
	if (data)
		free_data(data);
	exit(1);
}

char *remove_comment_from_string(char *str)
{
	char *tmp;

	if (!(tmp = ft_strchr(str, COMMENT_CHAR)))
		return (ft_strdup(str));
	return (ft_strndup(str, tmp - str));
}

char *cut_string(char *str)
{
	int i;
	char *new;

	i = 0;
	while (*str == ' ' || *str == '\t')
		str++;
	while (str[i] && str[i] != COMMENT_CHAR)
		i++;
	if (!(new = ft_strndup(str, i)))
		return (NULL);
	return (new);
}

int	check_other_strings(char *str, t_struct *data)
{
	t_op *op;
	int if_label;
	char *cut_str;
	int result;

	if ((if_label = check_label(data, str)) < 0)
		return (MALLOC_FAIL);
	if (!check_ending(str + if_label))
		return (0);
	if (!(cut_str = cut_string(str + if_label)))
		return (MALLOC_FAIL);
	if (!(op = check_op(cut_str)))
	{
		free(cut_str);
		return (SYNTAX_ERROR);
	}
	str = trim_start(cut_str + ft_strlen(op->name), data);
	result = check_param(data, str, op);
	free(cut_str);
	return (result);
}

void	free_strings(char *str1, char *str2, char *str3, char *str4)
{
	free(str1);
	free(str2);
	free(str3);
	free(str4);
}

int 	finish_reading(char **string, char *tmp2, char *small, char *big)
{
	char *tmp1;

	if (big)
		tmp1 = big;
	else
		tmp1 = ft_strdup("\n");
	if (!check_ending(tmp2 + 1))
	{
		big = ft_strndup(small, tmp2 - small);
		*string = ft_strjoin(tmp1, big);
		free_strings(small, tmp1, big, NULL);
		return (0);
	}
	free_strings(small, tmp1, NULL, NULL);
	return (SYNTAX_ERROR);
}

int		continue_reading(int fd, char **string, t_struct *data)
{
	char *small;
	char *big;
	char *tmp1;
	char *tmp2;
	tmp1 = ft_strdup("\n");
	big = NULL;
	while(get_next_line(fd, &small) > 0 && ++(data->line))
	{
		data->str = small;
		data->position = 0;
		if ((tmp2 = ft_strchr(small, '"')))
			return (finish_reading(string, tmp2, small, big));
		tmp2 = ft_strjoin(tmp1, small);
		big = ft_strjoin(tmp2, "\n");
		free_strings(tmp1, tmp2, small, NULL);
		tmp1 = big;
		data->str = NULL;
		if (ft_strlen(big) > COMMENT_LENGTH)
			break ;
	}
	free(tmp1);
	return(QUOTES_END);
}

int 	write_name_comment(char *substring, t_struct *data, size_t len)
{
	if (len == PROG_NAME_LENGTH)
	{
		if (ft_strlen(substring) > len)
		{
			free(substring);
			return (LONG_NAME);
		}
		data->name = substring;
	}
	else
	{
		if (ft_strlen(substring) > len)
		{
			free(substring);
			return (LONG_COMM);
		}
		data->comment = substring;
	}
	return (0);
}

int		extract_name_comment(char *str, t_struct *data, int fd, int len)
{
	char *substring;
	char *add_string;
	int i;

	str = trim_start(str, data);
	if (!*str || *str != '"')
		return(QUOTES_BEGIN);
	i = 1;
	while (str[i] && str[i] != '"')
		i++;
	if (!str[i])
	{
		if ((i = continue_reading(fd, &add_string, data)))
			return (i);
		substring = ft_strjoin(str + 1, add_string);
		free(add_string);
	}
	else if (!check_ending(str + i + 1))
		substring = ft_strndup(str + 1, i - 1);
	else
		return (SYNTAX_ERROR);
	return (write_name_comment(substring, data, len));
}

void	process_name_and_comment(char *str, t_struct *data, int fd)
{
	int err;

	str = trim_start(str, data);
	if (*str == COMMENT_CHAR || !*str)
		return ;
	if (ft_strnequ(str, NAME_CMD_STRING, 5))
		err = (data->name ? MULTIPLE_NAME : extract_name_comment(str + 5, data, fd, PROG_NAME_LENGTH));
	else if (ft_strnequ(str, COMMENT_CMD_STRING, 8))
		err = (data->comment ? MULTIPLE_COMMENT : extract_name_comment(str + 8, data, fd, COMMENT_LENGTH));
	else
		err = (TOP_FILE);
	if (err)
		error_management(err, data);
}

void		process_string(char *str, t_struct *data, int fd)
{
	int		error;
	char	*str_trim;

	str_trim = trim_start(str, data);
	if (!*str_trim || *str_trim == COMMENT_CHAR)
		return ;
	if (*str_trim == '.')
	{
		if (ft_strnequ(str, NAME_CMD_STRING, 5))
			error = MULTIPLE_NAME;
		else if (ft_strnequ(str, COMMENT_CMD_STRING, 8))
			error = MULTIPLE_COMMENT;
		else
			error = DOT_START;
	}
	else
		error = check_other_strings(str_trim, data);
	if (error)
	{
		free(str);
		close (fd);
		error_management(error, data);
	}
}

void	*is_valid_file(char *file_name, t_struct *data)
{
	int			fd;
	int 		flag;
	char		*str;

	flag = 1;
	if ((fd = open(file_name, O_RDONLY)) == -1)
		error_management(NO_FILE, data);
	while (get_next_line(fd, &str) > 0 && ++(data->line))
	{
		data->str = str;
		data->position = 0;
		if (!data->name || !data->comment)
			process_name_and_comment(str, data, fd);
		else
			process_string(str, data, fd);
		flag = check_ending(str);
		free(str);
		data->str = NULL;
	}
	close(fd);
	if (flag)
		error_management(END_INPUT, data);
}

t_struct *change_extension(char *file_name)
{
	int i;
	t_struct *data;

	if (!file_name)
		error_management(NOT_EXIST, NULL);
	i = ft_strlen(file_name);
	while (i >= 0)
	{
		if (file_name[i] == '.')
		{
			if (i == 0 || ft_strcmp(file_name + i, ".s"))
				error_management(FILE_NAME, NULL);
			else
			{
				if (!(data = (t_struct *)ft_memalloc(sizeof(t_struct))) ||
				!(data->file_name = (char *)ft_memalloc((i + 5) * (sizeof(char)))))
					error_management(MALLOC_FAIL, data);
				ft_strncpy(data->file_name, file_name, i);
				ft_strncpy(data->file_name + i, ".cor", 4);
				return (data);
			}
		}
		i--;
	}
	return (NULL);
}

int		main(int ac, char **av)
{
	int			i;
	t_struct	*data;

	i = 1;
	if (ac < 2)
		error_management(USAGE, NULL);
	while (i < ac)
	{
		if (!(data = change_extension(av[i])))
			error_management(FILE_NAME, NULL);
		else
		{
			is_valid_file(av[i], data);
			instructions_position(data);
			check_labels(data);
			to_bytecode(data);

			ft_putstr("file ");
			ft_putstr(data->file_name);
			ft_putendl(" was successfully created");//как альтернатива

			free_data(data);
		}
		i++;
	}
	return (0);
}
