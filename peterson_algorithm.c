#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <stdbool.h>
//Algo 4
int x=0;
bool flag[2];

void* criticalSection(){
	x++;
	}

void* Thread1(void* arg)
{
do{
flag[0]=true;

while(flag[1]){
	
flag[0]=false;
chouaib:
if (flag[1]){
	goto chouaib;}

flag[0]=false;
}
criticalSection() ;

printf("thread 1 : %d \n",x);
sleep(1);

flag[0]=false;
}while(1);
}

void* Thread2(void* arg)
{
sleep(3);
do{
flag[1]=true;

while(flag[0]){
	
flag[1]=false;
chouaib:
if (flag[0]){
	goto chouaib;}

flag[1]=false;
}
criticalSection() ;
printf("thread 2 : %d \n",x);
sleep(1);

flag[1]=false;
}while(1);

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
