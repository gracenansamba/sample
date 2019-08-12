#include <iostream>
#include <string>
#include <cmath>

/*
 this program can get the LU of a [3][3] matrix
 An equation solver should be robust and scalable
 it's still very manual unscalable : (the user should
 be able to enter any size of a matrix and the eimination 
 formula should be one for all i guess 
 Working on that 
 */
using namespace std;

class LUFact{
        private:
                        double r1a,r1b,r1c,r2a,r2b,r2c,r3a,r3b,r3c;
                        //double elim1, elim2, elim3;
                        double k, k1, k2, k3;
			double A [3][3];
			double U [3][3];
        public:
			//constructor
                        LUFact (double r1a,double r1b,double r1c,double r2a,double r2b,double r2c,double r3a,double r3b,double r3c) {
                                this->r1a=r1a; this->r1b=r1b; this->r1c=r1c;
                                this->r2a=r2a; this->r2b=r2b; this->r2c=r2c;
                                this->r3a=r3a; this->r3b=r3b; this->r3c=r3c;
                        }

			//need a function to calculate the real LU 
	
                        double elimRow2 (double A[3][3], double& k1 ){
				//double kkk;
				for(int i=0; i<3; i++){
				if(i==1){	
				for(int j=0; j<3; j++){
                                //if (r1a !=0)
				//for(int k= 0; k<3; k++){
				if(j==0){
					k1=(A[i][j])/(A[i-1][j]);
					//printf("value of k1 = %.1f \n ",k1);
					} 
				      // printf("value of k %.1f \n = " , k);	
					//if(A[i][j]!=0 && j==0){
                                       		A [i][j] =A[i][j]  - (k1*(A[i-1][j]));
		          				}
					}	
				}
				/*
				for (int i=0; i<3; i++){
                                for (int j=0; j<3; j++)
                                {
                                        printf("%.1f\t", A[i][j]);
                                }
                                        printf("\n"); printf("\n");}*/
                                return A[3][3];//,k1;printf("k1 returned = %.1f ",k);
				}
			       				
                        double elimRow3(double A[3][3], double& k2 ){
                                //f (i==2){
                                for(int i=0; i<3; i++){
                                if(i==2){     
                                for(int j=0; j<3; j++){

				if(j==0){
                                	k2= (A[i][j])/(A[i-2][j]);
					//printf ("value of k2 for second elim =%.1f \n", k2);
					
					}
					//printf("value of k for second elim is %.1f" , k);
                                        A[i][j] =A[i][j]  - (k2*(A[i-2][j])); //printf("%.1f\t", U[i][j]);
							}
                                }
                                }/*
                                for (int i=0; i<3; i++){
				 for (int j=0; j<3; j++)
                                {
                                        printf("%.1f\t", A[i][j]);
                                }
                                        printf("\n"); printf("\n");}*/
				return A[3][3];
			}

			double elimRow3F(double A[3][3], double& k3 ){
                                //f (i==2){
                                for(int i=0; i<3; i++){
                                if(i==2){
                                for(int j=0; j<3; j++){
                                //if (r1a !=0)
				if (j==1){
					k3 = (A[i][j])/(A[i-1][j]);
					//printf("value of k3 third elim = %.1f \n",k3);
					}
                                        A[i][j] =A[i][j]  - (k3*(A[i-1][j])); //printf("%.1f\t", U[i][j]);
                                		}
                                	}
                                }
                                for (int i=0; i<3; i++){
                                 for (int j=0; j<3; j++)
                                {
                                        printf("%.1f\t", A[i][j]);
                                }
                                        printf("\n"); printf("\n");
                                }return A[3][3];
                        }	
};

int main(){
			double r1a,r1b,r1c,r2a,r2b,r2c,r3a,r3b,r3c;
                        double k1, k2, k3,kkk;
			//printf("value of k1 in the  main = %.1f", k1);
	        	 cout << "please enter values of the 3 equations: "<< endl;
                         cin>> r1a; cout<< "";cin >>r1b;cout<< ""; cin>> r1c;cout<< "" <<endl;
                         cin>> r2a; cout<< "";cin>> r2b;cout<< ""; cin>> r2c;cout<< "" <<endl;
                         cin>> r3a; cout<< "";cin>> r3b;cout<< ""; cin>> r3c;cout<< "" <<endl;
                      
			 double A [3][3] = {{r1a,r1b,r1c},{r2a,r2b,r2c},{r3a,r3b,r3c}};
                         double U [3][3] = {{0,0,0},{0,0,0},{0,0,0}};
			
		         LUFact one (r1a,r1b,r1c,r2a,r2b,r2c,r3a,r3b,r3c);
                        //cout << "first elimination" << endl;
			 one.elimRow2(A,k1);
		 	// cout << "second elimination" << endl;
			 one.elimRow3(A,k2);
			 cout << " The upper Triangular is " << endl;
			 one.elimRow3F(A, k3);
			//double k1,k2,k3,kkk;
			 cout << "The lower triangular is "<< endl;
			double L [3][3] ={{1,0,0},{k1,1,0},{k2,k3,1}};
			for(int i=0;i<3;i++){
				for (int j=0; j<3; j++){
					//cout<< L[i][j];
					 printf("%.1f\t",L[i][j]);
				}
				printf("\n"); printf("\n");

			}
                      return 0;                                                          
 }
                            
