#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int ft_dup2(int olfd, int newfd)
{
	int	fd = open("prueba.txt", O_WRONLY | O_CREAT | O_TRUNC);
	if (fd ==-1)
	{
		perror("open");
		return 1;
	}

	if (dup2(fd, STDOUT_FILENO) == -1)
	{
		perror("dup2");
		close(fd);
		return 1;
	}

	printf("Este mensaje va a 'prueba.txt'\n");
	close(fd);
	return (0);
}