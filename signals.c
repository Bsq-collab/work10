#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<errno.h>
#include<stdlib.h>
#include <dirent.h>
#include <signal.h>

static void sighandler(int signo){
  if(signo==SIGINT){
    char message[20]="byebyebyebye";
    int filestuff=open("filestuff.txt",O_APPEND);
    write(filestuff,message,sizeof(message));
    close(filestuff);
    exit(0);
  }
  if(signo==SIGUSR1){
    printf("PID: %d\n",getppid());
  }
}

int main(){
  signal(SIGINT,sighandler);
  signal(SIGUSR1,sighandler);
  
  while(1){
    printf("PID: %d\n", getpid());
    sleep(1);
  }
}
