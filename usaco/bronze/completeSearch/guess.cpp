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

    set<string> characteristics;
    vector<set<string>> animals(n);

    for(int i = 0; i < n; i++){
        int k;
        cin >> k;

        while(k--){
            string c;
            cin >> c;
            animals[i].insert(c);
            characteristics.insert(c);
        }
    }

    int ans = 0;

    for(auto it1 = characteristics.begin(); it1 != characteristics.end(); it1++){
        for(auto it2 = characteristics.begin(); it2 != characteristics.end(); it2++){
            if(it1 == it2)
        }
    }


}

int main(){
    /* freopen("lifeguards.in", "r", stdin);
	freopen("lifeguards.out", "w", stdout); */
    solve();
} 