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

    vector<int> nums(n);

    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    for(int i = 0; i < k; i++){
        int x;
        cin >> x;

        int l = -1, r = n;
        while(l + 1 < r){
            int mid = l + (r - l) / 2;

            if(nums[mid] <= x){
                l = mid;
            }
            else{
                r = mid;
            }
        }

        cout << l + 1 << '\n';
    }
}

int main(){
    /* freopen("lifeguards.in", "r", stdin);
	freopen("lifeguards.out", "w", stdout); */
    solve();
} 