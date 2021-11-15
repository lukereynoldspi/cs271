//Exercise 1

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define SYMBOL_TABLE_SIZE 200

typedef int16_t hack_addr;

//Exercise 2

typedef struct Symbol{
	char *name;
	hack_addr addr;
} Symbol;

int hash(char *str);
struct Symbol *find(char * key);
void insert(char* key, hack_addr addr);
void display_table();