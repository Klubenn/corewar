#include <fcntl.h>
#include <stdio.h>
#include "libft/libft.h"
/*
void    to_bytecode(int fd)
{
    bin_sign(fd);
    bin_champ_name(fd);
    bin_null(fd);
    bin_exec_code_size(fd);
    bin_comment(fd);
    bin_null(fd);
    bin_exec_champ(fd);


} */

char *change_extension(char *file_name)
{
	int i;
	char    *new_file;

	i = 0;
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
				new_file[i + 4] = '\0';
				return (new_file);
			}
		}
		i--;
	}
	return (NULL);
}

int main(int ac, char **av)
{
	int fd;
	char *new_file;

	if (ac != 2)
	{
		printf("usage: ./asm champion_file.s");
		return (0);
	}
	if (!(new_file = change_extension(av[1])))
	{
		write(2, "Wrong file name. Should have an \".s\" extension\n", 47);
		return (1);
	}
	fd = open(new_file, O_WRONLY | O_APPEND | O_TRUNC | O_CREAT, 0644);
//	to_bytecode(fd);
	return (0);
}