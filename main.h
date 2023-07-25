#ifndef MAIN_H_
#define MAIN_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <stdbool.h>


/* Functions declaration */
void *_realc(void *ptr, size_t old_size, size_t new_size);
void *_memcpy(void *adress, const void *srcpy, size_t n);
size_t malloc_size(void *ptr);
char *copy_string_strcpy(char *address, const char *src);
int compare_string_strcmp(const char *s1, const char *s2);
size_t Length_string_strlen(const char *s);
char *concat_string_strcat(char *address, const char *src);
char *_environ_get(const char *env_var);
char *comand_get(char *command);
char **str_split(char *buf, const char *del);
void comnd_exec(char **args, char **env);
void tok_free(char **tokens);

#endif
