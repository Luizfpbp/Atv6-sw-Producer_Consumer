#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <semaphore.h>

void *produzir (void *idt);
void *consumir (void *idt);

int b_size;

int prod_id;
int *thr_produtos;
sem_t mutex;

int *buffer;
int b_index;

int P, C, N, B;

int main (void) {

    scanf("%d %d %d %d", &P, &C, &N, &b_size);

    b_index = 0;

    pthread_t thr_p[P];
    pthread_t thr_c[C];

    int thr_id [P];
    for (int c=0; c<P; c++) {
        thr_id[c] = c;
    }

    thr_produtos = (int*) malloc(P*sizeof(int));
    buffer = (int*) malloc((b_size)*sizeof(int));

    sem_init (&mutex, 0, 1);

    for (int c=0; c < P; c++) {
        pthread_create (&thr_p[c], NULL, produzir, &thr_id[c]);
    }

    for (int c=0; c < C; c++) {
        pthread_create (&thr_c[c], NULL, consumir, &thr_id[c]);
    }

    for (int c=0; c < P; c++) {
        pthread_join (thr_p[c], NULL);
    }

    for (int c=0; c < P; c++) {
        pthread_join (thr_c[c], NULL);
    }

    return 0;
}

void *produzir(void *idt) {

    while (1) {
    
        int *id = idt;
        int x = thr_produtos[*id];
        int final;

        sleep(1);

        sem_wait(&mutex);
        if (buffer[b_size-1] == 0) {

            final = (2*x)+1;
            buffer[b_index] = final;

            if (x+1 < N) {
                thr_produtos[*id] = x+1;
            } else {
                thr_produtos[*id] = 0;
            }

            printf("O produtor %d produziu %d na posição %d\n", *id, final, b_index);
            b_index++;
        } 

        if (b_index+1 == b_size) {
            b_index = 0;
        }

        sem_post(&mutex);

    }

}

void *consumir (void *idt) {
    
    int *id = idt;

    while (1) {

        sem_wait(&mutex);
        for (int c=0; c<b_size; c++) {
            if (buffer[c] != 0) {
                printf("Consumidor %d consumiu %d na posição %d\n", *id, buffer[c], c);
                buffer[c] = 0;
                break;

            }

        }
        sem_post(&mutex);

        sleep(1);

    }

}
