#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    while(cin >> n){
        vector<int> data(n);
        for(int i = 0; i < n; i++){
            cin >> data[i];
        }

        sort(data.begin(), data.end());
        int mid1 = data[(n - 1) / 2];
        int mid2 = data[n / 2];
        int answer = 0;
        for(int i = 0; i < n; i++){
            if(data[i] == mid1 || data[i] == mid2){
                answer ++;
            }
        }
        cout << mid1 << " " << answer  << " " << mid2 - mid1 + 1 << "\n";
    }
}