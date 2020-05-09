/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etuffleb <etuffleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 18:07:51 by etuffleb          #+#    #+#             */
/*   Updated: 2020/03/15 20:57:39 by etuffleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include "asm.h"


#define COMMENT_CHAR		'#'
#define ALT_COMMENT_CHAR	';'

#define LABEL_CHAR			':'
#define DIRECT_CHAR			'%'
#define SEPARATOR_CHAR		','

#define LABEL_CHARS			"abcdefghijklmnopqrstuvwxyz_0123456789"

#define NAME_CMD_STRING		".name"
#define COMMENT_CMD_STRING	".comment"

#define PROG_NAME_LENGTH		(128)
#define COMMENT_LENGTH			(2048)
#define COREWAR_EXEC_MAGIC		0xea83f3


typedef struct		s_labels
{
	char			*label_name;
}					t_labels;


typedef struct		s_args
{
	int				type;//from 0 to 3 : NULL, T_REG, T_DIR or T_IND
	char			*str;
}					t_args;


typedef struct		s_instruction
{
	int				function;// from 0 to 16
	int				num_of_args;
	t_args			args_of_func[num_of_args];

}					t_instruction;


typedef struct		s_strings
{
	t_labels		*labels;
	t_instruction	instruction;
}					t_strings;


typedef struct		s_struct
{
	char			*name;
	char			*comment;
	t_strings		*commands;

}					t_struct;


int		check_length(char *str, int is_name)
{
	char *substring;
	int i = 0;
	int strlen;

	if (is_name)
		substring = ft_substr(str, 6);
	else
		substring = ft_substr(str, 9);
	while (substring[i] == ' ')
		i++;
	strlen = ft_strlen(&(substring[i])) - 1;//;
	if ((is_name && strlen > PROG_NAME_LENGTH) ||
		(!is_name && strlen > COMMENT_LENGTH) ||
		(strlen < 1))
		return 0;
	else
		return 1;
}

void	set_name_or_comment(char *str, int is_name, t_struct *m_struct)
{
	char *substring;//free
	int i = 0;

	if (is_name)
		substring = ft_strsub(str, 5, ft_strlen(str) - 1 - 5);
	else
		substring = ft_strsub(str, 8, ft_strlen(str) - 1 - 8);
	while (substring[i] == ' ')
		i++;
	if (is_name)
		m_struct->name = &(substring[i]);
	else
		m_struct->comment = &(substring[i]);
}

void	is_correct_name_or_comment(char *str, t_struct *m_struct)
{
	int is_name;

	if (str[ft_strlen(str) - 1] != ';')
		ft_error(';');

	is_name = -1;
	if (str[1] == 'n' && ft_strnequ(str, NAME_CMD_STRING, 5) == 0)
		is_name = 1;
	else if (str[1] == 'c' && ft_strnequ(str, COMMENT_CMD_STRING, 8) == 0)
		is_name = 0;
	else
		ft_error("Only a name or comment can begin with a \'.\'");


	if (check_length(str, is_name))
		set_name_or_comment(str, is_name, m_struct);
	else
		ft_error("length");

}

int is_name_and_comment(t_struct *m_struct)
{
	return (m_struct->name != NULL && m_struct->comment != NULL) ? 1 : 0;
}

void check_string(char *str, t_struct *m_struct)
{
	if (is_it_mark())

		if (is_it_command())
		{
			command = is_correct_command(str);
			is_correct_argument_types(command);
		}


}


void check_other_strings(int fd, char *str, t_struct *m_struct)
{
	check_string(str, m_struct);

	while (gnl(fd, &str) > 0)
	{
		check_string(str, m_struct);


	}




}



void	refresh_main_struct(t_struct *main_struct)
{
	main_struct->comment = NULL;
	main_struct->name = NULL;
	main_struct->commands = NULL;
}


t_struct	*is_valid_file(char *file_name)
{
	int fd;
	char *str;
	int command;
	t_struct *main_struct;

	main_struct = (t_struct *)malloc(sizeof(t_struct));
	refresh_main_struct(main_struct);
	fd = open(file_name, O_RDONLY);
	while (gnl(fd, &str) > 0)
	{
		if (str[0] == '\0' || str[0] == '#')
			continue;
		if (str[0] == '.')
			is_correct_name_or_comment(str, main_struct);// checked ';'
		else if (is_name_and_comment(main_struct))//!!!!!!!!!
		{
			check_other_strings(fd, str, main_struct);//to check ';'
			break;
		}
		else
			ft_error("name and comment should be of the top of file", main_struct);
	}//free str ?!
	//is_all_right(&main_struct);
	return main_struct;
}

int		main(int ac, char **av)
{
	int			i;
	t_struct	*all_info;

	i = 1;
	while (i < ac)
	{
		all_info = is_valid_file(av[i]);
		//create_byte_file(av[i], all_info);//buffer?
		free_main_struct(all_info);
		i++;
	}
	return 0;
}
