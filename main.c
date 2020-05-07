#include <stdio.h>
#include <fcntl.h>
#include <zconf.h>

void read_file(int fd)
{
	unsigned char	c;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while(read(fd, &c, 1))
	{
		i++;
		printf("%02x", (int)c);
		if (i % 2 == 0)
		{
			j++;
			if(j == 8)
			{
				i = 0;
				j = 0;
				printf("\n");
			}
			else
				printf(" ");
		}
	}
}

int main(int ac, char **av)
{
	int fd;
	if (av[1])
	{
		fd = open(av[1], O_RDONLY);
		read_file(fd);
	}
	return 0;
}
