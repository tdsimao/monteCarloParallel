#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void *rotinaSorteio(void *threadid);

int areaCirc[1000], sorteiosPorThread, sorteiosRestantes;

int main (int argc, char *argv[]){
    int numThreads, numSorteios, retorno;
    long i;
    float pi,  ac = 0, aq =0;
    printf("Teste\n");
    numThreads = atoi(argv[1]);
    numSorteios = atoi(argv[2]);   
    pthread_t threads[numThreads];
    sorteiosPorThread = numSorteios / numThreads;
    sorteiosRestantes = numSorteios - sorteiosPorThread * numThreads;
    printf("Numero de threads = %d \nNumero de sorteios = %d \nSorteios por thread = %d \nSorteios restante = %d\n", numThreads,numSorteios,sorteiosPorThread,sorteiosRestantes);

    for(i=0; i<numThreads; i++){
        printf("Criar Thread %ld\n", i);
        pthread_create(&threads[i], NULL, rotinaSorteio, (void *)i);
        
    }

    for(i=0; i<numThreads; i++){
        pthread_join(threads[i], NULL);
    }
    
    for(i=0; i<numThreads; i++){
        ac += areaCirc[i];
    }
    printf("ac = %f\nnumSorteios = %d\n",ac,numSorteios);
    pi = (ac / numSorteios)*4; 
    
    printf("Pi = %lf!\n",pi);
    return 0;
}

void *rotinaSorteio(void *threadid){
    long n, i, id;
    float x,y;
    
    id = (long)threadid;
    if (id < sorteiosRestantes) {
        n = sorteiosPorThread + 1;
    }
    else {
        n = sorteiosPorThread;
            
    }
    srand48(time(NULL));
    printf("Thead #%ld. Sortear %ld numeros!\n",id, n);
    areaCirc[id] = 0;
    for (i=0; i<n; i++ ){
        x = drand48();
        y = drand48();
        if ((x*x+y*y) <= 1) {
            //printf("T #%ld -- N %ld -- X %f-- Y %f -- Circulo\n",id, i, x,y);
            areaCirc[id] += 1;
        }
        else{
            //printf("T #%ld -- N %ld -- X %f-- Y %f -- Quadrado\n",id, i, x,y);
        }
   }

}


// compilar no terminal "gcc -lptrhead motecarlo.c -o rotinaSinal"
// executar: "./rotinaSonal"
// enquanto estiver rodando abrir uma nova janela do terminal
// encontrar o pid do processo com o comando "ps -aux"
// enviar um sinal para o processo com o comando "kill -USR1 pid"
// onde pid é o id do processo
