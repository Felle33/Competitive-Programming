#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <cstring>

#define endl '\n'

using namespace std;

void solve(){
    int k, n;
    cin >> k >> n;
    int jump = 1, number = 1;

    for(int i = 0; i < k; i++){
        cout << number << " ";
        if(n - (number + jump) >= (k - i - 1)){
            number += jump;
            jump++;
        }
        else{
            number++;
        }
        
    }

    cout << endl;
}

int main(){
    int t;
    cin >> t;

    while(t--){
        solve();
    }
}