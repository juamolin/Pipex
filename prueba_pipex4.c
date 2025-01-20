#include <unistd.h>
#include <stdio.h>

int main(void)
{
	if (access("prueba.txt", R_OK)== 0)
		printf("readfile es accesible en modo lectura\n");
	if (access("prueba.txt", W_OK) == 0)
		printf("writefile es accesible en modo escritura\n");
	if (access("prueba.txt", X_OK) == 0)
		printf("executefile es accesible en modo ejecución\n");
	if (access("prueba.txt", R_OK|W_OK) == 0)
		printf("rwfile es accesible en modo lectura y escritura\n");
}