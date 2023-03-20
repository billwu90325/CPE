#include <iostream>
#include <vector>
#include <string>
#include <cctype>
using namespace std;

/*
(1) isalpha()
(2) isdigit()
(3) getline(cin, buffer)
(4) include <cctype>
(5) string[index] -> char
(6) vector.erase(*)
*/

int main(){
    vector<string> word_list;
    string buffer;
    while(true){
        getline(cin, buffer);
        string s;
        if(buffer[0] != '0'){
            for(int i = 0; i < buffer.size(); i++){
                if(isalpha(buffer[i])){
                    s = "";
                    while(isalpha(buffer[i])){
                        s += buffer[i];
                        i ++;
                    }
                    word_list.push_back(s);
                    i --;
                    cout << s;
                }else if(isdigit(buffer[i])){
                    int value = 0;
                    while(isdigit(buffer[i])){
                        value = value * 10 + (buffer[i] - '0');
                        i ++;
                    }
                    s = word_list[word_list.size() - value];
                    word_list.erase(word_list.end() - value);
                    word_list.push_back(s);
                    i --;
                    cout << s;
                }else{
                    cout << buffer[i]; 
                }
            } 
        }else{
            break;
        }
        cout << "\n";
    }
    return 0;
}