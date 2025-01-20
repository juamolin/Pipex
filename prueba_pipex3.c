#include <unistd.h>
#include <stdio.h>

int	ft_access(const char *pathname, int mode)
{
	if (access(pathname, mode) == 0)
	{
		if (mode == F_OK)
			printf("El archivo %s existe.\n", pathname);
		else if	(mode == R_OK)
			printf("El archivo %s se puede leer.\n", pathname);
		else if (mode == W_OK)
			printf("El archivo %s se puede escribir.\n", pathname);
		else if (mode == X_OK)
			printf("El archivo %s se puede ejecutar.\n", pathname);
		else
			printf("Modo de acceso desconocido.\n");
	}
	else
		perror("Error");
	return (0);
}

int	main(void)
{
	const char *pathname = "prueba.txt";

	ft_access(pathname, F_OK);
	ft_access(pathname, R_OK);
	ft_access(pathname, W_OK);
	ft_access(pathname, X_OK);
	return (0);
}