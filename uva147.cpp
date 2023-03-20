#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;
#define limit 30001

/*
(1) DP problem
(2) convert between "int" & "float" -> may generate error
*/

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    // better use "int" instead of "float" -> less convertion(float can't be index also)
    int money[] = {10000, 5000, 2000, 1000, 500, 200, 100, 50, 20, 10, 5};
    long long dp[limit] = {1}; // dp[0] = 1 
    
    for(int i = 0; i < 11; i ++){
        for(int j = money[i]; j < limit; j += 5){ // 0.05 is the smallest unit
            dp[j] += dp[j - money[i]];
            // don't need to worry about previous results -> optimal
            // no duplicated problem -> one time for every denomination
            // concept: last one is the current denomination
        }
    }

    int a, b;
    char buffer;
    while(cin >> a >> buffer >> b){
        if(a == 0 && b == 0) break;
        float n = a + (float)b / 100;
        int index = (a * 100) + b;
        cout << fixed << setprecision(2) << setw(6) << n;
        cout << setw(17) << dp[index] << "\n";
    }
}