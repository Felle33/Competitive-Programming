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
#define mp make_pair
#define rep(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define reps(X,S,Y) for (int (X) = S;(X) < (Y);++(X))

using namespace std;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<unsigned long long> vull;
typedef vector<vector<int>> vvi;
typedef long long ll;
typedef pair<int,int> pii;

const ll MOD = 1e9 + 7;
const ll DIM = 1e6;
const ll INF = 1e15;
vector<int> DX = {0, 1, -1, 0};
vector<int> DY = {1, 0, 0, -1};
string DIR = "RDUL";

ll binExp(ll b, ll e){
    ll res = 1;
    while(e > 0){
        if(e & 1)
            res = res * b;
        
        b = b * b;
        e >>= 1;
    }

    return res;
}

void solve(){
    ll n; cin >> n;
    ll posti = 2 * n - 2;
    ll postiLiberi = posti - n;

    ll sum = 2 * 3 * binExp(4, postiLiberi - 1);
    for(int i = 0; i < postiLiberi - 1; i++) {
        sum += 3 * 3 * binExp(4, postiLiberi - 2);
    }

    sum *= 4;
    cout << sum << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    solve();
}