#include <stdio.h>
#include <stdlib.h>
#include "createdb.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

// Get were to store data
char* get_storage_path() {
  FILE* file = fopen("./storage.txt", "r");
  if(file == NULL) {
    perror("Error reading storage.txt");
    return NULL;
  }

  char* storage_path = malloc(sizeof(char) * 1024);

  // reads text until newline is encountered
  fscanf(file, "%[^\n]", storage_path);
  printf("Data from the file:\n%s", storage_path);
  fclose(file);

  return storage_path;
}


void createdb(char* dbname)
{
  // Get storage path
  char* storage_path = get_storage_path();
  if(storage_path == NULL) {
    perror("Could not create db");
    return;
  }

  // Begin
  printf("Creating virual db\npeep poop peep pap...\n");

  // Create db directory
  createDir(storage_path, dbname);
}

// create a dir in path
void createDir(char* path, char* name)
{
  strcat(path, "/");
  if(mkdir(strcat(path, name), 0777) != 0) {
    printf("When executing: mkdir(\"%s\")\n", path);
    perror("mkdir");
    exit(1);
  };
}
