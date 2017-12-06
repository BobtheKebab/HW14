#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <string.h>

int main (int argc, char* argv[]) {

  int semid;

  // Make sem and set val
  if (!strcmp(argv[1], "-c")) {
    semid = semget(13, 1, IPC_CREAT);
    semctl(semid, 1, SETVAL, argv[2]);
    printf("nutt\n");
  }

  // Get val
  if (!strcmp(argv[1], "-v")) {
    
  }

  if (!strcmp(argv[1], "-r")) {
    
  }
  
}


