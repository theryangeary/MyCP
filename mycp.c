/*
  mycp - copy one file's contents to another
  Ryan Geary - September 5, 2018
  CISC361 Fall 2018
  Programming Assignment 1b
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

#include "mycp.h"

#define BUFFERSIZE 128

// printUsage - print an explanatory error message to help users
void printUsage() {
  printf("Usage:\nmycp source_file destination_file\n");
}

int main(int argc, char* argv[]) {
  char buffer[BUFFERSIZE];
  char source_file_name[128];
  char dest_file_name[128];
  int source_file;
  int dest_file;

  if(argc == 3) {
    //get file names
    strcpy(source_file_name, argv[1]);
    strcpy(dest_file_name, argv[2]);

    source_file = open(source_file_name, O_RDONLY);
    if (source_file == -1) {
      printf("Source file does not exist\n");
      return 0;
    }
    
    
    dest_file = open(dest_file_name, O_RDWR);
    if (dest_file != -1) {
      printf("File already exists. Overwrite? [y/N]: ");
      int check = fgetc(stdin);
      if (!(check == (int) 'Y' || check == (int) 'y')) {
        return 0;
      }
      else {
        close(dest_file);
        remove(dest_file_name);
      }
    }
    struct stat statbuf;
    stat(source_file_name, &statbuf);
    
    dest_file = open(dest_file_name, O_WRONLY | O_CREAT, statbuf.st_mode);

    int readResult, writeResult;
    do  {
      readResult = read(source_file, buffer, BUFFERSIZE);
      writeResult = write(dest_file, buffer, readResult);
    } while (readResult != 0 && writeResult != 0);

    close(source_file);
    close(dest_file);
  }
  else {
    printUsage();
  }


  return 0;
}

