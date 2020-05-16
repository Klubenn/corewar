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

void	f_reg(int fd, t_struct *data, char *str)
{
	unsigned char reg_num;

	reg_num = (unsigned char)ft_atoi(str);//if str contains "r", then ft_atoi(str+1)
	if (reg_num > 0  && reg_num <= 16)
		write(fd, &reg_num, 1);
}

void	f_dir(int fd, t_struct *data, char *str)
{

}

void	f_ind(int fd,t_struct *data, char *str)
{

}

void arguments_code(int fd, t_struct *data, t_instruction *instruction)
{
	int i;
	f func[4] = {NULL, &f_reg, &f_dir, &f_ind};

	i = 0;
	while (i++ <= instruction->num_of_args)
		func[instruction->args_of_func[i].type](fd, data, instruction->args_of_func[i].str);


}

void	bin_exec_champ(int fd, t_struct *data)
{
	while (data->instruction)
	{
		operation_code(fd, data->instruction);
		arguments_code(fd, data, data->instruction);
	}

}