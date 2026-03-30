
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

sem_t mutex, wrt, readTry;
int read_count = 0;

void* reader(void* arg) {
    int id = *(int*)arg;

    sem_wait(&readTry);
    sem_wait(&mutex);

    read_count++;
    if(read_count == 1)
        sem_wait(&wrt);

    sem_post(&mutex);
    sem_post(&readTry);

    printf("Reader %d is reading\n", id);

    sem_wait(&mutex);
    read_count--;
    if(read_count == 0)
        sem_post(&wrt);
    sem_post(&mutex);
}

void* writer(void* arg) {
    int id = *(int*)arg;

    sem_wait(&readTry);
    sem_wait(&wrt);

    printf("Writer %d is writing\n", id);

    sem_post(&wrt);
    sem_post(&readTry);
}

int main() {
    int nr, nw;
    pthread_t r[10], w[10];
    int id[10];

    printf("Enter number of readers: ");
    scanf("%d", &nr);

    printf("Enter number of writers: ");
    scanf("%d", &nw);

    sem_init(&mutex, 0, 1);
    sem_init(&wrt, 0, 1);
    sem_init(&readTry, 0, 1);

    for(int i=0;i<nr;i++) {
        id[i] = i+1;
        pthread_create(&r[i], NULL, reader, &id[i]);
    }

    for(int i=0;i<nw;i++) {
        id[i] = i+1;
        pthread_create(&w[i], NULL, writer, &id[i]);
    }

    for(int i=0;i<nr;i++)
        pthread_join(r[i], NULL);

    for(int i=0;i<nw;i++)
        pthread_join(w[i], NULL);

    return 0;
}


