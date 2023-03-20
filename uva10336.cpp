#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

/*
(1) DFS: "boundary" situation
(2) sort pair vector
*/

void DFS(int x, int y, vector<vector<char> >& data, vector<vector<bool> >& visited);
bool cmp(pair<char, int>& a, pair<char, int>& b);
bool cmp2(pair<char, int>& a, pair<char, int>& b);


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    while(cin >> n){
        for(int i = 0; i < n; i++){
            int h, w;
            cin >> h >> w;
            vector<vector<char> > data(h, vector<char>(w));
            vector<vector<bool> > visited(h, vector<bool>(w));
            for(int j = 0; j < h; j++){
                for(int k = 0; k < w; k++){
                    cin >> data[j][k];
                    visited[j][k] = false;
                }
            }

            vector<pair<char, int> > type;
            for(int j = 0; j < h; j++){
                for(int k = 0; k < w; k++){
                    if(!visited[j][k]){
                        DFS(j, k, data, visited);
                        bool exist = false;
                        for(int l = 0; l < type.size(); l++){
                            if(type[l].first == data[j][k]){
                                type[l].second ++;
                                exist = true;
                            }
                        }
                        if(!exist){
                            type.push_back(make_pair(data[j][k], 1));
                        }
                    }
                }
            }

            cout << "World #" << i + 1 << "\n";
            sort(type.begin(), type.end(), cmp2);
            sort(type.begin(), type.end(), cmp);
            for(int j = 0; j < type.size(); j++){
                cout << type[j].first << ": " << type[j].second << "\n";
            }

        }
    }
}

void DFS(int x, int y, vector<vector<char> >& data, vector<vector<bool> >& visited){
    visited[x][y] = 1;
    if((x + 1) < data.size()) if(data[x+1][y] == data[x][y] && !visited[x+1][y] ) DFS(x+1, y, data, visited);
    if((x - 1) >= 0) if(data[x-1][y] == data[x][y] && !visited[x-1][y] ) DFS(x-1, y, data, visited);
    if((y + 1) < data[0].size()) if(data[x][y+1] == data[x][y] && !visited[x][y+1] ) DFS(x, y+1, data, visited);
    if((y - 1) >= 0) if(data[x][y-1] == data[x][y] && !visited[x][y-1] ) DFS(x, y-1, data, visited);
}

bool cmp(pair<char, int>& a, pair<char, int>& b){
    return a.second > b.second;
}

bool cmp2(pair<char, int>& a, pair<char, int>& b){
    return a.first < b.first;
}