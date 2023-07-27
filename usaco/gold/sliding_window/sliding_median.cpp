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

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

const ll MOD = 1e9 + 7;
const ll DIM = 1e6;
const ll INF = 1e9;
vector<int> DX = {0, 1, -1, 0};
vector<int> DY = {1, 0, 0, -1};
string DIR = "RDUL";

multiset<ll> lower, upper;

void control() {
    if(lower.size() != upper.size() && lower.size() != upper.size() + 1) {
        if(lower.size() > upper.size()) {
            upper.insert(*lower.rbegin());
            lower.erase(--lower.end());
        } else {
            lower.insert(*upper.begin());
            upper.erase(upper.begin());
        }
    }
}

void insert(int x) {
    if(lower.empty() && upper.empty()) {
        lower.insert(x);
        return;
    }

    // max di lower è minore di x
    if(*lower.rbegin() < x) {
        upper.insert(x);
    } else {
        // max di lower è maggiore di x
        lower.insert(x);
    }

    control();
}

void erase(int x) {
    // max di lower è minore di x
    if(x <= *lower.rbegin()) {
        lower.erase(lower.find(x));
    } else {
        // max di lower è maggiore di x
        upper.erase(upper.find(x));
    }

    control();
}

void solve(){
    int n, k;
    cin >> n >> k;

    vector<ll> nums(n);
    rep(i, n) {
        cin >> nums[i];
    }

    for(int r = 0, l = 0; r <= n; r++) {
        if(r >= k) {
            cout << *lower.rbegin() << " ";
            erase(nums[l++]);
        }
        
        if(r < n)
            insert(nums[r]);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    solve();
}