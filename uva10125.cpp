#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int search(vector<int>& set){
    for(int d = set.size() - 1; d >= 0; d--){
        for(int a = 0; a < set.size(); a++){
            for(int b = a + 1; b < set.size(); b++){
                for(int c = b + 1; c < set.size(); c++){
                    if((set[d] == set[a] + set[b] + set[c]) && a != d && b != d && c != d){
                        return set[d];
                    }
                }
            }
        }
    }
    return -1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    while(cin >> n && n != 0){
        vector<int> set(n);
        for(int i = 0; i < n; i++)cin >> set[i];
        sort(set.begin(), set.end());
        int answer = search(set);
        if(answer == -1) cout << "no solution\n";
        else cout << answer << "\n";
    }
}