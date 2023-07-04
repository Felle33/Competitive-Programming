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

vector<ll> nums;
int n, k;

bool good(ll maximumSum){
    ll segs = 1;
    ll curSum = 0;
    int j = 0;

    for(int i = 0; i < n; i++){
        if(curSum + nums[i] > maximumSum){
            curSum = nums[i];
            segs++;
        }
        else{
            curSum += nums[i];
        }
    }

    return segs <= k;
}

void solve(){
    cin >> n >> k;

    nums.resize(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    ll l = *max_element(all(nums)), r = l;

    while(!good(r)) r *= 2;

    while(l + 1 < r){
        ll mid = l + (r - l) / 2;

        if(good(mid)){
            r = mid;
        }
        else{
            l = mid;
        }
    }

    cout << setprecision(10) << r << '\n';
}

int main(){
    /* freopen("lifeguards.in", "r", stdin);
	freopen("lifeguards.out", "w", stdout); */
    solve();
} 