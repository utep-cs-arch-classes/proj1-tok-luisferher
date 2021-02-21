#include <stdio.h>

void main(){
  //Define character c
  char c;
  //Ask user for an input and store value in c variable
  c = getchar();
  //While loop will run until c is the end-of-file signal
  while(c != '\n'){
    putchar(c);//Print the value of character c
    c = getchar();//Ask user for an input and store value in c variable
  }
}
