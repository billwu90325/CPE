#include <iostream>
#include <vector>
using namespace std;

/*
bubble sort
*/

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int num;
    cin >> num;
    for(int round = 0; round < num; round++){
        int n;
        cin >> n;
        vector<int> train(n);
        for(int i = 0; i < n; i++){
            cin >> train[i];
        }

        bool judgement;
        int answer = 0;
        for(int i = 0; i < n; i++){
            judgement = true;
            for(int j = 0; j < (n - i - 1); j++){
                if(train[j] > train[j + 1]){
                    int tmp = train[j];
                    train[j] = train[j + 1];
                    train[j + 1] = tmp;
                    judgement = false;
                    answer ++;
                }
            }
            if(judgement) break;
        }

        cout << "Optimal train swapping takes " << answer << " swaps.\n";
    }
}