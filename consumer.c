
#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <fcntl.h>
#include <unistd.h>

sem_t *prod_sem, *buffer_sem, *con_sem;

int tablesize = 2;

int main()
{
	prod_sem = sem_open("/sem-mutex", 0, S_IRUSR | S_IWUSR, 1);

	sem_wait(prod_sem);
	con_sem = sem_open("/con-mutex", O_CREAT, S_IRUSR | S_IWUSR, 1);
	while (tablesize > 0)
	{
		printf("\n Consuming: %d", tablesize);
		tablesize--;
	}
	sem_post(con_sem);
	tablesize = 2;


}
