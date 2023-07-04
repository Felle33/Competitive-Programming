#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <cstring>
#include <unordered_map>

typedef long long ll;
using namespace std;

void solve(){
    vector<string> cows(8);
    cows[0] = "Beatrice";
    cows[1] = "Belinda";
    cows[2] = "Bella";
    cows[3] = "Bessie";
    cows[4] = "Betsy";
    cows[5] = "Blue";
    cows[6] = "Buttercup";
    cows[7] = "Sue";

    int n;
    cin >> n;

    vector<vector<int>> graph(8);
    vector<int> constraints(8);

    for(int i = 0; i < n; i++){
        string a, b;
        int end;
        cin >> a;
        for(int i = 0; i < 8; i++){
            if(cows[i] == a){
                end = i;
                break;
            }
        }

        cin >> a >> a >> a >> a >> b;

        for(int i = 0; i < 8; i++){
            if(cows[i] == b){
                constraints[i]++;
                graph[i].push_back(end);
                break;
            }
        }
    }

    for(int i = 0; i < 8; i++){
        if(constraints[i] == 0){
            cout << cows[i] << '\n';
            
        }
    }
}

int main(){
    /* freopen("lineup.in", "r", stdin);
	freopen("lineup.out", "w", stdout); */
    solve();
} 