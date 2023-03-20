#include <iostream>
#include <vector>
using namespace std;

/*
<Josephus Problem>
(1) start from 1
(2) add "m" to last survival each round
*/

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<int> answer(101);
    for(int i = 13; i <= 100; i++){
        for(int m = 1; ; m++){
            int pos = 0;
            for(int k = 1; k < i; k++){
                pos = (pos + m) % k;
            }
            if(pos == 11){
                answer[i] = m;
                break;
            }
        }
    }

    int n;
    while(cin >> n && n != 0){
        cout << answer[n] << "\n";
    }
}
