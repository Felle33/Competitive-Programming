#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <cstring>
#include <unordered_map>
#include <set>

typedef long long ll;
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<vector<pair<string, int>>> meas(101);
    vector<string> cows = {"Bessie", "Elsie", "Mildred"};

    for(int i = 0; i < n; i++){
        int day, diff;
        string c;

        cin >> day >> c >> diff;

        meas[day].push_back({*find(cows.begin(), cows.end(), c), diff});
    }

    vector<pair<string, int>> milk = {{"Bessie", 7}, {"Elsie", 7}, {"Mildred", 7}};
    set<string> podium = {"Bessie", "Elsie", "Mildred"};
    int ans = 0;

    for(int i = 1; i < 101; i++){

        for(pair<string, int> p : meas[i]){
            int index = distance(cows.begin(), find(cows.begin(), cows.end(), p.first));
            milk[index].second += p.second;
        }

        int maxMilk = 0;
        int maxMilkIndex;

        for(int j = 0; j < 3; j++){
            if(milk[j].second > maxMilk){
                maxMilk = milk[j].second;
                maxMilkIndex = j;
            }
        }

        set<string> newPodium;
        for(int j = 0; j < 3; j++){
            if(maxMilk == milk[j].second){
                newPodium.insert(milk[j].first);
            }
        }

        if(newPodium != podium){
            podium = newPodium;
            ans++;
        }

    }

    cout << ans << '\n';
}

int main(){
    freopen("measurement.in", "r", stdin);
	freopen("measurement.out", "w", stdout);
    solve();
} 