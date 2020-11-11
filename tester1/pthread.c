#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>


typedef struct test_struct {
  int kal;
  double ista;
} imp_struct;


void *print_message_function(void *ptr);
void *print_struct(void *ptr);


int main(){
  pthread_t thread1, thread2, thread3, thread4;
  char *message1="Thread 1";
  char *message2="Thread 2";
  imp_struct sim_struct;

  
  int iret1, iret2;
  /* Create independent thread ecah of will execute function */
  iret1 = pthread_create(&thread1, NULL, print_message_function, (void *)message1);
  iret2 = pthread_create(&thread2, NULL, print_message_function, (void *)message2);
  iret3 = pthread_create(&thread3, NULL, print_struct, (void *)sim_struct);
  pthread_join(thread1, NULL);
  pthread_join(thread2, NULL);

  printf("Thread 1 return: %d\n", iret1);
  printf("Thread 2 return: %d\n", iret2);
  return 0;

}

void * print_message_function(void*ptr){
  char *message;
  message = (char *)ptr;
  printf("%s \n", message);

}

void *print_struct(void *ptr){
  

}
