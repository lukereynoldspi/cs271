#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_LINE_LENGTH  200
/** Exercise 1 **/

int main(int argc, const char *argv[])
{
	

	/** Exercise 2 **/
	if(argc != 2)
	{
		// if incorrect number of arguments
		printf("Usage: %s [filename]\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	/** Exercise 3 **/
	FILE *fin = fopen( argv[1], "r" );

	if(fin == NULL)
	{
		perror("Unable to open file!");
		exit(EXIT_FAILURE);
	}
	char out_file[100] = "";
	strcpy(out_file, argv[1]);
	strcat(out_file, ".echo");

	/** Exercise 4 **/
	FILE *fout = fopen(out_file, "w+");
	/** Exercise 5 **/
	char line[MAX_LINE_LENGTH] = {0};
	unsigned int line_num = 0;
	while (fgets(line, sizeof(line), fin))
	{
		line_num += 1;
		printf( "%04d %s", line_num, line);
		fprintf(fout, line);
	}
	/** Exercise 6 **/
	fclose(fin);
	fclose(fout);


}
