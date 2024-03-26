#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

#define NUM_STUDENTS 4


sem_t read_sem, write_sem;

void *readFile(void *arg) {
    int student_id = *(int*)arg;
    sem_wait(&read_sem);
    printf("Student %d is reading the file.\n", student_id);
    
    printf("Student %d finished reading.\n", student_id);
    sem_post(&read_sem);
    return NULL;
}


void *writeFile(void *arg) {
    int student_id = *(int*)arg;
    sem_wait(&write_sem);
    printf("Student %d is updating the file.\n", student_id);
 
    printf("Student %d finished updating.\n", student_id);
    sem_post(&write_sem);
    return NULL;
}

int main() {
    pthread_t students[NUM_STUDENTS];
    int student_ids[NUM_STUDENTS];

   
    sem_init(&read_sem, 0, 1); 
    sem_init(&write_sem, 0, 1); 

    
    for (int i = 0; i < NUM_STUDENTS; i++) {
        student_ids[i] = i + 1;
        pthread_create(&students[i], NULL, readFile, &student_ids[i]);
    }

  
    pthread_t writer;
    int writer_id = NUM_STUDENTS + 1;
    pthread_create(&writer, NULL, writeFile, &writer_id);

    
    for (int i = 0; i < NUM_STUDENTS; i++) {
        pthread_join(students[i], NULL);
    }
    pthread_join(writer, NULL);

    
    sem_destroy(&read_sem);
    sem_destroy(&write_sem);

    return 0;
}

