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
    vector<int> nums(n + 1);
    int ex = 0;
    
    for(int i = 1; i <= n; i++){
        cin >> nums[i];
        if((nums[i] - i) % k != 0){
            ex++;
        }
    }

    if(ex == 0){
        cout << 0 << '\n';
    } else if(ex == 2){
        cout << 1 << '\n';
    } else{
        cout << -1 << '\n';
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