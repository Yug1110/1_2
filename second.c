#include<stdio.h>
#include<unistd.h>
#include<time.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<sys/stat.h>

pid_t a,b,c;
int report;

double first_process(){
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
  printf("\n\nfirst_process time:");
  for(int i=0;i<ans;i++){
    printf("*");
  }
  printf(" %f\n\n",ans);
  return ans;
}

double second_process(){
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
  printf("\n\nsecond_process time:");
  for(int i=0;i<ans;i++){
    printf("*");
  }
  printf(" %f\n\n",ans);
  return ans;
}

double third_process(){
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
  printf("\n\nthird_process time:");
  for(int i=0;i<ans;i++){
    printf("*");
  }
  printf(" %f\n\n",ans);
  return ans;
}

void main(){
  double ans=first_process();
  printf("\n\nfirst_process time:");
  for(int i=0;i<ans;i++){
    printf("*");
  }
  printf(" %f\n",ans);

  ans=second_process();
  printf("second_process time:");
  for(int i=0;i<ans;i++){
    printf("*");
  }
  printf(" %f\n\n",ans);

  ans=third_process();
  printf("third_process time:");
  for(int i=0;i<ans;i++){
    printf("*");
  }
  printf(" %f\n",ans);

}
