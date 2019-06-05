#include <iostream>
#include <cstdio>
#include <cmath>
#define blockSize 1

using namespace std;

__global__
void dots(float *A, float *B, float *C, int M, int N, int K) 
{
	int I = blockIdx.x * blockDim.x + threadIdx.x;
	int J = blockIdx.y * blockDim.y + threadIdx.y;

	if (I>=M || J >=N)
		printf("threads are more than size");
	
	else 
		{
			int k; //where do  i set the k from? 
			printf("A : %d, B : %d, C : %d, M : %d, N : %d, K : %d\n", A,B,C,M,N,K);
			
			float temp = 0;
			for (k=0; k<K; k++){
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
	int M=3; int N=3; int K =1;
	int A[M][K]= {1,2,3}; //can i do a dot like a matrix?
	int B[K][N]= {1,2,3};
	int C[M][N] = {0,0,0};
/*
	is this how i would do a normal dot
	int A[M]= {1,2,3};
	int B[N]= {1,2,3};
	int C[K] = {0,0,0};
	
*/
	
//Allocate memory for device
	float *dA, *dB, *dC;
	cudaMalloc(&dA, M*sizeof(float));
	cudaMalloc(&dB, N*sizeof(float));
	cudaMalloc(&dC, K*sizeof(float));

//Copy memory to deveice

	cudaMemcpy(&dA, A, sizeof(float), cudaMemcpyDeviceToHost);
	cudaMemcpy(&dB, B, sizeof(float), cudaMemcpyDeviceToHost);
	cudaMemcpy(&dC, C, sizeof(float), cudaMemcpyDeviceToHost);

//call kernel
	
	dots<<<1,1>>>(dA,dB,dC,M,N,K);

//Copy memory back to host
	cudaMemcpy(C,&dC, sizeof(float), cudaMemcpyHostToDevice);
	
	cudaFree (dA);  cudaFree (dB);  cudaFree (dC);
	return 0;
}
