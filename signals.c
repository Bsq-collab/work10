#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<errno.h>
#include<stdlib.h>
#include <dirent.h>
#include <signal.h>

const char *FILE_PATH = "work10.txt";
  
static void sighandler(int signo){
  if(signo==SIGINT){
    ""
  }
}
int main(){
  while(1){
    printf("PID: %d\n", getpid());
    sleep(1)
  }
}
