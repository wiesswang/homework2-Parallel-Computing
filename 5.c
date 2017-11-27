#include <stdio.h>
#include <omp.h>
#define N 10
#define m 2
int main()
{
	double a[N][N];
	double b[N][N];
	double c[N][N];
	int n=0;
	int i,j,k;
	//some initializations
	 double start = omp_get_wtime( );
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			a[i][j]=1;
			b[i][j]=1;
			c[i][j]=0;
		}
	}
	omp_set_num_threads(m);
#pragma omp parallel shared(a,b,c) private(i,j,k)
{
#pragma omp for schedule(dynamic)
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			for(k=0;k<N;k++)
				c[i][j]+=a[i][k]*b[k][j];
		}
	}
}
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			printf("%lf ",c[i][j]);
		}
		printf("\n");
	}
	double end = omp_get_wtime( );  
    	printf("start = %.16g\nend = %.16g\ndiff = %.16g seconds\n",  
             		start, end, end - start);  
}
