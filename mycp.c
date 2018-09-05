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

#include "mycp.h"

// printUsage - print an explanatory error message to help users
void printUsage() {
  printf( "\nUsage:\nmycp source_file destination_file\n");
}

int main(int argc, char* argv[]) {
  char source_file_name[128];
  char dest_file_name[128];
  FILE source_file;
  FILE dest_file;

  if(argc == 3) {
    //get file names
    strcpy(source_file_name, argv[1]);
    strcpy(dest_file_name, argv[2]);

    
  }
  else {
    printUsage();
  }


  return 0;
}
