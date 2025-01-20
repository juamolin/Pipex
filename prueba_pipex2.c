#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main(void)
{
	int	fd;
	ssize_t	bytes_read;
	char	buffer[10];

	fd = open("prueba2.txt", O_CREAT | O_WRONLY, 0444);
	if (fd < 0)
		return(0);

	write (fd, "ABCDEFGHIJK", 11);
	close(fd);

	fd = open("prueba2.txt", O_RDONLY);
	if (fd < 0)
		return(0);

	bytes_read = read(fd, buffer, 10);
	buffer[bytes_read] = '\0';

	printf("Bytes leidos: %ld\n", bytes_read);
	printf("Contenido: %s\n", buffer);
	close(fd);
	return(0);
}