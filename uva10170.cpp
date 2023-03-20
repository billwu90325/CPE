#include <iostream>
using namespace std;
#define ll long long

/*
sometimes interger cause error -> long long
*/

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll s, d;
    while(cin >> s >> d){
        ll diff = s - 1;
        ll offset = ((1 + diff) * diff) / 2;
        ll target = offset + d;

        for(ll i = 1; ; i++){
            ll ceil = ((1 + i) * i) / 2;
            if(ceil >= target){
                cout << i << "\n";
                break;
            }
        }
    }
}