#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

void solve(){
    int n;
    cin >> n;

    vector<vector<int>> total(n, vector<int>(n - 1));
    vector<bool> seen(n + 1);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n - 1; j++){
            cin >> total[i][j];
        }
    }

    int n1 = total[0][0];
    int n2 = total[1][0];
    
    if(n1 == n2){
        seen[n1] = true;
        cout << n1 << " ";

        for(int j = 2; j < n; j++){
            if(!seen[total[j][0]]){
                seen[total[j][0]] = true;
                cout << total[j][0] << " ";
                break;
            }
        }
    }
    else{
        seen[n1] = true;
        seen[n2] = true;

        if(total[2][0] == n1){
            cout << n1 << " " << n2 << " ";
        }
        else{
            cout << n2 << " " << n1 << " ";
        }
    }

    for(int i = 1; i < n - 1; i++){
        for(int j = 0; j < n; j++){
            if(!seen[total[j][i]]){
                seen[total[j][i]] = true;
                cout << total[j][i] << " ";
                break;
            }
        }
    }

    cout << endl;
}

int main(){
    int t;
    cin >> t;

    while(t--){
        solve();
    }
}