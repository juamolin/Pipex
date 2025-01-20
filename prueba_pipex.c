#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int	main(void)
{
	int	fd;
	int	fd1;

	fd = open("prueba.txt", O_CREAT | O_WRONLY | O_APPEND);
	if (fd < 0)
		return(0);
	
	fd1 = open("prueba.txt", O_CREAT | O_WRONLY);
	if (fd1 < 0)
		return(0);
	write(fd, "ABCDEFGHIJK", 11);
	write(fd1, "@@@@@@", 6);
	return(0);
}