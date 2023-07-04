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

void solve(){
    int n, k;
    cin >> n >> k;

    vector<int> stack(n);

    for(int i = 0; i < k; i++){
        int a, b;
        cin >> a >> b;
        a--, b--;

        stack[a]++;
        stack[b + 1]--;
    }

    vector<int> nums(n);
    int curSum = 0;

    for(int i = 0; i < n; i++){
        curSum += stack[i];
        nums[i] = curSum;
    }

    sort(all(nums));

    cout << nums[n / 2] << '\n';
}

int main(){
    /* freopen("maxcross.in", "r", stdin);
	freopen("maxcross.out", "w", stdout); */
    solve();
} 