#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <sstream>
using namespace std;

struct Node{
	string c;
    map<string, int> next;
    Node(){
    	next.clear();
    }
    void init(string s) {
    	c = s;
    	next.clear();
    }
};
struct Node nodes[1048576];
int TrieSize = 0;
void insertTrie(vector<string> s);
void dfs(int u, int depth);

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    string s;
    while(cin >> n){
		nodes[0].init("");
		TrieSize = 0;
        for(int i = 0; i < n; i++){
            cin >> s;
            for(int j = 0; j < s.size(); j++){
                if(s[j] == '\\') s[j] = ' ';
            }
            vector<string> pwd;
            stringstream ss(s);
            string buffer;
            while(ss >> buffer) pwd.push_back(buffer);
            insertTrie(pwd);
        }
        dfs(0, 0);
        puts("");
        //cout << "\n";
    }
}

void insertTrie(vector<string> s){
	int p = 0;
	for(int i = 0; i < s.size(); i++){
		if(nodes[p].next.find(s[i]) == nodes[p].next.end()){
			nodes[++TrieSize].init(s[i]);
			nodes[p].next[s[i]] = TrieSize;
		}
		p = nodes[p].next[s[i]];
	}
}

void dfs(int u, int depth){
	if(u){
		for(int i = 1; i < depth; i++){
            cout << " ";
        }
		printf("%s\n", nodes[u].c.c_str());
	}
	for(map<string, int>::iterator it = nodes[u].next.begin(); it != nodes[u].next.end(); it++){
        dfs(it->second, depth + 1);
    }
}
