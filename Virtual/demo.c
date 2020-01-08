#include<stdio.h>
#include<string.h>

int main()
{
  char source[] = "World";   
  char *destination = "Hello ";   

  printf("Origina String: %s\n", destination);
 int i = strlen(destination) - 1;
 printf("%d", i);
  strncpy (&destination[2], source, 1); 
  //destination[i+1] = '\0';
  printf("Modified String: %s\n", 1);
  printf("HIO");
  return 0;
}