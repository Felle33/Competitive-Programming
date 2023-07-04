#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <cstring>
#include <set>

typedef long long ll;
using namespace std;

int digit_sum(int n){
    int res = 0;
    while(n > 0){
        res += n % 10;
        n /= 10;
    }

    return res;
}

void solve(){
    int n, q;
    cin >> n >> q;

    vector<int> arr(n);
    set<int> numbers;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        if(arr[i] > 9){
            numbers.insert(i);
        }
    }

    while(q--){
        int o;
        cin >> o;

        if(o == 1){
            int l, r;
            cin >> l >> r;
            l--;
            r--;

            while(!numbers.empty()){
                auto it = numbers.lower_bound(l);
                if(it == numbers.end() || *it > r) break;

                arr[*it] = digit_sum(arr[*it]);
                int paiu = *it;

                if(arr[*it] <= 9) numbers.erase(it);
                l = paiu + 1;
            }
        }
        else{
            int x;
            cin >> x;
            x--;
            cout << arr[x] << '\n';
        }
    }
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