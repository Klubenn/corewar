#include "asm.h"

void	write_backwards(int fd, void *source, int size)
{
	while (--size >= 0)
		write(fd, &(*(source + size)), 1);
}

void	bin_sign(int fd)
{
	int x = COREWAR_EXEC_MAGIC;

	write_backwards(fd, &x, sizeof(int));
}

void bin_champ_name(int fd, t_struct *data)
{
	char *name;

	name = (char *)ft_memalloc(PROG_NAME_LENGTH);
	if (data->name && name)
		ft_strcpy(name, data->name);
	write(fd, name, PROG_NAME_LENGTH);
	free(name);
}

void bin_null(int fd)
{
	int x = 0;

	write(fd, &x, 4);
}

void	bin_exec_code_size(int fd, t_struct *data)
{
	int size;

	size = data->code_length;
	write_backwards(fd, &size, sizeof(int));
}

void	bin_comment(int fd, t_struct *data)
{
	char *comment;

	comment = (char *)ft_memalloc(COMMENT_LENGTH * sizeof(char));
	if (data->comment)
		ft_strcpy(comment, data->comment);
	write(fd, comment, COMMENT_LENGTH);
}


void    to_bytecode(char *new_file, t_struct *data)
{
	int fd;

	fd = open(new_file, O_WRONLY | O_APPEND | O_TRUNC | O_CREAT, 0644);
	bin_sign(fd);
	bin_champ_name(fd, data);
	bin_null(fd);
	bin_exec_code_size(fd, data);
	bin_comment(fd, data);
	bin_null(fd);
//	bin_exec_champ(fd, data);
	close(fd);
}

char *change_extension(char *file_name)
{
	int i;
	char    *new_file;

	if (!file_name)
		return (NULL);
	i = ft_strlen(file_name);
	while (i >= 0)
	{
		if (file_name[i] == '.')
		{
			if (ft_strcmp(&(file_name[i]), ".s"))
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

t_op	op_calc(int num)
{
	t_op    op_tab[17] =
			{
					{0, 0, {0}, 0, 4},
					{1, 1, {T_DIR}, 0, 4},
					{2, 2, {T_DIR | T_IND, T_REG}, 1, 4},
					{3, 2, {T_REG, T_IND | T_REG}, 1, 4},
					{4, 3, {T_REG, T_REG, T_REG}, 1, 4},
					{5, 3, {T_REG, T_REG, T_REG}, 1, 4},
					{6, 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 1, 4},
					{7, 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 1, 4},
					{8, 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 1, 4},
					{9, 1, {T_DIR}, 0, 2},
					{10, 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 1, 2},
					{11, 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 1, 2},
					{12, 1, {T_DIR}, 0, 2},
					{13, 2, {T_DIR | T_IND, T_REG}, 1, 4},
					{14, 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 1, 2},
					{15, 1, {T_DIR}, 0, 2},
					{16, 1, {T_REG}, 1, 4}
			};
	return (op_tab[num]);
}

int		argument_size(t_instruction *instruction)
{
	t_op	op_data;
	int 	num;
	int 	size;
	int 	size_total;

	size_total = 0;
	op_data = op_calc(instruction->function);
	num = op_data.arg_num;
	while (num-- > 0)
	{
		size = 0;
		size += instruction->args_of_func[num].type == T_DIR ? op_data.t_dir_size : 0;
		size += instruction->args_of_func[num].type == T_IND ? 2 : 0;
		size += instruction->args_of_func[num].type == T_REG ? 1 : 0;
		size_total += size;
		instruction->args_of_func[num].size = size;
	}
	size_total += op_data.arg_type_code + 1;
	return (size_total);
}

void	instructions_position(t_struct *data)
{
	t_instruction *instruction;
	int position;

	position = 0;
	instruction = data->instruction;
	while(instruction)
	{
		instruction->position = position;
		position += argument_size(instruction);
		instruction = instruction->next;
	}
	data->code_length = position;
}

int main(int ac, char **av)
{
	char *new_file;
	t_struct *data;

	data = temp_data("COVID-19", "This city is mine");//this should come from Kate
	instructions_position(data);//calculate size of instructions and total code size
	if (!(new_file = change_extension(data->file_name))) //prepare a .cor ending name
	{
		write(2, "Wrong file name. Should have an \".s\" extension\n", 47);
		return (1);
	}
	to_bytecode(new_file, data); //create a file with a bytecode
//	print_file(new_file); //print the contents of the generated file in hex format
	return (0);
}