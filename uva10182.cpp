#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<int> table;
    table.push_back(1);
    for(int i = 1; ; i++){
        table.push_back(table[i - 1] + i * 6);
        if(table[i] > 100000) break;
    }

	vector<pair<int,int> > table_sum;
	table_sum.push_back(make_pair(0,-1));
	table_sum.push_back(make_pair(-1,0));
	table_sum.push_back(make_pair(-1,1));
	table_sum.push_back(make_pair(0,1));
	table_sum.push_back(make_pair(1,0));
	table_sum.push_back(make_pair(1,-1));

    //cout << table.size() << "\n";
    int n;
    while(cin >> n){
        int round;
        int ceil = 0;
        for(int i = 0; i < table.size(); i++){
            if(table[i] >= n){
                round = i;
                ceil = table[i];
                break;
            }
        }
        if(round == 0){
            cout << "0 0\n";
            continue;
        }

        int diff = ceil - n;
        int count = diff / round;
        int rest = diff % round;

		int x = round, y = 0;
		for(int i = 0; i < count; i++){
			x += table_sum[i].first * round;
			y += table_sum[i].second * round;
		}
	
    	x += table_sum[count].first * rest;
		y += table_sum[count].second * rest;
        cout << x << " " << y << "\n";
    }
}