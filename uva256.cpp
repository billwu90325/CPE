#include <iostream>
#include <cmath>
#include <iomanip> 
// control & define I/O stream and related functions
using namespace std;

/*
A. DP
B. Regular method
    (1) fixed: output with float without scientific notation
    (2) setprecision: set precision after decimal point
    (3) setfill(): fill the width with certain mark
    (4) setw(): width of output
    (printf("%0*d\n", n, number)) -> fill "number" with "0" to width "n"
*/

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    while(cin >> n){
        int half = pow(10, n / 2);
        for(int i = 0; i < half; i++){
            for(int j = 0; j < half; j++){
                if(pow((i + j), 2) == half * i + j){
                    cout << fixed << setprecision(0) << setfill('0') << setw(n) << pow((i + j), 2) << "\n";
                    //printf("%0*d\n", n, half * i + j);
                }
            }
        }
    }
}
