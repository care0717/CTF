#include <stdio.h>

int main(int argc, char *argv[]){
  int zero=0;
  char buffer[10];
  
  printf("buf address\t= %x\n", (int)buffer);
  printf("zero address\t= %x\n", (int)&zero);
  fgets(buffer, 64, stdin);
  printf("zero=%d\n", zero);
  if (zero==0x12345678){
    printf("cong!");
  }
  return 0;
}

