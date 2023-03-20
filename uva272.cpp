#include <iostream>
using namespace std;

/*
(1) cin.get(c)
(2) getline(cin, s)
*/

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    char c;
    int cnt = 1;
    while(cin.get(c)){
        if(c == '"'){
            if(cnt % 2) cout << "``";
            else cout << "''";
            cnt ++;
        }else cout << c;
    }
}