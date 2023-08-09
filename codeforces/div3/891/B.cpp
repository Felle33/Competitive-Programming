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

void solve(){
    string s;
    cin >> s;

    int size = s.size();
    vector<bool> op(size, false);
    bool newCif = false;
    for(int i = s.size() - 1; i >= 0;) {
        if(s[i] >= '5' && s[i] <= '9') {
            op[i] = true;
            int j = i;
            while(j >= 0 && s[j] == '9') {
                s[j] = '0';
                j--;
            }

            if(j >= 0) {
                s[j] += 1;
            } else {
                s.insert(0, "1");
                newCif = true;
            }
            i = j;
        } else {
            i--;
        }
    }

    if(newCif) {
        for(int j = 1; j < (int) s.size(); j++) {
            s[j] = '0';
        }
    } else {
        for(int i = 0; i < (int) s.size(); i++) {
            if(op[i]) {
                for(int j = i + 1; j < (int) s.size(); j++) {
                    s[j] = '0';
                }
                break;
            }
        }
    }
    
    cout << s << '\n';
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