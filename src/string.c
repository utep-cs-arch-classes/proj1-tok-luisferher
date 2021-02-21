#include <stdio.h>
#include "tokenizer.h"

int space_char(char c);
int non_space_char(char c);
char *word_start(char *str);
char *word_end(char *str);
int count_words(char *str);

int main(){
  char c;
  int i;
  c = getchar();
  i = non_space_char(c);
  printf("%1d\n", i);
}

int space_char(char c){
  if (c == ' ' || c == '\t'|| c == '\n'){
    return 1;
  }
  else
    return 0;
}
int non_space_char(char c){
  if(c == ' ' || c == '\t' || c == '\n'){
    return 0;
  }
  else
    return 1;
}
