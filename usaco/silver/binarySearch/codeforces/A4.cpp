#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <cstring>
#include <unordered_map>
#include <map>
#include <set>

#define all(x) (x).begin(), (x).end()

typedef long long ll;
using namespace std;

int n, d;
vector<double> nums;
int ansL, ansR;

bool good(double mean){
    vector<double> copy(n);
    vector<double> pref(n + 1);

    for(int i = 0; i < n; i++){
        copy[i] = nums[i] - mean;
    }
    
    pref[0] = 0;
    for(int i = 1; i <= n; i++){
        pref[i] = pref[i - 1] + copy[i - 1];
    }

    double mi = 0, index = 0;
    for(int r = d; r <= n; r++) {
        if(mi > pref[r - d]) {
            index = r - d;
            mi = pref[r - d];
        }

        if(pref[r] - mi >= 0) {
            ansL = index + 1, ansR = r;
            return true;
        }
    }

    return false;
}

void solve(){
    cin >> n >> d;
    nums.resize(n);
    
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    double l = -1, r = 200;

    for(int i = 0; i < 100; i++){
        double mid = l + (r - l) / 2;
        if(good(mid)){
            l = mid;
        } else {
            r = mid;
        }
    }

    cout << ansL << " " << ansR << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout.precision(10);
    cout << std::fixed;

    solve();
} 