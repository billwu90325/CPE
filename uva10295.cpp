#include <iostream>
#include <map>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int m, n;
    while(cin >> m >> n){
        map<string, int> data;
        for(int i = 0; i < m; i ++){
            string name;
            int point;
            cin >> name >> point;
            data[name] = point;
        }

        for(int i = 0 ; i < n; i++){
            string sentence;
            int sum = 0;
            while(cin >> sentence && sentence != "."){
                sum += data[sentence];
            }
            cout << sum << "\n";
        }
    }
}