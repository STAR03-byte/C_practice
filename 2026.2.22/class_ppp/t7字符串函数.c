#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include<inttypes.h>
#include<stdbool.h>
#include<string.h>

int main(void)
{
	char* ptr = ",world\n";

	/*printf("%s\n", ptr);*/

	char dest[50] = "hello";

	/*strcpy_s(dest,6,string);*/

	printf("%zd\n", strlen(dest));

	rsize_t	dest_size = sizeof(dest) - strlen(dest) - 1;

	strcat_s(dest, sizeof(dest), ptr);

	printf("%s\n", dest);


	return 0;
}