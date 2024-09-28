#include <stdio.h>
#include <stdlib.h>
#include "createdb.h"

char* get_storage_path() {
  // check were should the db store data
  FILE* file = fopen("./storage.txt", "r");
  if(file == NULL) {
    perror("Error reading storage.txt");
    return NULL;
  }

  char* storage_path = malloc(sizeof(char) * 1024);

  if(fgets(storage_path, sizeof(storage_path), file) != NULL)
  {
    printf("%s\n", storage_path);
    return storage_path;
  }

  perror("Could not read the storage.txt file.");
  return NULL;
}

void createdb(char* dbname)
{
  char* storage_path = get_storage_path();
  if(storage_path == NULL) {
    perror("Could not create db");
    return;
  }

  printf("%s\n", storage_path);

  printf("Creating virual db\npeep poop peep pap...\n");
}

int main()
{
  createdb("he");
  return 1;
}
