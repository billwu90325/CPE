#include <iostream>
using namespace std;

/*
(1) handle "EOF" situation
*/

int main(){
    int a, b;
    while(scanf("%d %d", &a, &b) != EOF){
        int maxlen = 0;
        for(int i = min(a, b); i <= max(a, b); i++){
            int num = i;
            int current = 1;
            while(num != 1){
                if(num % 2 == 0) num /= 2;
                else num = (3 * num) + 1;
                current ++;
            }
            if(current > maxlen) maxlen = current;
        }
        printf("%d %d %d\n", a, b, maxlen);
    }
}