// This file should be removed after the first part of asm is ready
// It is only needed to test the functionality of the second part
//

#include "asm.h"

#define LIVE	1
#define LD		2
#define ST		3
#define ADD		4
#define SUB		5
#define AND		6
#define OR		7
#define XOR		8
#define ZJUMP	9
#define LDI		10
#define STI		11
#define FORK	12
#define LLD		13
#define LLDI	14
#define LFORK	15
#define AFF		16

#define OPERATION	STI
#define ARGNUM		3
#define ARG_1 		T_REG
#define ARG_2 		T_DIR
#define ARG_3 		T_DIR

t_instruction *temp_instruction()
{
	t_instruction *instruction;

	instruction = (t_instruction *)ft_memalloc(sizeof(t_instruction));
	instruction->num_of_args = ARGNUM;
	instruction->function = OPERATION;
	if (ARGNUM >= 1)
		instruction->args_of_func[1].type = ARG_1;
	if (ARGNUM >= 2)
		instruction->args_of_func[2].type = ARG_2;
	if (ARGNUM == 3)
		instruction->args_of_func[3].type = ARG_3;
	return (instruction);
}

t_strings *temp_commands()
{
	t_strings *commands;

	commands = (t_strings *)ft_memalloc(sizeof(t_strings));
	commands->instruction = temp_instruction();
	return (commands);
}

t_struct *temp_data(char *name, char *comment)
{
	t_struct *data;

	data = (t_struct *)ft_memalloc(sizeof(t_struct));
	if (!data)
		return (NULL);
	data->comment = comment;
	data->name = name;
	data->commands = temp_commands();
	return (data);
}