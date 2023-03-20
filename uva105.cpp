#include <iostream>
#include <vector>
using namespace std;

/*
(1) record highest(skyline)
(2) output intersecting point 
*/

int main(){
    int l, h, r;
    int maxr = 0;
    vector<int> height(10000, 0);
    while(scanf("%d %d %d", &l, &h, &r) != EOF){
        maxr = max(maxr, r);
        for(int i = l; i < r; i++) height[i] = max(height[i], h);
    }

    bool space = false;
    for(int i = 1; i <= maxr; i++){
        if(height[i - 1] != height[i]){
            if(space) printf(" ");
            space = true;
            printf("%d %d", i, height[i]);
        }
    }
    printf("\n");
    return 0;
}