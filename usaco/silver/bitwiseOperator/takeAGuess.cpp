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

vector<int> nums;

int ask(int i1, int i2){
    cout << "and " << i1 << " " << i2;
    cout << endl << flush;
    
    int andRes, orRes;
    cin >> andRes;

    cout << "or " << i1 << " " << i2;
    cout << endl << flush;

    cin >> orRes;

    int xorRes = orRes & ~(andRes);
    return 2 * andRes + xorRes;
}

void solve(){
    int n, k;
    cin >> n >> k;

    nums.resize(n);

    int x = ask(1, 2); // x
    int y = ask(1, 3); // y
    int z = ask(2, 3); // z

    int b = (x - y + z) / 2;
    nums[0] = x - b;
    nums[1] = b;
    nums[2] = z - b;

    for(int i = 4; i <= n; i++){
        int res = ask(2, i);
        nums[i - 1] = res - b;
    }

    sort(all(nums));

    cout << "finish " << nums[k - 1];
    cout << endl << flush;
}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);

    solve();
}