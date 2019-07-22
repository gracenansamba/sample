#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class LUFact{
        private:
                        double r1a,r1b,r1c,r2a,r2b,r2c,r3a,r3b,r3c;
                        //double elim1, elim2, elim3;
                        double k1, k2, k3;
        public:
                        LUFact (double r1a,double r1b,double r1c,double r2a,double r2b,double r2c,double r3a,double r3b,double r3c) {
                                this->r1a=r1a; this->r1b=r1b; this->r1c=r1c;
                                this->r2a=r2a; this->r2b=r2b; this->r2c=r2c;
                                this->r3a=r3a; this->r3b=r3b; this->r3c=r3c;
                        }
                        double getR1a(){return r1a;}
                        double getR1b(){return r1b;}
                        double getR1c(){return r1c;}
                        double getR2a(){return r2a;}
                        double getR2b(){return r2b;}
                        double getR2c(){return r2c;}
                        double getR3a(){return r3a;}
                        double getR3b(){return r3b;}
                        double getR3c(){return r3c;}

                        double elim1(){
                                if (r1a !=0)
                                        return r2a = r2a - (k1*r1a);

                        }
                        double ell(){           //if (r1b !=0)
                                        return r2b = r2b - (k1*r1b);}
                                //if (r1c !=0)
                        double el(){    return r2c = r2c - (k1*r1c);}
                        //}


                        double elim2(){
                                return r3a = r3a - (k2*r1a);}

                        double ell2(){
                                return r3b = r3b - (k2*r1b);}
                        double el2(){
                                return r3c = r3c - (k2*r1c);}

                        double elim3(){
                                return r3a = r3a - (k3*r2a);}
                        double ell3(){
                                        return r3c = r3c - (k3*r2c);}
			double el3(){
                                return r3c = r3c - (k3*r2c);}
			double k;
			void coeff (){

				if (row >=0)
				{
					if (row= r1a||row= r1a|| row= r1a || row= r1a)
						{row - k = 0; }
					else //if row-k= 0 ; do nothing else find k as an unknown
				}
				
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

                         LUFact one (r1a,r1b,r1c,r2a,r2b,r2c,r3a,r3b,r3c);
                         double g = one.elim1();
                         one.elim2();
                         one.elim3();

                        cout << "u1 = " << one.elim1() << endl;
                        cout << "u2 = " << one.ell() << endl;
	                cout << "u3 = " <<one.el() << endl;
                        cout << "u4 = " <<one.elim2() << endl;
                        cout << "u5 = " <<one.ell2() << endl;
                        cout << "u6 = " <<one.el2() << endl;
                        cout << "u7 = " <<one.elim3() << endl;
                        cout << "u8 = " <<one.ell3() << endl;
                        cout << "u9 = " <<one.el3() << endl;

                        return 0;                                                             
 }
                            
