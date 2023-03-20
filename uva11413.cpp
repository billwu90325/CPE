#include <iostream>
#include <vector>
using namespace std;

/*
binary search for capacity
*/

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    while(cin >> n >> m){
        vector<int> bottle(n);
        int left = 0, right = 0;
        for(int i = 0; i < n; i++){
            cin >> bottle[i];
            left = max(left, bottle[i]);
            right += bottle[i];
        }

        int mid;
        while(left < right){
            mid = (left + right) / 2;
            int sum = 0, cnt = 0;
            for(int i = 0; i < n; i++){
                sum += bottle[i];
                if(sum > mid){
                    cnt ++;
                    sum = bottle[i];
                }else if(sum == mid){
                    cnt ++;
                    sum = 0;
                }
            }
            if(sum > 0) cnt ++;
            if(cnt > m) left = mid + 1;
            else right = mid - 1;
            // notice the translation of boundary -> mid +- 1
        }
        cout << left << "\n";
    }
}