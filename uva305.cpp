#include <iostream>
#include <vector>
using namespace std;

/*
<joseph problem>
*/

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<int> answer(13);
    for(int i = 1; i < 14; i++){
        for(int j = i + 1; ; j++){
            int length = 2 * i;
            int pos = 0;
            bool bingo = true;

            for(int k = length; k > i; k--){
                // index start from "0"
                pos = (pos + j - 1) % k;
                if(pos < i){
                    bingo = false;
                    break;
                }
            }
            
            if(bingo){
                answer[i - 1] = j;
                break;
            }
        }
    }
    
    int n;
    while(cin >> n){
        if(n == 0) break;
        else cout << answer[n - 1] << "\n";
    }
}