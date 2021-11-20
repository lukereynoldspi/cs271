#include "parser.h"

int main(int argc, char const *argv[])
{
	if(argc != 2)
	{
    // incorrect number of arguments
    	exit_program(EXIT_INCORRECT_ARGUMENTS, argv[0]);   
	}

	FILE *fin = fopen( argv[1], "r" );
	if(fin == NULL)
	{
		exit_program(EXIT_CANNOT_OPEN_FILE, argv[1]);
	}

	parse(fin);
	fclose(fin);

}