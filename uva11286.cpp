#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
using namespace std;

/*
(1) sort map by value
    -> transfer into vector
    -> sort pair(define operator)
*/

bool sortByVal(pair<string, int> &a, 
               pair<string, int> &b);

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    while(cin >> n && n != 0){
        map<string, int> course;
        for(int i = 0; i < n; i++){
            vector<int> pick(5);
            for(int j = 0; j < 5; j++){
                cin >> pick[j];
            }
            sort(pick.begin(), pick.end());
            string result = "";
            for(int j = 0; j < 5; j++){
                result += to_string(pick[j]);
            }
            if(course.find(result) != course.end()) course[result] ++;
            else course[result] = 1;        
        }

        vector<pair<string, int> > transfer;
        for(map<string, int>::iterator it = course.begin(); it != course.end(); it++){
            transfer.push_back(make_pair(it->first, it->second));
        }

        sort(transfer.begin(), transfer.end(), sortByVal);
        int num = transfer[0].second, sum = 0;
        for(int i = 0; i < transfer.size(); i++){
            if(transfer[i].second == num) sum += transfer[i].second;
            else break;
        }
        cout << sum << "\n";
    }
}

bool sortByVal(pair<string, int> &a, 
               pair<string, int> &b){ 
    return (a.second > b.second); 
} 