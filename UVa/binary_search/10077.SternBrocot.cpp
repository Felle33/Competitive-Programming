#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <cstring>
#include <map>
#include <set>
#include <iomanip>
#include <bitset>

#define all(x) (x).begin(), (x).end()
#define mp make_pair
#define pb push_back
#define rep(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define reps(X,S,Y) for (int (X) = S;(X) < (Y);++(X))

using namespace std;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<unsigned long long> vull;
typedef vector<vector<int>> vvi;
typedef long long ll;
typedef pair<int,int> pii;

const ll MOD1 = 1e9 + 7;
const ll MOD2 = 998244353;
const ll MOD3 = 99999999999999997;
const ll DIM = 1e6;
const int INF = 1e9;
const ll LLINF = 1e15;
const int INF_INT = 1e9;
const ll LL_MAX = 9223372036854775807;
const int LOG = 22;
vector<int> DX = {0, 1, -1, 0};
vector<int> DY = {1, 0, 0, -1};
string DIR = "RDUL";

ll a, b;
pair<ll, ll> node, leftNode, rightNode;

void sternBrocot() {
    if(node.first == a && node.second == b) return;

    if(a * node.second < node.first * b) {
        cout << "L";
        rightNode = node;
        node.first = leftNode.first + node.first;
        node.second = leftNode.second + node.second;
        sternBrocot();
        return;
    }
    cout << "R";
    leftNode = node;
    node.first = rightNode.first + node.first;
    node.second = rightNode.second + node.second;
    sternBrocot();
}

void solve(){
    while(1) {
        cin >> a >> b;
        if(a == 1 && b == 1) break;
        node = {1, 1};
        leftNode = {0, 1};
        rightNode = {1, 0};

        sternBrocot(); 
        cout << '\n';
    }
        
}

int main(){
    solve();
}