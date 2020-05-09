#ifndef COREWAR_ASM_H
#define COREWAR_ASM_H

#include <fcntl.h>
#include <stdio.h>
#include "libft/libft.h"
#include <zconf.h>
#include "op.h"

typedef struct		s_strings t_strings;
typedef struct		s_labels
{
	char			*label_name;
}					t_labels;

typedef struct		s_args
{
	unsigned char	type;//from 0 to 3 : NULL, T_REG, T_DIR or T_IND
	char			*str;
}					t_args;

typedef struct		s_instruction
{
	int				function;// from 0 to 16
	int				num_of_args;
	t_args			args_of_func[4];

}					t_instruction;


struct				s_strings
{
	t_labels		*labels;
	t_instruction	*instruction;
	t_strings		*next;
	t_strings		*prev;
};

typedef struct		s_struct
{
	char			*name;
	char			*comment;
	t_strings		*commands;

}					t_struct;

t_struct *temp_data(char *name, char *comment); //temporary function. should be removed after 1st part is ready
void	print_file(char *new_file);
void	bin_exec_champ(int fd, t_struct *data);

#endif //COREWAR_ASM_H
