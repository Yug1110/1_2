#include<stdio.h>
#include<unistd.h>
#include<time.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sched.h>

pid_t a,a1,a2,a3,b,b1,b2,b3,c,c1,c2,c3;
int report;
struct sched_param param;

double first_process_default(){
  clock_t timing;
  timing=clock();
  a=fork();
  if(a==-1){
    printf("Unable to create a child procee\n");
  }
  else if(a==0){
    sched_setscheduler(a, SCHED_OTHER,&param);
    execlp("make","make",NULL);
  }waitpid(a,&report,0);
  timing=clock()-timing;
  double ans=(double)timing;
  return ans;
}

double first_process_p1(){
  clock_t timing;
  timing=clock();
  a1=fork();
  if(a1==-1){
    printf("Unable to create a child procee\n");
  }
  else if(a1==0){
    param.sched_priority=1;
    sched_setscheduler(a1, SCHED_OTHER,&param);
    execlp("make","make",NULL);
  }waitpid(a1,&report,0);
  timing=clock()-timing;
  double ans=(double)timing;
  return ans;
}

double first_process_p2(){
  clock_t timing;
  timing=clock();
  a2=fork();
  if(a2==-1){
    printf("Unable to create a child procee\n");
  }
  else if(a2==0){
    param.sched_priority=2;
    sched_setscheduler(a2, SCHED_OTHER,&param);
    execlp("make","make",NULL);
  }waitpid(a2,&report,0);
  timing=clock()-timing;
  double ans=(double)timing;
  return ans;
}

double first_process_p3(){
  clock_t timing;
  timing=clock();
  a3=fork();
  if(a3==-1){
    printf("Unable to create a child procee\n");
  }
  else if(a3==0){
    param.sched_priority=3;
    sched_setscheduler(a3, SCHED_OTHER,&param);
    execlp("make","make",NULL);
  }waitpid(a3,&report,0);
  timing=clock()-timing;
  double ans=(double)timing;
  return ans;
}

double second_process_default(){
  clock_t timing;
  timing=clock();
  b=fork();
  if(b==-1){
    printf("Unable to create a child procee\n");
  }
  else if(b==0){
    sched_setscheduler(b, SCHED_RR,&param);
    execlp("make","make",NULL);
  }waitpid(b,&report,0);
  timing=clock()-timing;
  double ans=(double)timing;
  return ans;
}

double second_process_p1(){
  clock_t timing;
  timing=clock();
  b1=fork();
  if(b1==-1){
    printf("Unable to create a child procee\n");
  }
  else if(b1==0){
    param.sched_priority=1;
    sched_setscheduler(b1, SCHED_RR,&param);
    execlp("make","make",NULL);
  }waitpid(b1,&report,0);
  timing=clock()-timing;
  double ans=(double)timing;
  return ans;
}

double second_process_p2(){
  clock_t timing;
  timing=clock();
  b2=fork();
  if(b2==-1){
    printf("Unable to create a child procee\n");
  }
  else if(b2==0){
    param.sched_priority=2;
    sched_setscheduler(b2, SCHED_RR,&param);
    execlp("make","make",NULL);
  }waitpid(b2,&report,0);
  timing=clock()-timing;
  double ans=(double)timing;
  return ans;
}

double second_process_p3(){
  clock_t timing;
  timing=clock();
  b3=fork();
  if(b3==-1){
    printf("Unable to create a child procee\n");
  }
  else if(b3==0){
    param.sched_priority=3;
    sched_setscheduler(b3, SCHED_RR,&param);
    execlp("make","make",NULL);
  }waitpid(b3,&report,0);
  timing=clock()-timing;
  double ans=(double)timing;
  return ans;
}


double third_process_default(){
  clock_t timing;
  timing=clock();
  c=fork();
  if(c==-1){
    printf("Unable to create a child procee\n");
  }
  else if(c==0){
    sched_setscheduler(c, SCHED_FIFO,&param);
    execlp("make","make",NULL);
  }waitpid(c,&report,0);
  timing=clock()-timing;
  double ans=(double)timing;
  return ans;
}

double third_process_p1(){
  clock_t timing;
  timing=clock();
  c1=fork();
  if(c1==-1){
    printf("Unable to create a child procee\n");
  }
  else if(c1==0){
    param.sched_priority=1;
    sched_setscheduler(c1, SCHED_FIFO,&param);
    execlp("make","make",NULL);
  }waitpid(c1,&report,0);
  timing=clock()-timing;
  double ans=(double)timing;
  return ans;
}

double third_process_p2(){
  clock_t timing;
  timing=clock();
  c2=fork();
  if(c2==-1){
    printf("Unable to create a child procee\n");
  }
  else if(c2==0){
    param.sched_priority=2;
    sched_setscheduler(c2, SCHED_FIFO,&param);
    execlp("make","make",NULL);
  }waitpid(c2,&report,0);
  timing=clock()-timing;
  double ans=(double)timing;
  return ans;
}

double third_process_p3(){
  clock_t timing;
  timing=clock();
  c3=fork();
  if(c3==-1){
    printf("Unable to create a child procee\n");
  }
  else if(c3==0){
    param.sched_priority=3;
    sched_setscheduler(c3, SCHED_FIFO,&param);
    execlp("make","make",NULL);
  }waitpid(c3,&report,0);
  timing=clock()-timing;
  double ans=(double)timing;
  return ans;
}



void main(){
  double ans1=first_process_default();
  double ans11=first_process_p1();
  double ans12=first_process_p2();
  double ans13=first_process_p3();
  double ans2=second_process_default();
  double ans21=second_process_p1();
  double ans22=second_process_p2();
  double ans23=second_process_p3();
  double ans3=third_process_default();
  double ans31=third_process_p1();
  double ans32=third_process_p2();
  double ans33=third_process_p3();
  
  printf("\n\nfirst_process default time:");
  for(int i=0;i<ans1;i++){
    printf("*");
  }
  printf(" %f\n",ans1);

  printf("first_process priority1 time:");
  for(int i=0;i<ans11;i++){
    printf("*");
  }
  printf(" %f\n",ans11);

  printf("first_process priority2 time:");
  for(int i=0;i<ans12;i++){
    printf("*");
  }
  printf(" %f\n",ans12);

  printf("first_process priority3 time:");
  for(int i=0;i<ans13;i++){
    printf("*");
  }
  printf(" %f\n",ans13);

  printf("second_process default time:");
  for(int i=0;i<ans2;i++){
    printf("*");
  }
  printf(" %f\n",ans2);

  printf("second_process priority1 time:");
  for(int i=0;i<ans21;i++){
    printf("*");
  }
  printf(" %f\n",ans21);

  printf("second_process priority2 time:");
  for(int i=0;i<ans22;i++){
    printf("*");
  }
  printf(" %f\n",ans22);

  printf("second_process priority3 time:");
  for(int i=0;i<ans23;i++){
    printf("*");
  }
  printf(" %f\n",ans23);
  
  printf("third_process default time:");
  for(int i=0;i<ans3;i++){
    printf("*");
  }
  printf(" %f\n",ans3);

  printf("third_process priority1 time:");
  for(int i=0;i<ans31;i++){
    printf("*");
  }
  printf(" %f\n",ans31);

  printf("third_process priority2 time:");
  for(int i=0;i<ans32;i++){
    printf("*");
  }
  printf(" %f\n",ans32);

  printf("third_process priority3 time:");
  for(int i=0;i<ans33;i++){
    printf("*");
  }
  printf(" %f\n",ans33);
}
