#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <string.h>

#define KEY 13

int main (int argc, char* argv[]) {

  int semid;

  // Make sem and set val
  if (!strcmp(argv[1], "-c")) {
    if (!argv[2]) {
      printf("Wrong number of args mate\n");
    } else {
      semid = semget(KEY, 1, IPC_CREAT | IPC_EXCL | 0644);
      if (semid == -1) {
	printf("Semaphore already exists\n");
      } else {
	int temp;
	sscanf(argv[2], "%d", &temp); // Turn char into int
	semctl(semid, 0, SETVAL, temp);
	printf("Semaphore created: %d\n", semid);
	printf("Value set: %d\n", temp);
      }
    }
  }

  // Get val
  if (!strcmp(argv[1], "-v")) {
    semid = semget(KEY, 0, 0);
    printf("Semphore value: %d\n", semctl(semid, 0, GETVAL));
  }

  // Remove sem
  if (!strcmp(argv[1], "-r")) {
    semid = semget(KEY, 0, 0);
    printf("Semaphore removed: %d\n", semctl(semid, 0, IPC_RMID));
  }
  
}


