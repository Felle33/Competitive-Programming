#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <cstring>
#include <unordered_map>
#include <map>
#include <set>
#include <stack>

#define all(x) (x).begin(), (x).end()

typedef long long ll;
using namespace std;

void solve(){
    int n, x;
    cin >> n;

    vector<int> nums(n);
    vector<int> result(n, -1);
    stack<int> s;
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    s.push(nums[0]);
    for(int i = 1; i < n; i++){
        while(!s.empty() && s.top() > nums[i]){
            s.pop();
        }

        result[i] = s.empty() ? -1 : s.top();
        s.push(nums[i]);
    }

    for(int i = 0; i < n; i++){
        cout << result[i] << " ";
    }
    cout << '\n';
}

int main(){
    /* freopen("bcount.in", "r", stdin);
	freopen("bcount.out", "w", stdout); */
    solve();
} 