#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

int space_char(char c);
int non_space_char(char c);
char *word_start(char *str);
char *word_end(char *str);
int count_words(char *str);
char *copy_str(char *inStr, short len);
void print_tokens(char **toks);
void free_tokens(char **toks);
char **tokenize(char *str);


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
  //int n;
  //char arr[100] = {'h','e','y',' ','h','i',' ','b','y','e','\0'};
// char arr[5] = {' ',' ','a','b','\0'};
// n = count_words(arr);
// printf("Total Words in the String\n");
// printf("%d\n", n);
//}
//Testing copy_str
  // char arr[] = "Hello";
  // char *ptr;
  // ptr = arr;
  // char *p = copy_str(ptr,3);
  //while(*p != 0){
  //printf("%c\n",*p);
  // p++;
  //---------------------------------
  //Testing tokenizer
  // char arr[] = "Hello World yay!\0";
  // char *ptr;
  // ptr = arr;
  // char **doble = tokenize(ptr);
  //printf("%s\n", *(doble+1));
  // print_tokens(doble);
  //free_tokens(doble);
  //print_tokens(doble);
  int i;
  char t;
  char end;
  while(end != 0x0a){
    printf("Enter words\n");
    t = getchar();
    char *input = (char *)malloc(100);
    for(i=0; (t = getchar())!= 0x0a && i < 99; i++){
      *(input+i) = t;
    }
    *(input+99)= '\0';
    char **doble = tokenize(input);
    printf("TOKENS-----\n");
    print_tokens(doble);
    printf("If you want to exit press enter else enter any key\n");
    end = getchar();
  }
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
  char *start;
  char *end;
  int n = count_words(str);
  char **parr = (char **) malloc (sizeof(char *)*(n+1));
  int i = 0;
  while(i != n){
    short length;
    start = word_start(ptr);
    end = word_end(start);
    length = end - start;
    //printf("%d\n",length);
    *(parr+i) = copy_str(start,length);
    ptr = end;
    i++;
  }
  *(parr+n) = '\0';
  return parr;
}
void print_tokens(char **toks){
  int i = 0;
  while(toks[i] != 0){
    printf("%s\n", *(toks+i));
    i++;
  }
}
void free_tokens(char **toks){
  int i = 0;
  while(toks[i] != 0){
    free(toks[i]);
    i++;
  }
  free(toks);
}
