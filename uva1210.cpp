#include <iostream>
#include <vector>
using namespace std;

/*
(1) find prime numbers
(2) restrictions of "for" loop
*/

int main(){
    vector<bool> nature(10000, true);
    vector<int> prime;
    for(int i = 2; i < 10000; i++){
        if(nature[i] == true){
            for(int j = i+i; j < 10000; j+=i) nature[j] = false;
            prime.push_back(i);
        }
    }

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    while(cin >> n && n != 0){
        int cnt = 0;
        for(int i = 0; prime[i] <= n; i++){
            int sum = 0;
            for(int j = i; sum < n; j++){
                sum += prime[j];
                if(sum == n){
                    cnt ++;
                    break;
                }
            }
        }
        cout << cnt << "\n";
    }
}