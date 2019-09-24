#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 50

int main(int argc, char const *argv[])
{
	
	char *str = (char*)calloc(N, sizeof(char));
	printf("Introduce algo: ");
	scanf("%[^\n]", str);

	/*fgets(str, N, stdin);
	if(str[strlen(str) - 1] == '\n')
		str[strlen(str) - 1] = 0;*/

	for (int i = 0; i < strlen(str); ++i)
	{
		printf("%c", str[i]);
	}

	str[2] = str[6] = str[5] = 'w';

	for (int i = 0; i < strlen(str); ++i)
	{
		printf("%c", str[i]);
	}


	return 0;
}




/* Codificacion 2 */
for (int i = 0; i < strlen(str) - 1; i += 2) {
	str[i] = desencolarPrimero(&cola);
	str[i+1] = desencolarUltimo(&cola);
}
