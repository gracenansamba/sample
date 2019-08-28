//cubic sum of 0<n<41
#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int main(){
    int n=41;
    int sum=0;
    for (int i=0; i<n; i++){
        sum += (pow(i,3));
    }cout << sum <<endl;
}
