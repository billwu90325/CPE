#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int round;
    cin >> round;
    vector<int> answer;
    for(int i = 0; i < round; i++){
        int num;
        cin >> num;
        int lines = 0;
        vector<int> x(num);
        vector<int> y(num);
        vector<vector<bool> > check;
        vector<bool> initial(num, true);
        // initialize vector -> (number or elements, value)

        for(int j = 0; j < num; j++){
            check.push_back(initial);
            check[j][j] = false;
        }

        for(int j = 0; j < num; j++){
            cin >> x[j];
            cin >> y[j];
        }

        for(int j = 0; j < num; j++){
            for(int k = 0; k < num; k++){
                if(check[j][k] && check[k][j]){
                    vector<int> group;
                    group.push_back(j);
                    group.push_back(k);
                    int M = (y[k] - y[j]) / (x[k] - x[j]);
                    for(int l = 0; l < num; l++){
                        if(check[j][l] && check[l][j]){
                            if((x[l] - x[j]) == 0 && (y[l] - y[j]) == 0) group.push_back(l);
                            else if((x[l] - x[j]) == 0) continue;
                            else if((y[l] - y[j]) == 0) continue;
                            else{
                                int m = (y[l] - y[j]) / (x[l] - x[j]);
                                if(M == m) group.push_back(l);
                            }
                        }
                    }
                    for(int m = 0; m < group.size(); m++){
                        for(int n = 0; n < group.size(); n ++){
                            check[group[m]][group[n]] = false;
                        }
                    }
                    lines ++;
                }
            }
        }
        answer.push_back(lines);
    }

    for(int i = 0; i < round; i++){
        cout << answer[i] << "\n";
    }
    return 0;
}
