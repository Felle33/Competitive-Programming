#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <cstring>
#include <unordered_map>
#include <map>
#include <set>
#include <stack>

#define all(x) (x).begin(), (x).end()

typedef long long ll;
using namespace std;

void solve(){
    int n, t;
    cin >> n >> t;

    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    int l = 0, r = 0;
    int curSum = 0;
    int ans = 0;
    for(; r < n; r++){
        curSum += nums[r];

        while(curSum > t){
            curSum -= nums[l++];
        }

        ans = max(ans, r - l + 1);
    }

    cout << ans << '\n';
}

int main(){
    /* freopen("bcount.in", "r", stdin);
	freopen("bcount.out", "w", stdout); */
    solve();
} 