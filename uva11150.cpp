#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    while(cin >> n){
        int cnt = 0, empty = 0;
        while((n + empty) >= 3){
            cnt += n;
            empty += n;
            n = empty / 3;
            empty %= 3;
        }
        cnt += n;
        if((n + empty) == 2) cnt ++;
        cout << cnt << "\n";
    }
}