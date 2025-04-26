#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdbool.h>
#include <unistd.h>

//Algo 3
int x=0;
bool flag[2];

void* criticalSection(){
	x++;
	}

void* Thread1(void* arg)
{
do{
flag[0]=true; 
label:
if (flag[1]){
    goto label;}
criticalSection() ;
printf("thread 1 : %d \n",x);

flag[0]=false;
}while(1);
}

void* Thread2(void* arg)
{
do{
flag[1]=true;
label:
if (flag[0]){
	goto label;}

 criticalSection();
 printf("thread 2 : %d \n",x);

 flag[1]=false;
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
	
	printf("  x= %d",x);
/* Fin Normale du programme */
     return 0;
     }
