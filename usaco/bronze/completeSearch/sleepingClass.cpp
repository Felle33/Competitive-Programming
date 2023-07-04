#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <cstring>
#include <unordered_map>
#include <map>
#include <set>

typedef long long ll;

using namespace std;

void solve(){
    int n;
    cin >> n;

    vector<int> elsieLog(n);
    ll sum = 0;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        elsieLog[i] = x;
        sum += x;
    }

    for(int hours = 0; hours <= sum; hours++){
        if(hours != 0 && sum % hours != 0) continue;

        int curSum = 0;
        bool valid = true;
        for(int i = 0; i < n; i++){
            curSum += elsieLog[i];

            if(curSum > hours){
                valid = false;
                break;
            } else if(curSum == hours){
                curSum = 0;
            }
        }

        if(valid){
            if (hours == 0) {
                // Handle the edge case where num_hours is 0
                cout << 0 << '\n';
            } else {
                // sum/num_hours is the total # of classes AFTER modifying
                cout << n - sum / hours << '\n';
            }
            break;
        }
    }
}

int main(){
    /* freopen("cownomics.in", "r", stdin);
	freopen("cownomics.out", "w", stdout); */
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        solve();
    }
} 