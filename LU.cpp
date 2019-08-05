#include <iostream>
#include <string>
#include <cmath>

/*
 this program can get the LU of the matrix "A [3][3] = {{1,2,3},{4,5,6},{7,8,10}}" 
 the coeficients are k1=4, k2=7, k3=2
 I calculated this before
 I need to make the coefficients auto and also to make the 
 equation solver robust and scalable
 it's still very manual unscalable
#brute forced for starters
 */
using namespace std;

class LUFact{
        private:
                        double r1a,r1b,r1c,r2a,r2b,r2c,r3a,r3b,r3c;
                        //double elim1, elim2, elim3;
                        double k1, k2, k3;
			double A [3][3];
			double U [3][3];
        public:
			//this is a constructor
                        LUFact (double r1a,double r1b,double r1c,double r2a,double r2b,double r2c,double r3a,double r3b,double r3c) {
                                this->r1a=r1a; this->r1b=r1b; this->r1c=r1c;
                                this->r2a=r2a; this->r2b=r2b; this->r2c=r2c;
                                this->r3a=r3a; this->r3b=r3b; this->r3c=r3c;
                        }

			//need a function to calculate the real LU 
	

			
                        double elimRow2 (double A[3][3], int k1 ){
				for(int i=0; i<3; i++){
				if(i==1){	
				for(int j=0; j<3; j++){
                                //if (r1a !=0)
				//for(int k= 0; k<3; k++){
                                       A [i][j] =A[i][j]  - (k1*(A[i-1][j]));
					//printf("value of A = %.1f\t", A[i][j]);printf("\n"); printf("\n");

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
				
			
			       				
                        double elimRow3(double A[3][3], int k2 ){
                                //f (i==2){
                                for(int i=0; i<3; i++){
                                if(i==2){     
                                for(int j=0; j<3; j++){
                                //if (r1a !=0)
                                        A[i][j] =A[i][j]  - (k2*(A[i-2][j])); //printf("%.1f\t", U[i][j]);

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

			double elimRow3F(double A[3][3], int k3 ){
                                //f (i==2){
                                for(int i=0; i<3; i++){
                                if(i==2){
                                for(int j=0; j<3; j++){
                                //if (r1a !=0)
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
                         double k1, k2, k3;
			
	        	 cout << "please enter values of the 3 equations: "<< endl;
                         cin>> r1a; cout<< "";cin >>r1b;cout<< ""; cin>> r1c;cout<< "" <<endl;
                         cin>> r2a; cout<< "";cin>> r2b;cout<< ""; cin>> r2c;cout<< "" <<endl;
                         cin>> r3a; cout<< "";cin>> r3b;cout<< ""; cin>> r3c;cout<< "" <<endl;
                        cout << "please enter the coefients :"<< endl;
                        cout << "k1= "; cin >> k1;
                        cout << "k2= "; cin >> k2;
                        cout << "k3= "; cin >> k3;
			
			 double A [3][3] = {{r1a,r1b,r1c},{r2a,r2b,r2c},{r3a,r3b,r3c}};
                         double U [3][3] = {{0,0,0},{0,0,0},{0,0,0}};
			
			  //printf("value of A below = %.1f\t", A[1][1]);

			 //double A [3][3] = {{1,2,3},{4,5,6},{7,8,10}};
                        // double U [3][3] = {{0,0,0},{0,0,0},{0,0,0}};


 	                 LUFact one (r1a,r1b,r1c,r2a,r2b,r2c,r3a,r3b,r3c);
                         cout << "first elimination" << endl;
			 one.elimRow2(A,k1);
		 	 cout << "second elimination" << endl;
			 one.elimRow3(A,k2);
			 cout << " The upper Triangular is " << endl;
			 one.elimRow3F(A,k3);

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
                            
