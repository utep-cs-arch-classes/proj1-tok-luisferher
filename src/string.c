#include <stdio.h>
#include "tokenizer.h"

int space_char(char c);
int non_space_char(char c);
char *word_start(char *str);
char *word_end(char *str);
int count_words(char *str);

int main(){
  //Testing space and non space functions
  // char c;
  // int i;
  // c = getchar();
  //  i = non_space_char(c);
  // printf("%1d\n", i);
  //------------------------------
  //Testing word start
  //int n;
  // char arr[10] = {'h','e','l','l','o',' ','w','o','\0'};
  // char *p = word_end(arr);
  // printf("%p\n", p);
  //printf("%c\n", *p);
  //---------------------------------
  //Testing count words
  int n;
  //char arr[100] = {'h','e','y',' ','h','i',' ','b','y','e','\0'};
  char arr[5] = {' ',' ','a','b','\0'};
   n = count_words(arr);
   printf("Total Words in the String\n");
   printf("%d\n", n);
}
/* Return true (non-zero)if c is a whitespacecharacter
(' ', '\t', or '\n').
Zero terminators are not printable (therefore false)*/
int space_char(char c){
  if (c == ' ' || c == '\t'|| c == '\n'){
    return 1;
  }
  else
    return 0;
}
/* Return true (non-zero) if c is a non-whitespace 
character (not space, tab, or newline).
   Zero terminators are not printable (therefore false)*/
int non_space_char(char c){
  if(c == ' ' || c == '\t' || c == '\n' || c == '\0'){
    return 0;
  }
  else
    return 1;
}
/* Returns a pointer to the first character of the next
space-separated word in zero-terminated str. Return a zero pointer if
str does not contain any words.
str is assumed to be pointing to a space character*/
char *word_start(char *str){
  char c;
  char *ptr;
  int n;
  ptr = str;
  while(*ptr!='\0'){
    c = *ptr;
    n = non_space_char(c);
    if(n == 1){ //Check if char is a non-space
      return ptr;
    }
    else
      ptr++;
  }
  return 0;
}
/* Returns a pointer terminator to the first space character or string-terminator
following str in a zero terminated string.
str is assumed to be pointing to a non-space character*/ 
char *word_end(char *str){
  char c;
  char *ptr;
  int n;
  ptr = str;
  while(*ptr!='\0'){
    c = *ptr;
    n = space_char(c);
    if(n == 1){//Check if char is a space char
      return ptr;
    }
    else
      ptr++;
  }
  return ptr;
}
/* Counts the number of space separated words in the string argument. */
int count_words(char *str){
  int counter = 0;
  char *ptr;
  char *st;
  char *end;
  ptr = str;
  while(*ptr!='\0'){
    st = word_start(ptr);
    if(st == 0){//Check if string is empty
      return counter;
    }
    end = word_end(st);
    if(*end == '\0'){//Check end of string
      counter++;
      return counter;
    }
    counter++;
    ptr = end;
  }
}
    
