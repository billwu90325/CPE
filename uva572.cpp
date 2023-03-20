#include <iostream>
#include <vector>
using namespace std;

/*
floodfill problem(classify)
    -> implement with recursion
*/

void floodfill(vector<vector<char> >& map,
               vector<vector<int>  >& id_table,
               int row, int col, int id);

int main(){
    int m, n;
    while(cin >> m >> n){
        if(m == 0 && n == 0) break;
        vector<vector<char> > map(m, vector<char>(n));
        vector<vector<int> > id_table(m, vector<int>(n, 0));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                cin >> map[i][j];
            }
        }

        int id = 1;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j ++){
               if(map[i][j] == '@' && id_table[i][j] == 0){
                   floodfill(map, id_table, i, j, id);
                   id ++;
               }
            }
        }
        cout << id - 1 << endl;
    }
}

void floodfill(vector<vector<char> >& map,
               vector<vector<int>  >& id_table,
               int row, int col, int id){
   if(row < 0 || (row >= map.size()) )   return;
   if(col < 0 || (col >= map[0].size())) return;
   if(map[row][col] != '@' || id_table[row][col] > 0) return;

   id_table[row][col] = id;
   floodfill(map, id_table, row-1, col-1, id);
   floodfill(map, id_table, row-1, col,   id);
   floodfill(map, id_table, row-1, col+1, id);
   floodfill(map, id_table, row,   col-1, id);
   floodfill(map, id_table, row,   col+1, id);
   floodfill(map, id_table, row+1, col-1, id);
   floodfill(map, id_table, row+1, col,   id);
   floodfill(map, id_table, row+1, col+1, id);
}