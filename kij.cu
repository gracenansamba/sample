//********************************************************************************************************
#include <cstdio>// a simple matrix matrix multiplication in CUDA
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

//#ifdef DOLOG
//#define LOG(msg) std::cerr<<msg<<std::endl
#define LOG(msg) fprintf(stderr, msg "\n");
//#else
//#define LOG(msg)
//#endif

// host code for validating last cuda operation (not kernel launch)
//using namespace std;
#define gpuErrchk(ans) { gpuAssert((ans), __FILE__, __LINE__); }
inline void gpuAssert(cudaError_t code, const char *file, int line, bool abort=true)
{
   if (code != cudaSuccess)
   {
      fprintf(stderr,"GPUassert: %s %s %d\n", cudaGetErrorString(code), file, line);
      if (abort) exit(code);
   }
}

// CPU matrix multiplication: code(the normal way to mulitiply matrices)
__global__
void  multiply (int width,int height ,int firstCol ,int** A,int** B,int** C,int** A_O,int** B_O, int** C_O)
{

int x_idx = threadIdx.x + blockIdx.x * blockDim.x;
int y_idx = threadIdx.y + blockIdx.y * blockDim.y;


if (x_idx < width && y_idx <height ) {
//int temp = 0;

  for (int i = 0; i <3; i++)
    {
      //printf ("i= %d", i);
      //printf ("\n");
      for (int j = 0; j <3; j++)
	{
 	//printf ("j= %d", j);
 	//printf ("\n");
	int temp = 0;
	//printf ("temp= %d", temp);
 	//printf ("\n");
 	for (int k = 0; k < firstCol; k++)
  	 {
     		//printf ("k= %d", k);
    		// printf ("\n");
     		temp += A[i][k] * B[k][j]; //C is fixed while A is rowWise and B is columnWise
     		C_O[i][j] =temp ;
     		//printf ("Cij= %d", temp);
    		//printf ("\n");
 	}
    }
  }
}

}
//**************************************************************************************
__global__ void display (int width, int height,int** A,int** B,int** C ){

	for (int i = 0; i <3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
 		//printf ("%d\t", C[i][j]);
		}
	printf ("\n");
   }
}
//***********************************************************************************
int main ()
{

 int width, height;
//vector<vector<int> > A { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
//vector<vector<int> > B { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
//vector<vector<int> > C { {0, 0, 0}, {0, 0, 0}, {0, 0, 0} };

int A[][3]= { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
int B[][3]= { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
int C[][3]= { {0, 0, 0}, {0, 0, 0}, {0, 0, 0} };

//**********************************************************************************
//Memory allocaction

   width=3;
    height=3;
int firstCol= 3;
int **d_A, **d_B, **d_C; //allocate memory on device
//copy matrix to GPU
gpuErrchk(cudaMalloc((void**)&d_A, (width)*(height)*sizeof(int)));
gpuErrchk(cudaMalloc((void**)&d_B, (width)*(height)*sizeof(int)));
gpuErrchk(cudaMalloc((void**)&d_C, (width)*(height)*sizeof(int)));

//same
int **A_O,**B_O,**C_O;
gpuErrchk(cudaMalloc((void**)&A_O,(width)*(height)*sizeof(int)));
gpuErrchk(cudaMalloc((void**)&B_O,(width)*(height)*sizeof(int)));
gpuErrchk(cudaMalloc((void**)&C_O,(width)*(height)*sizeof(int)));


gpuErrchk(cudaMemcpy(d_A, &A[0][0],(width)*(height)*sizeof(int) , cudaMemcpyHostToDevice));
gpuErrchk(cudaMemcpy(d_B, &B[0][0],(width)*(height)*sizeof(int) , cudaMemcpyHostToDevice));
gpuErrchk(cudaMemcpy(d_C, &C[0][0],(width)*(height)*sizeof(int) , cudaMemcpyHostToDevice));
//printf ("matrix A= %d", A);
//printf ("matrix B= %d", B);
//call kernel
dim3 tpb(16,16);
dim3 bpg((width+tpb.x-1)/tpb.x, (height+tpb.y-1)/tpb.y);

multiply<<<bpg,tpb>>>(width, height , firstCol ,d_A,d_B,d_C, A_O, B_O, C_O);
display<<<bpg,tpb>>>(width,height,d_A,d_B,d_C);

//copy matrix back to CPU

//gpuErrchk(cudaMemcpy(&A[0][0], d_A, (width)*(height)*sizeof(int), cudaMemcpyDeviceToHost));
//gpuErrchk(cudaMemcpy(&B[0][0], d_B, (width)*(height)*sizeof(int), cudaMemcpyDeviceToHost));
gpuErrchk(cudaMemcpy(&C[0][0], (void**)C_O, (width)*(height)*sizeof(int), cudaMemcpyDeviceToHost));

cudaFree(d_A);cudaFree(d_B);cudaFree(d_C);cudaFree(A_O);cudaFree(B_O);cudaFree(C_O);

return 0;
}