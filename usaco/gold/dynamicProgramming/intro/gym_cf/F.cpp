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

void calc_pyramids(vector<int>& pyramids) {
    pyramids.push_back(1);

    for(int total = 1, new_line = 2, last_pyramid = 1; total <= 300000;) {
        pyramids.push_back(total + last_pyramid + new_line);
        total += last_pyramid + new_line;
        last_pyramid = last_pyramid + new_line;
        new_line++;
    }
}

void solve(){
    int n;
    cin >> n;

    vector<int> tests(n);
    rep(i, n) {
        cin >> tests[i];
    }
    int max_in = *max_element(all(tests));
    vector<int> min_canballs(max_in + 1, 1e6);
    vector<int> pyramids;
    calc_pyramids(pyramids);
    min_canballs[0] = 0;

    for(int ball = 1; ball <= max_in; ball++) {
        for (int pyr : pyramids) {
            if(pyr <= ball) {
                min_canballs[ball] = min(min_canballs[ball], min_canballs[ball - pyr] + 1);
            }
        }
    }

    for(int test : tests) {
        cout << min_canballs[test] << '\n';
    }
}

int main(){
    //freopen("slalom.in", "r", stdin);
	//freopen("slalom.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
}

/*
5
1
5
9
15
91
*/
