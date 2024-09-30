#include "createdb.h"
#include <stdio.h>
#include <string.h>
#include "print_commands.h"

int main()
{
  // Wilcom the user
  printf("Wilcom in mohabsql.\n");
  printf("Type 'help' to list available commands\n\n");

  // show user options (TODO)
  //...

  // get user command
  char command[1024];

  while(strcmp(command, "exit") != 0) {
    scanf("%s", command);

    // perform user command
    if(strcmp(command, "createdb") == 0)
    {
      char dbname[1024];
      printf("DB name: ");
      scanf("%s", dbname);
      createdb(dbname);
    } else if (strcmp(command, "help") == 0) {
      print_commands();
    }
  }

  printf("Bye.\n");

  return 0;
}
