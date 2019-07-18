nclude <iostream>
#include <string>
#include <cmath>

using namespace std;

class LUFact{
	        private;
		                double r1a,r1b,r1c,r2a,r2b,r2c,r3a,r3b,r3c;
				                double elim1, elim2, elim3;
						                double k1, k2, k3;
								        public;
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


																													                void elim1(){
																																                        r2a = r2a - (k1*r1a);
																																			                        r2b = r2b - (k1*r1b);
																																						                        r2c = r2c - (k1*r1c);
																																									                }
																															                void elim2(){
																																		                        r3a = r3a - (k2*r1a);
																																					                        r3b = r3b - (k2*r1b);
																																								                        r3c = r3c - (k2*r1c);
																																											                }

																																	                void elim3()void elim3(){
																																				                        r3a = r3a - (k3*r2a);
																																							                        r3c = r3c - (k3*r2b);
																																										                        r3c = r3c - (k3*r2c);
																																													                }
};

int main(){
	                 double r1a,r1b,r1c,r2a,r2b,r2c,r3a,r3b,r3c;
			                  cout << "please enter values of the 3 equations: "<< endl;
					                   cin r1a; cout<< "";cin r1b;cout<< ""; cin r1c;cout<< "" <<endl;
							                    cin r2a; cout<< "";cin r2b;cout<< ""; cin r2c;cout<< "" <<endl;
									                     cin r3a; cout<< "";cin r3b;cout<< ""; cin r3c;cout<< "" <<endl;
											     
											                      LUFact one (r1a,r1b,r1c,r2a,r2b,r2c,r3a,r3b,r3c);
													                       one.elim1();
															                        one.elim2();
																		                 one.elim3();
																				 
																				                  cout << "upper triangular = " << one.elim1();
																						  
																						                  return 0;
																								  
																								  
}
