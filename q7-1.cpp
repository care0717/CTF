#include <stdio.h>    
#include <string.h>	
int main(){
  const char *s =
      "     	    "
      "0123456789"
      "     "

      "		   "
      "			         							  				 			 "
      "ABCDEFGHIJ";
  printf("%c\n", strlen(s));
  int i = 021647522;
  i = 4673356;
  i -= 200;

  printf("%x\n", &i);
  printf("%d\n", &i);
  printf("%s", &i);
}
