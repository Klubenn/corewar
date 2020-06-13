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
#include "op.h"
#include "asm.h"

void	free_data(t_struct *data)
{
	free(data);//TODO write more later
}

void	error_management(char *str, t_struct *data, int exiting)
{
	int error;

	error = 0;
	if (str)
	{
		ft_putstr_fd(str, 2);
		error = 1;
	}
	if (data)
		free_data(data);
	if (exiting)
		exit(error);
}

int		check_length(char *str, int is_name)//TODO можно при ошибке возвращать 0 или отрицательное значение, а если всё верно, позицию начала имени/комментария
{
	char *substring;
	int i;
	int len;

	i = 0;
	if (is_name)
		substring = ft_substr(str, 6);
	else
		substring = ft_substr(str, 9);
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

void	write_name_or_comment(char *str, t_struct *data)
{
	char *substring;
	int i;

	i = 0;
	if (ft_strnequ(str, NAME_CMD_STRING, 5) == 0)//
	{
		if (!check_length(str, 1))//TODO можно, чтобы эта функция возвращала указатель на место начала имени, если всё ок, чтобы потом выделить строку именно с этого момента (см. ниже)
		{
			free(str);
			error_management("length", data, 1);
		}
		substring = ft_strsub(str, 5, ft_strlen(str) - 1 - 5);
		while (substring[i] == ' ')
			i++;
		data->name = &(substring[i]);//TODO переделать, надо, чтобы указатель был на начале строки для дальнейшего освобождения структуры
	}
	else if (ft_strnequ(str, COMMENT_CMD_STRING, 8) == 0)//TODO то же, что и выше,только на начало комментария
	{
		if (!check_length(str, 0))
		{
			free(str);
			error_management("length", data, 1);
		}
		substring = ft_strsub(str, 8, ft_strlen(str) - 1 - 8);// ? -1
		while (substring[i] == ' ')
			i++;
		data->comment = &(substring[i]);//TODO переделать, надо, чтобы указатель был на начале строки для дальнейшего освобождения структуры
	}
	else
	{
		free(str);
		error_management("Only a name or comment can begin with a \'.\'", data, 1);
	}
}

int is_name_and_comment(t_struct *m_struct)
{
	return ((m_struct->name != NULL && m_struct->comment != NULL) ? 1 : 0);
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


void	check_other_strings(int fd, char *str, t_struct *data)
{
	char **file;
	int i;

	if (!is_name_and_comment(data))
	{
		free(str);
		close (fd);
		error_management("name and comment should be at the top of file", data, 1);
	}
	i = 0;
	file = malloc(sizeof(char *) * 100); //вот это мне не нравится
	file[i] = ft_strdup(str);
	free(str);
	while (get_next_line(fd, &str) > 0)
	{
		file[++i] = str;//записываю всё в массив
	}
	check_instruction_lines(file, data);

	//free_array(file);
}

t_struct	*is_valid_file(char *file_name)
{
	int			fd;
	char		*str;
	t_struct	*data;

	if ((fd = open(file_name, O_RDONLY)) == -1)
		error_management("can't open the file", NULL, 1);
	data = (t_struct *)ft_memalloc(sizeof(t_struct));
	while (get_next_line(fd, &str) > 0)//TODO добавить ф-цию удаления пробелов ft_strtrim
	{
		if (str[0] != '#' && str[0] != '\0')//TODO ft_strrchr #
		{
			if (str[0] == '.')
				write_name_or_comment(str, data);
			else
			{
				check_other_strings(fd, str, data); // TODO ';'
				break;
			}
		}
		free(str);
	}
	close(fd);
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
		error_management("error", NULL, 1);
	while (i < ac)
	{
		if (!(new_file = change_extension(av[i])))
			write(2, "Wrong file name. Should have an \".s\" extension\n", 47);
		else
		{
			data = is_valid_file(av[i]);
			instructions_position(data);//checks that code length isn't exceeded
			check_labels(data);
			to_bytecode(new_file, data);
			printf("file %s was successfully created\n", new_file);
			free_data(data);
		}
		i++;
	}
	return (0);
}
