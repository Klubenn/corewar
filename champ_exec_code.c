#include "asm.h"

void	argument_type(int fd, t_instruction *instruction)
{
	unsigned char	arg_num[4];
	unsigned char	arg_type;
	int				i;

	arg_type = 0;
	i = 1;
	while (i <= instruction->num_of_args)
	{
		arg_num[i] = instruction->args_of_func[i].type;
		arg_num[i] = arg_num[i] << ((4 - i) * 2);
		arg_type = arg_type | arg_num[i];
		i++;
	}
	write(fd, &arg_type, 1);
}

void	operation_code(int fd, t_instruction *instruction)
{
	char	op_code;

	op_code = (char)instruction->function;
	write(fd, &op_code, 1);
	if (op_code != 1 && op_code != 9 && op_code != 12 && op_code != 15)
		argument_type(fd, instruction);
}

void	bin_exec_champ(int fd, t_struct *data)
{
//	while (data->commands)
//	{
		operation_code(fd, data->commands->instruction);
/*		arguments(fd, data->commands->instruction);
		data->commands = data->commands->next;
	}
*/
}