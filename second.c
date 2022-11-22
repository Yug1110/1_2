#include<stdio.h>
#include<unistd.h>
#include<time.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<sys/stat.h>

pid_t a,b,c;
int report;

void first_process(){
  clock_t timing;
  timing=clock();
  a=fork();
  if(a==-1){
    printf("Unable to create a child procee\n");
  }
  else if(a==0){
    execlp("make","make",NULL);
  }waitpid(a,&report,0);
  timing=clock()-timing;
  double ans=(double)timing;
  printf(“\033[0;31m”);
  printf("\n\nfirst_process time: ");
  for(int i=0;i<ans;i++){
    printf("*");
  }
  printf(" %lf\n\n\n",ans);
  printf(“\033[0m”);
  
}

void second_process(){
  clock_t timing;
  timing=clock();
  b=fork();
  if(b==-1){
    printf("Unable to create a child procee\n");
  }
  else if(b==0){
    execlp("make","make",NULL);
  }waitpid(b,&report,0);
  timing=clock()-timing;
  double ans=(double)timing;
  printf(“\033[0;31m”);
  printf("\n\nsecond_process time: ");
  for(int i=0;i<ans;i++){
    printf("*");
  }
  printf(" %lf\n\n\n",ans);
  printf(“\033[0m”)
}

void third_process(){
  clock_t timing;
  timing=clock();
  c=fork();
  if(c==-1){
    printf("Unable to create a child procee\n");
  }
  else if(c==0){
    execlp("make","make",NULL);
  }waitpid(c,&report,0);
  timing=clock()-timing;
  double ans=(double)timing;
  printf(“\033[0;31m”);
  printf("\n\nfirst_process time: ");
  for(int i=0;i<ans;i++){
    printf("*");
  }
  printf(" %lf\n\n\n",ans);
  printf(“\033[0m”)
}

void main(){
  first_process();
  second_process();
  third_process();
}
