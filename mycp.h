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

#define BUFFERSIZE 128
