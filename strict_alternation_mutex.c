#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
//Algo 1  
int x=0;
int turn=1;

void *criticalSection(){
	x++;
	}

void* Thread1(void* arg)
{
do{	
chouaib: 
	if (turn!=1 ){ goto chouaib;  } // if (flag[1]){ goto label;} == while (flag[1]);
criticalSection() ;
printf("thread 1 : %d \n",x);
turn=2;
}while(1);
}

void* Thread2(void* arg)
{
do{
csp:
if (turn!=2){
	goto csp;}
 criticalSection();
 printf("thread 2 :  %d \n",x);
 turn=1;
}while(x<10);
}

int main (void)	
{

/* Déclaration de variable de type thread */	
     pthread_t t1;
     pthread_t t2;

/* Création et lancement des threads 1 et 2 */
	pthread_create (&t1, NULL,Thread1, (void*)NULL);
	pthread_create (&t2, NULL, Thread2, (void*)NULL); 
	
/* Attendre la fin des threads pour terminer le  main */
     pthread_join (t1, NULL);
     pthread_join (t2, NULL); 
	
	printf(" x= %d",x);
/* Fin Normale du programme */
     return 0;
}
