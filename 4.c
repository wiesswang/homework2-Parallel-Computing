#include <stdio.h>
#include <omp.h>

int main()
{
	int i, j;
	int a[100][100] = {0};
	for ( i =0; i < 100; i++)
	{
		for( j = i; j < 100; j++ )
		{
 			a[i][j] = i*j;
		}
	}
 #pragma omp parallel for schedule(dynamic)
 	for(i = 0; i < 10; i++ )
 	{
 		printf("i=%d, thread_id=%d\n", i, omp_get_thread_num());
	}
}
