#include "parser.h"

bool is_Atype(const char *line)
{
	if (line[0] != '@')

		return false;
	else
		return true;
}

bool is_label(const char *line)
{
	if (line[0] == '(' && line[-1] == ')')
		return true;
	else
		return false;
}

bool is_Ctype(const char *line)
{
	if (is_label(line) || is_Atype(line))
		return false;
	else
		return true;
}

void parse(FILE * file)
{
	char line[MAX_LINE_LENGTH] = {0};
	while (fgets(line, sizeof(line), file))
	{
		strip(line);
		if(!*line)
			continue;
		char inst_type;
		if(is_Atype(line))
		{
			inst_type = 'A';
		}

		else if(is_label(line))
		{
			inst_type = 'L';
		}

		else if(is_Ctype(line))
		{
			inst_type = 'C';
		}
		printf("%c  %s\n",inst_type, line);
	}
}



char *strip(char *s)
{
	char s_new[MAX_LINE_LENGTH];
	
	int i = 0;
	for (char *s2 = s; *s2; s2++) 
	{ 
   		if (*s2 == '/' && *(s2+1) == '/')
   		{
   			break;
   		}
   		else if (!isspace(*s2))
   		{
   			s_new[i++] = *s2;
   		}
	}
	strcpy(s, s_new);
	return s;
}