// NOTE: it is recommended to use this even if you don't understand the following code.

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void concatenate(int x, char s, string& res) {
    for(int i = 0; i < x; i++) {
        res += s;
    }
}

int main() {
    // uncomment the two following lines if you want to read/write from files
    // ifstream cin("input.txt");
    // ofstream cout("output.txt");

    int n;
    cin >> n;
    
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    
    string ans = "";
    
    
    // INSERT YOUR CODE HERE
    int max_brackets = 0;
    for(int i = 0; i < n; i++) max_brackets += a[i];
    vector<vector<int>> dp(n + 1, vector<int>(max_brackets + 1));
    dp[n][0] = 1;
    for(int i = 1; i <= max_brackets; i++) dp[n][i] = -1;

    for(int i = n - 1; i >= 0; i--) {
        for(int j = max_brackets - a[i]; j >= 0; j--) {
            if(dp[i + 1][j + a[i]] != -1) {
                dp[i][j] = 1;
            } else if(j - a[i] >= 0 && dp[i + 1][j - a[i]] != -1) {
                dp[i][j] = 2;
            } else {
                dp[i][j] = -1;
            }
        }
    }

    if(dp[0][0] == -1) {
        cout << -1 << '\n';
        return 0;
    }

    int start = 0;
    int open_par = 0;

    while(start != n) {
        if(dp[start][open_par] == 1) {
            open_par += a[start];
            concatenate(a[start], '(', ans);
        } else {
            open_par -= a[start];
            concatenate(a[start], ')', ans);
        }
        start++;
    }
    
    cout << ans << endl;

    return 0;
}
