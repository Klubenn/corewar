#ifndef COREWAR_ASM_H
#define COREWAR_ASM_H

#include <fcntl.h>
#include <stdio.h>
#include <limits.h>
#include "libft.h"
#include "header_pf.h"
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
	QUOTES_BEGIN,
	QUOTES_END,
	SYNTAX_ERROR,
	WRONG_REG,
	WRONG_NUM,
	DUPL_LABEL,
	NOT_EXIST,
	MULTIPLE_NAME,
	MULTIPLE_COMMENT,
};


typedef	struct		s_op
{
	char			*name;
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
	unsigned char	type;// NULL, T_REG, T_DIR or T_IND
	int 			size;
	char			*str;
}					t_args;

struct 				s_instruction
{
	int 			position;
	char			function;
	t_op 			*op;
    int			    num_of_args;
	t_args			**args_of_func;
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
	int 			label_present;
	char			*str;
	int 			line;
	int 			position;
}					t_struct;

typedef void (*t_f)(int fd, t_struct *data, t_instruction *instruction, t_args *argument);

void	print_file(char *new_file);
void	bin_exec_champ(int fd, t_struct *data);
void	write_backwards(int fd, void *source, int size);
void	instructions_position(t_struct *data);
void	check_labels(t_struct *data);
void    to_bytecode(t_struct *data);
void	error_management(int err, t_struct *data);
int		check_other_strings(char *str, t_struct *data);
int		check_label(t_struct *data, char *str);
int     create_instruction(t_op *op, char **params, t_struct *data);
int		create_args(t_args **args_of_func, char **params);
int     check_type(char **params, t_op *op);
char	*trim_start(char *str, t_struct *data);
t_op	*check_op(char *str);
int 	skip_spaces(char* str);
int 	skip_word(char* str);
int 	check_param(t_struct *data, char *str, t_op *op);
char    get_type(char *param);
int		check_ending(char *str);

#endif //COREWAR_ASM_H
