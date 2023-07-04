#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <cstring>
#include <unordered_map>
#include <map>
#include <set>
#include <iomanip>

#define all(x) (x).begin(), (x).end()

typedef long long ll;
using namespace std;

const ll MOD = 1e9 + 7;
const ll DIM = 1e6;
const ll INF = 1e9;
vector<int> DX = {0, 1, -1, 0};
vector<int> DY = {1, 0, 0, -1};
string DIR = "RDUL";

void solve(){
    int n, k;
    cin >> n >> k;

    int ones = n, minusOnes = 0;
    bool accept = false;
    for(; ones >= 0; ones--, minusOnes++){
        if(ones * (ones - 1) / 2 + minusOnes * (minusOnes - 1) / 2 == k){
            accept = true;
            break;
        }
    }

    if(accept){
        cout << "YES" << '\n';
        for(int i = 0; i < ones; i++){
            cout << 1 << " ";
        }

        for(int i = 0; i < minusOnes; i++){
            cout << -1 << " ";
        }
        cout << '\n';
    } else{
        cout << "NO" << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        solve();
    }
}