#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <cstring>

typedef long long ll;
using namespace std;

void solve(){
    int n;
    cin >> n;
    char c;
    cin >> c;
    int runningSum = c == '0' ? 0 : 1;

    for(ll i = 1; i < n; i++){
        cin >> c;
        
        if(c == '0'){
            cout << '+';
        }
        else{
            if(runningSum > 0){
                cout << '-';
                runningSum--;
            }
            else{
                cout << '+';
                runningSum++;
            }
        }
    }
    cout << '\n';
}

int main(){
    int t;
    cin >> t;

    while(t--){
        solve();
    }
}