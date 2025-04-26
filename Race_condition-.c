#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

// Algo 0 - Race condition


int VAL = 0; //chouaib


void* function(void* args)
{
	do{
		sleep(1);
		VAL ++ ;
                printf("=> %s : %d \n",args,VAL);
        
       }while(1);

	pthread_exit(NULL);
}


int main (void)
{

/* Déclaration de variable de type thread */
     pthread_t thread1;
     pthread_t thread2;

/* Création et lancement des threads 1 et 2 */
	pthread_create (&thread1, NULL,function, "Thread 1");
	pthread_create (&thread2, NULL,function, "Thread 2");
/* Attendre la fin des threads pour terminer le  main */
     pthread_join (thread1, NULL);
     pthread_join (thread2, NULL);

/* Fin Normale du programme */
     return 0;
}
