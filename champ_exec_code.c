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

int 	find_label(t_struct *data, char *label_from_instruc)
{
	t_label	*label;

	label = data->label;
	while (label)
	{
		if (strcmp(label->label_name, label_from_instruc) == 0)
			return (label->instruction->position);
		label = label->next;
	}
	return (-1);
}

void	f_reg(int fd, t_struct *data, t_instruction *instruction, t_args argument)
{
	unsigned char reg_num;

	reg_num = (unsigned char)ft_atoi((argument.str) + 1);
	if (reg_num > 0  && reg_num <= 16)
		write(fd, &reg_num, 1);
	else
		exit (1);//invoke error function
}

void	f_dir(int fd, t_struct *data, t_instruction *instruction, t_args argument)
{
	//
}

void	f_ind(int fd,t_struct *data, t_instruction *instruction, t_args argument)
{
	short	ind_num;
	char	*result;

	ind_num = (short)(-1 * instruction->position);
	if (argument.str[0] == ':')
	{
		ind_num += (short)find_label(data, argument.str + 1);
		write_backwards(fd, ind_num, sizeof(short));//check if it should be written backwards or not
	}
	else
	{
		result = corewar_atoi(argument.str, &ind_num);//rewrite atoi to check

	}
}

void arguments_code(int fd, t_struct *data, t_instruction *instruction)
{
	int i;
	t_f func[4] = {NULL, &f_reg, &f_dir, &f_ind};

	i = 0;
	while (i++ <= instruction->num_of_args)
		func[instruction->args_of_func[i].type](fd, data, instruction, instruction->args_of_func[i]);


}

void	bin_exec_champ(int fd, t_struct *data)
{
	t_instruction *instruction;

	instruction = data->instruction;
	while (instruction)
	{
		operation_code(fd, instruction);
		arguments_code(fd, data, instruction);
		instruction = instruction->next;
	}

}