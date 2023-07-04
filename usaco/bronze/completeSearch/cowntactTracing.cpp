#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <cstring>
#include <unordered_map>
#include <map>
#include <set>

#define all(x) (x).begin(), (x).end()

typedef long long ll;

using namespace std;

bool equals(vector<bool>& v1, vector<bool>& v2){
    int n = v1.size();
    for(int i = 0; i < n; i++){
        if(v1[i] != v2[i]) return false;
    }
    return true;
}

void solve(){
    int n, m;
    cin >> n >> m;

    string infectString;
    cin >> infectString;

    vector<bool> infect(n);
    for(int i = 0; i < n; i++){
        infect[i] = (infectString[i] == '1');
    }

    vector<tuple<int, int, int>> contacts(m);
    for(int i = 0; i < m; i++){
        int t, x, y;
        cin >> t >> x >> y;
        x--, y--;
        contacts[i] = make_tuple(t, x, y);
    }

    sort(all(contacts));
    vector<bool> infectionSimulation(n);
    vector<int> shakesAfterInfection(n);
    int minK = 251, maxK = -1;
    int numberOfPatienteZero = 0;

    for(int patient_zero = 0; patient_zero < n; patient_zero++){
        bool valid = false;
        for(int k = 0; k <= 251; k++){
            fill(all(infectionSimulation), false);
            fill(all(shakesAfterInfection), 0);
            infectionSimulation[patient_zero] = true;

            for(tuple<int, int, int> contact : contacts){
                int x = get<1>(contact);
                int y = get<2>(contact);

                if(infectionSimulation[x]){
                    shakesAfterInfection[x]++;
                }
                
                if(shakesAfterInfection[x] <= k && infectionSimulation[x]){
                    infectionSimulation[y] = true;
                }

                if(infectionSimulation[y]){
                    shakesAfterInfection[y]++;
                }
                
                if(shakesAfterInfection[y] <= k && infectionSimulation[y]){
                    infectionSimulation[x] = true;
                }
            }

            if(equals(infect, infectionSimulation)){
                minK = min(minK, k);
                maxK = max(maxK, k);
                valid = true;
            }
        }

        if(valid){
           numberOfPatienteZero++;
        }
    }

    if(maxK == 251){
        cout << numberOfPatienteZero << " " << minK << " " << "Infinity" << '\n';
    } else {
        cout << numberOfPatienteZero << " " << minK << " " << maxK << '\n';
    }
}

int main(){
    /*freopen("tracing.in", "r", stdin);
	freopen("tracing.out", "w", stdout);*/

    solve();
} 