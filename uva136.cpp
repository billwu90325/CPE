#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
find next qualified "ugly number" with DP
*/

int main(){
    int cnt = 4;
    vector<int> ugly(1500);
    ugly[0] = 1;
    ugly[1] = 2;
    ugly[2] = 3;
    ugly[3] = 4;
    ugly[4] = 5;
    
    while(cnt < 1499){
        vector<int> candidate;
        
        for(int i = 0; i < 1500; i++){
            if(ugly[i] * 2 > ugly[cnt]){
                candidate.push_back(ugly[i] * 2);
                break;
            }
        }
        for(int i = 0; i < 1500; i++){
            if(ugly[i] * 3 > ugly[cnt]){
                candidate.push_back(ugly[i] * 3);
                break;
            }
        }
        for(int i = 0; i < 1500; i++){
            if(ugly[i] * 5 > ugly[cnt]){
                candidate.push_back(ugly[i] * 5);
                break;
            }
        }
        sort(candidate.begin(), candidate.end());
        cnt ++;
        ugly[cnt] = candidate[0];
        
    }
    printf("The 1500'th ugly number is %d.\n", ugly[1499]);
    
}