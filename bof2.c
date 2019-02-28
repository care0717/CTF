#include <stdio.h>
#include <string.h>
char buffer[32];
int main(int argc, char *argv[]){
  char local[32];
  
  printf("buf address\t= %x\n", (int)buffer);
  fgets(local, 128, stdin);
  
  strcpy(buffer, local);
  return 0;
}

