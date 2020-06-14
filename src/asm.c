//
// Created by Somebody on 11.06.2020.
//

/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   asm.c											  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: etuffleb <etuffleb@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2019/11/28 18:07:51 by etuffleb		  #+#	#+#			 */
/*   Updated: 2020/03/15 20:57:39 by etuffleb		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include <stdio.h>
#include <libft.h>
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
			"Champion comment is too long.\n",									//LONG_COMMENT
			"Champion name must be before comment.\n",							//COMM_BEFORE_NAME
			"Name and comment should start with the quotes.\n",					//QUOTES_BEGIN
	};
	ft_putstr_fd(ch[num], 2);
}

void	free_data(t_struct *data)
{
	free(data);//TODO write more later
}

void	error_management(int err, t_struct *data)
{
	if (err)
		print_error_message(err);
	if (data)
		free_data(data);
	exit(1);
}

void set_command(t_struct *m_struct, int command,  t_args *args)
{
	m_struct->instructions[i] = malloc();
	m_struct->instructions[i]->function = command;
	m_struct->instructions[i]->args = args;
}

void check_instruction_lines(char **file, t_struct *m_struct)
{
	int i = 0;

	while (i < file.length)
	{
		//check_instruction_line(file, i, m_struct);
	}
}

int	check_other_strings(int fd, char *str, t_struct *data)
{
	char **file;
	int i;


	i = 0;
	file = malloc(sizeof(char *) * 100); //вот это мне не нравится
	file[i] = ft_strdup(str);
	free(str);
	while (get_next_line(fd, &str) > 0)
	{
		file[++i] = str;//записываю всё в массив
	}
	check_instruction_lines(file, data);
	//TODO if error
	//free_array(file);
}

char *continue_reading(int fd)
{

}

int		check_length(char *str, int fd, int is_name)
{
	char *substring;
	int i;
	int len;

	while (*str == ' ' || *str == '\t')
		str++;
	if (!*str || *str != '"')
		return(QUOTES_BEGIN);
	else
	{
		i = 1;
		while (str[i] && str[i] != '"')
			i++;
		if (!str[i])
			substring = ft_strjoin(str, continue_reading(fd));
	}

	if (is_name)
		data->name = substring;
	else
		data->comment = substring;
	while (substring[i] == ' ')
		i++;
	len = ft_strlen(&(substring[i])) - 1;//;
	if ((is_name && len > PROG_NAME_LENGTH) ||
		(!is_name && len > COMMENT_LENGTH) ||
		(len < 1))
		return 0;
	else
		return 1;
}

int 	extract_name(char *str, t_struct *data, int fd)
{
	if (!check_length(str, fd, 1))
		return (LONG_NAME);
	substring = ft_strsub(str, 5, ft_strlen(str) - 1 - 5);
	while (substring[i] == ' ')
		i++;
	data->name = &(substring[i]);
}

int		extract_comment(char *str, t_struct *data, int fd)
{
	if (!check_length(str + 8, 0))
		return (LONG_COMMENT);
	substring = ft_strsub(str, 8, ft_strlen(str) - 1 - 8);// ? -1
	while (substring[i] == ' ')
		i++;
	data->comment = &(substring[i]);//TODO переделать, надо, чтобы указатель был на начале строки для дальнейшего освобождения структуры
}

void	write_name_or_comment(char *str, t_struct *data, int fd)
{
	int err;

	while (*str == ' ' || *str == '\t')
		str++;
	if (*str == COMMENT_CHAR || !*str)
		return ;
	if (ft_strnequ(str, NAME_CMD_STRING, 5) == 0)
		err = extract_name(str, data, fd);
	else if (ft_strnequ(str, COMMENT_CMD_STRING, 8) == 0)
		err = (data->name ? extract_comment(str, data,fd) : COMM_BEFORE_NAME);
	else
		err = (TOP_FILE);
	if (err)
		error_management(err, data);
}

void		process_string(char *str, t_struct *data, int fd)
{
	int		error;
	char	*str_trim;

	str_trim = ft_strtrim(str);
	if (!*str_trim || *str_trim == COMMENT_CHAR)
		return ;
	if (*str_trim == '.')
		error = DOT_START;
	else
		error = check_other_strings(fd, str_trim, data);
	free(str_trim);
	if (error)
	{
		free(str);
		close (fd);
		error_management(error, data);
	}
}
/*

TODO ft_strrchr # чтобы отсечь комментарии с конца

 */

int is_name_and_comment(t_struct *m_struct)
{
	return ((m_struct->name != NULL && m_struct->comment != NULL) ? 1 : 0);
}

int			check_end_input(char *str)
{
	while (*str == ' ' || *str == '\t')
		str++;
	return (*str ? 0 : 1);
}

t_struct	*is_valid_file(char *file_name)
{
	int			fd;
	int 		flag;
	char		*str;
	t_struct	*data;

	flag = 0;
	if ((fd = open(file_name, O_RDONLY)) == -1)
		error_management(NO_FILE, NULL);
	if (!(data = (t_struct *)ft_memalloc(sizeof(t_struct))))
		error_management(MALLOC_FAIL, NULL);
	while (get_next_line(fd, &str) > 0)
	{
		if (!is_name_and_comment(data))
			write_name_or_comment(str, data, fd);
		else
			process_string(str, data, fd);
		flag = check_end_input(str);
		free(str);
	}
	close(fd);
	if (!flag)
		error_management(END_INPUT, data);
	return (data);
}

char *change_extension(char *file_name)
{
	int i;
	char	*new_file;

	if (!file_name)
		return (NULL);
	i = ft_strlen(file_name);
	while (i >= 0)
	{
		if (file_name[i] == '.')
		{
			if (i == 0 || ft_strcmp(file_name + i, ".s"))
				return (NULL);
			else
			{
				new_file = (char *)ft_memalloc((i + 5) * (sizeof(char)));
				ft_strncpy(new_file, file_name, i);
				ft_strncpy(&(new_file[i]), ".cor", 4);
				return (new_file);
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
	char		*new_file;

	i = 1;
	if (ac < 2)
		error_management(USAGE, NULL);
	while (i < ac)
	{
		if (!(new_file = change_extension(av[i])))
			error_management(FILE_NAME, NULL);
		else
		{
			data = is_valid_file(av[i]);
			instructions_position(data);
			check_labels(data);
			to_bytecode(new_file, data);
			printf("file %s was successfully created\n", new_file);//TODO change to ft_printf
			free_data(data);
		}
		i++;
	}
	return (0);
}
