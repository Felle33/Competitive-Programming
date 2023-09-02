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

    vector<int> num(n);

    for(int i = 0; i < n; i++){
        cin >> num[i];
    }

    for(int i = 0; i < k; i++){
        int x;
        cin >> x;

        int l = 0, r = n;
        bool ok = false;
        while(l <= r){
            int mid = l + (r - l) / 2;
            if(x == num[mid]){
                ok = true;
                break;
            }
            else if(num[mid] > x){
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }

        if(ok){
            cout << "YES" << '\n';
        }
        else{
            cout << "NO" << '\n';
        }
    }
}

int main(){
    /* freopen("lifeguards.in", "r", stdin);
	freopen("lifeguards.out", "w", stdout); */
    solve();
} 