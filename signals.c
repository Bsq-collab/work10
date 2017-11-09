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
    char message[30]="you've been SIGINTed heh\n";
    int filestuff=open("filestuff.txt",O_APPEND|O_WRONLY);
    write(filestuff,message,sizeof(message));
    close(filestuff);
    exit(1);
  }
  if(signo==SIGUSR1){
    printf("PRINTING PARENT PID: %d\n",getppid());
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
