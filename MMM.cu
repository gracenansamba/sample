#include<cmath> 
#include<cstdio> 

__global__ 
void multiply(int*A,int*B,int*C, int M, int N, int K, int n) 
	{ 
	int i=blockIdx.y* blockDim.y + threadIdx.y; printf(" i= %d \n", i);
				//printf(" Tx= %d \n", threadIdx.y);
	int j=blockIdx.x *blockDim.x + threadIdx.x; printf(" j= %d \n", j);
				//printf(" Ty= %d \n", threadIdx.x);
		//for(int i=0;i<n;i++){    printf("%d\n",A[i]);} printf("\n", " ");
		//for(int j=0;j<n;j++){  printf("%d\n",B[j]);} 
	int temp=0;
	if( (i<(n)) && (j<(n))) { 
		
		for( int k=0;k<n;k++){printf("\n", " "); printf(" k= %d \n", k);
			 temp += A[(i)*N+k]*B[k*N +j];
				printf(" aIndex= %d \n", i*N+k);
				printf(" a= %d \n", A[(i)*K+k]);

				printf(" bIndex= %d \n", k*N+j);
				printf(" b= %d \n", B[k*N+(j)]);
	
		} C[(i)*N+(j)] =temp;
		for (i = 0; i < n; i++){  
			printf("[%d] =%d\n",i, C[i*N+j]); 
		} 
	} 
}
int main()
{ 
int M=3;int N=3; int K=3; int n=9; 

	int A[M][K]= {{1,2,3}, {4,5,6}, {7,8,9}}; 
	int B[K][N]= {{1,2,3}, {4,5,6}, {7,8,9}};  
	int C[M][N]= {{0,0,0},{0,0,0},{0,0,0}}; 
	
int* d_A;int* d_B;int* d_C; 
//int* A;int* B;int* C;  

//allocating space for variables on device  

cudaMalloc(&d_A,n* sizeof(int));//let memory store that m*n space for you of size ints  
cudaMalloc(&d_B,n* sizeof(int)); 
cudaMalloc(&d_C,n* sizeof(int)); 

//copy Aand B FROM HOST TO DEVICE  

cudaMemcpy(d_A, &A[0],n* sizeof(int) , cudaMemcpyHostToDevice); 
cudaMemcpy(d_B, &B[0],n *sizeof(int) , cudaMemcpyHostToDevice); 
cudaMemcpy(d_C, &C[0],n*sizeof(int) , cudaMemcpyHostToDevice); 


multiply<<<1,1>>>(d_A,d_B,d_C,M,N,K,n); 
//COPY RESULT BACK TO HOST 
cudaMemcpy(&C[0], d_C,n* sizeof(int), cudaMemcpyDeviceToHost); 


//printf("%d", C[0]);

cudaFree(A);//TO FREE MEMORY 

cudaFree(B); 
cudaFree(C); 
}