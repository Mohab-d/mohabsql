#include "createdb.h"
#include <stdio.h>
#include <string.h>

int main()
{
  // Wilcom the user
  printf("Wilcom in mohabsql.\n");

  // show user options (TODO)
  //...

  // get user command
  char command[1024];
  scanf("%s", command);

  // perform user command
  if(strcmp(command, "createdb") == 0)
  {
    char dbname[1024];
    printf("DB name: ");
    scanf("%s", dbname);
    createdb(dbname);
  }

  printf("Bye.\n");

  return 0;
}
