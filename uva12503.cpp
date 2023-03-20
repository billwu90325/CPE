#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    for(int i = 0; i < T; i++){
        int n;
        string buffer;
        cin >> n;
        getline(cin, buffer);
        string cmd;
        int location = 0;
        vector<bool> record;
        for(int j = 0; j < n; j++){
            getline(cin, cmd);
            if(cmd == "LEFT"){
                location --;
                record.push_back(0);
            }else if(cmd == "RIGHT"){
                location ++;
                record.push_back(1);
            }else{
                string index = cmd.substr(8, cmd.size() - 8);
                if(record[stoi(index) - 1]){
                    location ++;
                    record.push_back(1);
                }else{
                    location --;
                    record.push_back(0);
                }
            }   
        }
        cout << location << "\n";
    }
}