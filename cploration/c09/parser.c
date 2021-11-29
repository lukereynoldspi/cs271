#include "parser.h"
#include "error.h"
#include "symtable.h"
bool is_Atype(const char *line)
{
	if (line[0] != '@')

		return false;
	else
		return true;
}

bool is_label(const char *line)
{
	if (line[0] == '(' && line[strlen(line)-1] == ')')
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

char *extract_label(const char *line, char* label)
{
	strncpy(label, line + 1, strlen(line) - 2);
	return label;
}

void parse(FILE * file)
{
	char line[MAX_LINE_LENGTH] = {0};
	unsigned int line_num = 0;
	unsigned int instr_num = 0;
	instruction instr;
	add_predefined_symbols();
	while (fgets(line, sizeof(line), file))
	{
		line_num = line_num + 1;
		if(instr_num > MAX_INSTRUCTIONS)
		{
			exit_program(EXIT_TOO_MANY_INSTRUCTIONS, MAX_INSTRUCTIONS + 1);
		}
		strip(line);

		if(!*line)
			continue;

		char inst_type = '\0';

		if(is_Atype(line))
		{
			inst_type = 'A';
			if (!parse_A_instruction(line, &instr.instr.a)){
    			exit_program(EXIT_INVALID_A_INSTR, line_num, line);
 				}
 			instr.itype = INST_A;
		}

		else if(is_label(line))
		{
			inst_type = 'L';
			char label[strlen(line)];
			extract_label(line, label);
			if (isalpha(line[0]))
			{
				exit_program(EXIT_INVALID_LABEL, line_num, line);
			}
			else if(symtable_find(line) != NULL)
			{
				exit_program(EXIT_SYMBOL_ALREADY_EXISTS, line_num, line);
			}
			symtable_insert(line, instr_num);
       		continue;
		}

		else if(is_Ctype(line))
		{
			inst_type = 'C';
		}
		printf("%c  %s\n", inst_type, line);
		instr_num = instr_num + 1;
	}
}



char *strip(char *s)
{
	char s_new[MAX_LINE_LENGTH] = {0};
	
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

void add_predefined_symbols() {
	for (int i = 0; i < NUM_PREDEFINED_SYMBOLS; i++) {
		predefined_symbol sym= predefined_symbols[i];
		symtable_insert(sym.name, sym.addr);
	}
}

bool parse_A_instruction(const char *line, a_instruction *instr){
	char *s = (char*) malloc(strlen(line));
	strcpy(s, line +1);
	char *s_end = NULL;
	long result = strtol(s, &s_end, 10);
	if (s == s_end){
		instr->label = (char*) malloc(strlen(line));
		strcpy(instr->label, s);
		instr->is_addr = false;
	}
	else if (*s_end != 0){
		return false;
	}
	else{
		instr->address = result;
		instr->is_addr = true;
	}
	return true;
}