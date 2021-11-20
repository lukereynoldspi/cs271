//Exercise 1
#ifndef __SYMTABLE_H__
#define __SYMTABLE_H__
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
struct Symbol *symtable_find(char * key);
void symtable_insert(char* key, hack_addr addr);
void symtable_display_table();

#endif