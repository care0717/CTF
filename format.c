#include <stdio.h>

int main(int argc, char *argv[]){
  char str[100];
  fgets(str, 128, stdin);
  printf(str);
  return 0;
}
