# include<stdio.h>
# include<math.h>
# include<stdlib.h>
#include "omp.h"
int main()
{
	int m =1;
	for (m=1;m<9;m++){
		double start = omp_get_wtime( );
		int i,j,k=0;
		int n=0;
		FILE *fp;
		fp = fopen ("result.txt","w");
		if (fp ==NULL)
		{
			printf ("faile open the file!\n");
			exit (-1);
		}
		omp_set_num_threads(m);	
		for(i=2;i<100000;i++){
			for(j=2;j<=sqrt(i);j++)
				if(i%j==0)
					break; 
				if(j>sqrt(i))
        			{
					fprintf (fp,"%d ",i);
            				k++;
        			}
    		}
		printf("\n素数的个数为:%d\n",k);
		printf("\n线程数为:%d\n",m);
    		double end = omp_get_wtime( );   
    		printf("start = %.16g\nend = %.16g\ndiff = %.16g seconds\n",  
             		start, end, end - start);  
  
	}

}

