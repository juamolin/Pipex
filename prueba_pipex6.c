#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>

int	ft_dup2(int olfd, int newfd)
{
	if (fcntl(olfd, F_GETFL) == -1)
	{
		errno = EBADF;
		return (-1);
	}
	
	if (olfd == newfd)
		return (newfd);
	close (newfd);

	int	temp_fd;

	temp_fd = fcntl(olfd, F_DUPFD, newfd);
	if (temp_fd == -1)
		return (-1);
	return (temp_fd);
}

int	main(void)
{
	int	fd = open("prueba.txt", O_WRONLY | O_CREAT | O_TRUNC);
	if (fd == -1)
	{
		perror("open");
		return (1);
	}

	if (ft_dup2(fd, STDOUT_FILENO) == -1)
	{
		perror("ftdup2");
		close(fd);
		return (1);
	}

	printf("Este mensaje va a 'prueba.txt'\n");
	close(fd);
	return(0);
}
/*
int main(void)
{

		int invalid_fd = -1;

	if (ft_dup2(invalid_fd, STDOUT_FILENO) == -1)
	{
		if (errno == EBADF)
			printf("Error: Descriptor de archivo no valido.\n");
		else
			perror("ft_dup2");
	}
	return (0);
}*/