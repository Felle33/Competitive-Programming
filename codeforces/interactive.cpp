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
    int l = 1, r = 1e6 + 1;
    string res;

    while(l + 1 < r){
        int m = l + (r - l) / 2;

        cout << m << endl;
        cin >> res;

        if(res == "<"){
            r = m;
        }
        else{
            l = m;
        }
    }

    cout << "! " << l << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
}