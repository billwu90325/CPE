#include <iostream>
using namespace std;

/*
find the rule of count on cantor
(1) which line?
(2) even or odd line?
*/

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    while(cin >> n){
        int line = 0;
        int num = n;
        while(num > 0){
            line ++;
            num -= line;
        }
        bool odd = line % 2;
        int index = num + line;
        int numberator, denominator;
        if(odd){
            denominator = index;
            numberator = line - index + 1;
        }else{
            denominator = line - index + 1;
            numberator = index;
        }
        cout << "TERM " << n << " IS ";
        cout << numberator << "/" << denominator << "\n"; 
    }
}