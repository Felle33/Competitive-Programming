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
#define rep(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define reps(X,S,Y) for (int (X) = S;(X) < (Y);++(X))

typedef long long ll;
using namespace std;

const ll MOD = 1e9 + 7;
const ll DIM = 1e6;
const ll INF = 1e9;
vector<int> DX = {0, 1, -1, 0};
vector<int> DY = {1, 0, 0, -1};
string DIR = "RDUL";

void solve(){
    int n;
    cin >> n;

    vector<int> nums(n);

    rep(i, n){
        cin >> nums[i];
    }

    int x = 0;
    reps(i, 1, n){
        if(nums[i] < nums[i - 1]){
            int dif = nums[i - 1] - nums[i];
            x = max(x, dif);
            nums[i] = nums[i - 1];
        }
    }

    int index = 0;
    if(x != 0){
        index = (int) floor(log2(x)) + 1;
    }
    
    cout << index << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--)
    solve();
}