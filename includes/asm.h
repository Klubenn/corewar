#ifndef COREWAR_ASM_H
#define COREWAR_ASM_H

#include <fcntl.h>
#include <stdio.h>
#include <limits.h>
#include "libft.h"
//#include <zconf.h>
#include "op.h"

typedef struct		s_label t_label;
typedef struct		s_instruction t_instruction;

enum err_message
{
	USAGE = 1,
	FILE_NAME,
	END_INPUT,
	NO_FILE,
	TOP_FILE,
	DOT_START,
	MALLOC_FAIL,
	LONG_NAME,
	LONG_COMM,
	COMM_BEFORE_NAME,
	QUOTES_BEGIN,
	QUOTES_END,
	SYNTAX_ERROR,
};

typedef	struct		s_op
{
	int 			func_num;
	int 			arg_num;
	unsigned char	arg[3];
	int 			arg_type_code;
	int 			t_dir_size;
	char			*name;
	char			n;
	char			carry;
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
	t_op			function;// from 0 to 16
    int			    num_of_args;
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
	int 			label_presence;
}					t_struct;

typedef void (*t_f)(int fd, t_struct *data, t_instruction *instruction, t_args argument);

t_struct *temp_data(char *name, char *comment); //temporary function. should be removed after 1st part is ready
void	print_file(char *new_file);
void	bin_exec_champ(int fd, t_struct *data);
void	write_backwards(int fd, void *source, int size);
void	instructions_position(t_struct *data);
void	check_labels(t_struct *data);
void    to_bytecode(char *new_file, t_struct *data);
void	error_management(int err, t_struct *data);
int		check_other_strings(int fd, char *str, t_struct *data);
int		check_label(t_struct *data, char *str);


#endif //COREWAR_ASM_H
