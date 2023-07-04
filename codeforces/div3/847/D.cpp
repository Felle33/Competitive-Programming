#include <algorithm>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

void solve(){
    int n, res = 0;
    cin >> n;
    vector<int> dolls(n);
    map<int, int> cnt;

    for(size_t i = 0; i < n; i++){
        cin >> dolls[i];
        cnt[dolls[i]]++;
    }

    sort(dolls.begin(), dolls.end());

    for(size_t i = 0; i < n; i++){
        if(cnt[dolls[i]] > 0){
            int number = dolls[i];

            while(cnt[number] > 0){
                cnt[number]--;
                number++;
            }
            res++;
        }
    }

    cout << res << endl;
}

int main(){
    int t;
    cin >> t;

    while(t--){
        solve();
    }
}