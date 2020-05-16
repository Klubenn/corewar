#ifndef COREWAR_ASM_H
#define COREWAR_ASM_H

#include <fcntl.h>
#include <stdio.h>
#include "libft/libft.h"
#include <zconf.h>
#include "op.h"

typedef struct		s_label t_label;
typedef struct		s_instruction t_instruction;


typedef	struct		s_op
{
	int 			func_num;
	int 			arg_num;
	unsigned char	arg[3];
	int 			arg_type_code;
	int 			t_dir_size;
}					t_op;

struct				s_label
{
	char			*label_name;
	t_instruction	*instruction;
	t_label			*next;
};

typedef struct		s_args
{
	unsigned char	type;//from 0 to 3 : NULL, T_REG, T_DIR or T_IND
	int 			size;
	char			*str;
}					t_args;

struct 				s_instruction
{
	int 			position;
	int				function;// from 0 to 16
	int				num_of_args;
	t_args			args_of_func[4];
	t_instruction	*next;
};

typedef struct		s_struct
{
	char			*file_name;
	char			*name;
	char			*comment;
	int 			code_length;
	t_instruction	*instruction;
	t_label			*label;
}					t_struct;

typedef void (*f)(int, t_struct *, char *);

t_struct *temp_data(char *name, char *comment); //temporary function. should be removed after 1st part is ready
void	print_file(char *new_file);
void	bin_exec_champ(int fd, t_struct *data);

#endif //COREWAR_ASM_H
