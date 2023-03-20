#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    while(cin >> n && n != 0){
        string cmd;
        vector<int> dice;
        for(int i = 1; i < 7; i++) dice.push_back(i);
        // [0] = up
        // [1] = north
        // [2] = west
        // [3] = east
        // [4] = south
        // [5] = down

        for(int i = 0; i < n; i++){
            cin >> cmd;
            if(cmd == "east"){
                int tmp = dice[0];
                dice[0] = dice[2];
                dice[2] = dice[5];
                dice[5] = dice[3];
                dice[3] = tmp;
            }else if(cmd == "south"){
                int tmp = dice[0];
                dice[0] = dice[1];
                dice[1] = dice[5];
                dice[5] = dice[4];
                dice[4] = tmp;
            }else if(cmd == "west"){    
                int tmp = dice[0];
                dice[0] = dice[3];
                dice[3] = dice[5];
                dice[5] = dice[2];
                dice[2] = tmp;
            }else{
                int tmp = dice[0];
                dice[0] = dice[4];
                dice[4] = dice[5];
                dice[5] = dice[1];
                dice[1] = tmp;
            }
        }
        cout << dice[0] << "\n";
    }
}
