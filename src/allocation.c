#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "string.c"
char *copy_str(char *inStr, short len);
void print_tokens(char **toks);
void free_tokens(char **toks);
char **tokenize(char *str);
int main(){
  //Testing copy_str
  // char arr[] = "Hello";
  // char *ptr;
  // ptr = arr;
  // char *p = copy_str(ptr,3);
  //while(*p != 0){
  //printf("%c\n",*p);
  // p++;
  //}
  
}
/* Returns a freshly allocated new zero-terminated string
   containing <len> chars from <inStr> */
char *copy_str(char *inStr, short len){
  char *p = (char *) malloc (len+1);
  short i = 0;
  while(i != len){
    *(p+i) = *(inStr+i);
    i++;
  }
  *(p+len) = '\0';
  return p;
}
/*Returns a freshly allocated zero-terminated vector of freshly allocated space-separated tokens from zero-terminated str.*/
char **tokenize(char *str){
  char *ptr;
  ptr = str;
  int n = count_words(str);
  char **p = (char **) malloc (sizeof(char *)*n+1);
  }
}
void print_tokens(char **toks){
  
}























