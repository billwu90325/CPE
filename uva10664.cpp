#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

/*
(1) stringstream: string(line) <-> int
(2) DP: "direction of iteration" -> represent "1" or "infinite" number
*/

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    string buffer;
    getline(cin, buffer);
    for(int i = 0; i < n; i++){
        string s;
        getline(cin, s);

        stringstream ss(s);
        vector<int> w;
        int weight, sum = 0;
        while(ss >> weight){
            w.push_back(weight);
            sum += weight;
        }

        if(sum % 2 == 1) cout << "NO\n";
        else{
            vector<bool> available(sum + 1, false);
            available[0] = true;
            for(int j = 0; j < w.size(); j++){
                // iteration direction is important
                for(int k = sum; k >= w[j]; k--){
                    if(available[k - w[j]]) available[k] = true;
                }
            }
            if(available[sum / 2]) cout << "YES\n";
            else cout << "NO\n";
        }
    }
}