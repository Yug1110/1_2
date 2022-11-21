#include<stdio.h>
#include<unistd.h>
#include<time.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<sys/stat.h>

pid_t pid1,pid2,pid3;
int status;

void PROCESS_A(){
pid1=fork();
if(pid1==-1){
printf("error in creating child process");
}
else if(pid1==0){
execl("make","make",NULL);
}
waitpid(pid1,&status,0);
}

int main(){
PROCESS_A();
return 0;
}
