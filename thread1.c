#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void* thread_function(void* arg) {
  int thread_id = *(int*)arg;
  printf("Thread %d is starting\n", thread_id);

  // Do some work
  sleep(1);
  
  printf("Thread %d is finishing\n", thread_id);
  pthread_exit(NULL);
}

int main() {
  pthread_t threads[5];
  int thread_args[5];
  
  for(int i=0; i<5; i++) {
    thread_args[i] = i; 
    pthread_create(&threads[i], NULL, thread_function, &thread_args[i]);
  }

  printf("Main thread waiting for threads to finish...\n");

  for(int i=0; i<5; i++) {
    pthread_join(threads[i], NULL);
  }

  printf("All threads finished, main thread terminating\n");
  
  pthread_exit(NULL);
}
