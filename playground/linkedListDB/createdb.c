#include <stdio.h>
#include <stdlib.h>
#include "createdb.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

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
  fclose(file);

  return storage_path;
}


void createdb(char* dbname)
{
  clock_t start_time, end_time;

  start_time = clock();

  // Get storage path
  char* storage_path = get_storage_path();
  if(storage_path == NULL) {
    perror("Could not create db");
    return;
  }

  // Begin
  printf("Creating db...\n");

  // Create db directory
  char *dbpath = createDir(storage_path, dbname);

  end_time = clock();

  double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

  if(dbpath != NULL) {
    printf("Database created at %s\n", dbpath);
    printf("Executed in %.3f seconds.\n", elapsed_time);
  } else {
    perror("createdb");
  }
}

// create a dir in path
char* createDir(char* path, char* name)
{
  strcat(path, "/");
  strcat(path, name);
  if(mkdir(path, 0777) != 0) {
    return NULL;
  };

  return path;
}
