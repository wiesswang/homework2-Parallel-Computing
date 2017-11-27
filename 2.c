# include<stdio.h>
# include<math.h>
# include "omp.h"
int main()
{
	int m =1, x = 0;
	for (m=1;m<9;m++)
	{
		int i,j;
		int k=0;
		FILE *fp;
		fp = fopen ("result.txt","w");
		if (fp ==NULL)
		{
			printf ("faile open the file!\n");
			exit (-1);
		}
		double start = omp_get_wtime( );
		omp_set_num_threads(m);
		#pragma omp parallel for  private(i,j) reduction(+:k)
		for (i = 2; i < 100000; i++)
       		{
			x = omp_get_num_threads();
			for (j = 2; j <= sqrt(i); j++)
               		{
                       		if (i % j == 0)
                       		{
                               		break;
                       		}
               		}
               		if(j > sqrt(i))
               		{
                       		fprintf (fp,"%d ",i);
				k++;
                        }
		}
		printf("素数的个数为:%d ",k);
	        printf("线程数为:%d ",x);
   		double end = omp_get_wtime( );  
   		printf("start = %.16g,end = %.16g,diff = %.16g seconds ",start, end, end - start);  
		//fclose(fp)
		double s = 0.019/(end - start);
		printf("加速比为:%f\n",s);
	}
	return 0;
}


