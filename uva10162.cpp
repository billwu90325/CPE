#include <iostream>
#include <cmath>
#include <string>
using namespace std;

/*
(1) number too big -> unable to store with "int" or "long long"
    -> string(translate later)

(2) string[index] -> char -> int (- '0')
(3) handle overflood situation
(4) find the rule of last digit
*/

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int results[100];
    int sum = 0;
    for(int i = 1; i <= 100; i++){
        int add = 1;
        for(int j = 0; j < i; j++){
            add *= i;
            add %= 10;
        }
        sum += add;
        sum %= 10;
        results[i % 100] = sum;
    }

    string n;
    while(cin >> n && n != "0"){
        int len = n.length(); 
        int index = n[len - 1] - '0';
        if(len > 1) index += 10 * (n[len - 2] - '0');
        
        cout << results[index % 100] << "\n";
    }
}