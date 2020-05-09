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
	int x;

	x = 255;	// calculate size
	write_backwards(fd, &x, sizeof(int));
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
//	bin_sign(fd);
//    bin_champ_name(fd, data);
//    bin_null(fd);
//    bin_exec_code_size(fd, data);
//    bin_comment(fd, data);
//    bin_null(fd);
    bin_exec_champ(fd, data);
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

int main(int ac, char **av)
{
	char *new_file;
	t_struct *data;

	data = temp_data("COVID-19", "This city is mine");//this should come from Kate
	if (ac != 2)
	{
		printf("usage: ./asm champion_file.s");
		return (0);
	}
	if (!(new_file = change_extension(av[1]))) //prepare a .cor ending name
	{
		write(2, "Wrong file name. Should have an \".s\" extension\n", 47);
		return (1);
	}
	to_bytecode(new_file, data); //create a file with a bytecode
	print_file(new_file); //print the contents of the generated file in hex format
	return (0);
}