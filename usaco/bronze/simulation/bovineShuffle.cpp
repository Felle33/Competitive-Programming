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
    int n;
    cin >> n;

    vector<int> mp(n);
    for(int i = 0; i < n; i++){
        cin >> mp[i];
    }

    vector<string> cowsFinal(n);
    for(int i = 0; i < n; i++){
        cin >> cowsFinal[i];
    }

    vector<string> cowsInitial(n);
    for(int i = 0; i < n; i++){
        int j = 3;
        int numberToFind = i + 1;

        while(j--){
            for(int k = 0; k < n; k++){
                if(mp[k] == numberToFind){
                    numberToFind = k + 1;
                    break;
                }
            }
        }

        cowsInitial[numberToFind - 1] = cowsFinal[i];
    }

    for(int i = 0; i < n; i++){
        cout << cowsInitial[i] << '\n';
    }
}

int main(){
    freopen("shuffle.in", "r", stdin);
	freopen("shuffle.out", "w", stdout);
    solve();
} 