#include <iostream>
#include <vector>
using namespace std;

/*
<DP problem>
    index of dp is the outcome of corresponding rocks
    -> dp[0] is definitely "loss"
    -> dp[0] + available step -> definitely "win"
    -> extend the concept to the number of rocks

*/

int main(){
    int rock, num;
    while(cin >> rock >> num){
        vector<int> set(num);
        for(int i = 0; i < num; i++){
            cin >> set[i];
        }

        vector<bool> dp(rock + 1, 0);
        for(int i = 1; i <= rock; i++){
            for(int j = 0; j < num; j++){
                if(i - set[j] >= 0 && dp[i - set[j]] == 0){
                    dp[i] = 1;
                }
            }
        }
        /*
        for(int i : dp) cout << i << " ";
        cout << "\n";
        */
        if(dp[rock] == 1) cout << "Stan wins\n";
        else cout << "Ollie wins\n";
    }
}
