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
    int n;
	cin >> n;

    vector<int> nums(n);

    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    sort(all(nums));

    int k;
    cin >> k;

    while(k--){
        int a, b;
        cin >> a >> b;

        int l = -1, r = n;
        while(l + 1 < r){
            int mid = l + (r - l) / 2;

            if(nums[mid] >= a){
                r = mid;
            }
            else{
                l = mid;
            }
        }

        int r1 = r;

        l = -1, r = n;
        while(l + 1 < r){
            int mid = l + (r - l) / 2;

            if(nums[mid] <= b){
                l = mid;
            }
            else{
                r = mid;
            }
        }

        int r2 = l;

        cout << r2 - r1 + 1 << " ";
    }
}

int main(){
    /* freopen("lifeguards.in", "r", stdin);
	freopen("lifeguards.out", "w", stdout); */
    solve();
} 