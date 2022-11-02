
#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <fcntl.h>
#include <unistd.h>

sem_t* prod_sem, * buffer_sem, *con_sem;

int tablesize = 0;
int buffersize = 2;

//int i;
//int a;
int main()
{
	con_sem = sem_open("/con-mutex", 0, S_IRUSR | S_IWUSR, 1);

	if (tablesize == 0)
	{
		sem_wait(con_sem);
		//sem_getvalue(con_sem, &i);
	}

	prod_sem = sem_open("/sem-mutex", O_CREAT, S_IRUSR | S_IWUSR, 1);
	//sem_getvalue(con_sem, &a);
	//printf("%d", a);

	while (tablesize < buffersize)
	{
		tablesize++;
		printf("\n Producing: %d", tablesize);
	}
	sem_post(prod_sem);
	tablesize = 0;
}