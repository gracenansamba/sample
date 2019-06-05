#include <iostream>
#include <cstdio>
#include <cmath>
#define blockSize 1

using namespace std;

__global__
void dots(float *A, float *B, float *C, int M, int N, int K) 

{	
	 printf("A : %.1f %.1f %.1f", A[0], A[1] ,A[2]);
       	printf("B : %.1f %.1f %.1f", B[0] ,B[1], B[2]);
	printf ("C: %.1f  %.1f %.1f", C[0] , C[1], C[2]);
 

	int I = blockIdx.x * blockDim.x + threadIdx.x;
	int J = blockIdx.y * blockDim.y + threadIdx.y;

	if (I>=M || J >=N)
		printf("threads are more than size");

	
	else 
		{
			int k; //where do  i set the k from? 
			//printf("A : %d", A[0]);
			
			float temp = 0;
			for (k=0; k<3; k++){
				temp += A[I*K+k] * B[k*N +J];
				C[I*N+J] = temp;
				printf ("C = %d  " ,C[I*N+J]);
			}
			//printf("CIJ = %d\n", C[I*N+J]);
			printf("AIk = %d\n", A[I*K+k]);
			printf("BkJ = %d\n", B[k*N+J]);
			
		}
}
int main()
{

	int M=3; int N=3; int K =3;
/*
	float A[M][K]= {1,2,3}; //can i do a dot like a matrix?
	float B[K][N]= {1,2,3};
	float C[M][N] = {0,0,0};
*/
	//is this how i would do a normal dot
	float  A[M]= {1,2,3};//printf("A : % d  %d %d ", A[0], A[1], A[2]);
		//float *A = Aa; printf("A : % d  %d %d ", A[0], A[1], A[2]);
	float B[N]= {1,2,3};
	float C[3] = {0,0,0};
	

	
//Allocate memory for device
	float *dA, *dB, *dC;
	cudaMalloc(&dA, M*sizeof(float));
	cudaMalloc(&dB, N*sizeof(float));
	cudaMalloc(&dC, sizeof(float));

//Copy memory to deveice

	cudaMemcpy(dA, &A[0], M* sizeof(float),cudaMemcpyHostToDevice);
	cudaMemcpy(dB, &B[0], N*sizeof(float),cudaMemcpyHostToDevice);
	cudaMemcpy(dC, &C[0], sizeof(float),cudaMemcpyHostToDevice);

//call kernel
	
	dots<<<1,1>>>(dA,dB,dC,M,N,K);

//Copy memory back to host
	cudaMemcpy(C,&dC, sizeof(float), cudaMemcpyDeviceToHost);
	
	cudaFree (dA);  cudaFree (dB);  cudaFree (dC);
	return 0;
}

