#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <cstring>

typedef long long ll;
using namespace std;

void solve()
{
    int n, c;
    cin >> n >> c;
    vector<pair<int, int>> a;

    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a.push_back({x + min(i + 1, n - i), x + i + 1});
    }

    sort(a.begin(), a.end());
    vector<ll> pref;
    pref.push_back(0);
    for(int i = 0; i < n; i++)
    {
        pref.push_back(pref.back() + a[i].first);
    }
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        int new_c = c - a[i].second;
        int l = 0, r = n;
        int mx = 0;
        while(l <= r)
        {
            int mid = l+r>>1;
            // Calculate price
            ll price = pref[mid];
            int now = mid + 1;

            if(mid > i)
            {
                price -= a[i].first;
                now--;
            }

            if(price <= new_c)
            {
                mx = max(now, mx);
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        ans = max(ans, mx);
    }
    cout << ans << endl;
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