#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <cstring>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <stack>

#define all(x) (x).begin(), (x).end()

typedef long long ll;
using namespace std;

void solve(){
    int n, m;
    cin >> n;
    string pokemon;
    cin >> pokemon;

    unordered_set<char> types;
    for(char c : pokemon){
        types.insert(c);
    }

    int totalTypes = types.size();
    for(int l = 0, r = 0; r < n; r++){
        
    }
}

int main(){
    /* freopen("bcount.in", "r", stdin);
	freopen("bcount.out", "w", stdout); */
    solve();
} 