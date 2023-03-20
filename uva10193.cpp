#include <iostream>
#include <string>
using namespace std;

/*
(1) binary string to integer
    -> int stoi (const string&  str, [size_t* idx], [int base]);
(2) GCD formula: Euclidean algorithm
*/

int gcd(int a, int b);

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    string buffer;
    getline(cin, buffer);
    string s1, s2;
    int n1, n2;
    for(int i = 0; i < n; i++){
        getline(cin, s1);
        getline(cin, s2);
        n1 = stoi(s1, 0, 2);
        n2 = stoi(s2, 0, 2);
        
        cout << "Pair #" << i + 1 << ": ";
        if(gcd(n1, n2) != 1) cout << "All you need is love!\n";
        else cout << "Love is not all you need!\n";
    }
}

int gcd(int a, int b){
  if(a == 0 || b == 0) return a + b;
  while((a %= b) != 0 && (b %= a) != 0);
  return a + b;
}