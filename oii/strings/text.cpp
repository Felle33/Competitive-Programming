// NOTE: it is recommended to use this even if you don't understand the following code.

#include <iostream>
#include <fstream>
#include <vector>

typedef long long ll;

using namespace std;

// input data
int n, k;
vector<string> texts;

double calculate_avg(int row, vector<vector<ll>>& letters_columns) {
    double ans = 0;
    for(int i = 0; i < k; i++) {
        ans += n - letters_columns[i][texts[row][i] - 'a'];
    }
    return ans / (n - 1);
}

int main() {
//  uncomment the following lines if you want to read/write from files
//  ifstream cin("input.txt");
//  ofstream cout("output.txt");
    ios::sync_with_stdio(false);
    cin >> n >> k;
    texts.resize(n);
    for (int i = 0; i < n; i++)
        cin >> texts[i];

    // insert your code here

    vector<vector<ll>> letters_columns(k, vector<ll>(26));

    for(int i = 0; i < k; i++) {
        for(int j = 0; j < n; j++) {
            letters_columns[i][texts[j][i] - 'a']++;
        }
    }

    double avg_ans = calculate_avg(0, letters_columns);
    int res = 0;

    for(int i = 1; i < n; i++) {
        double avg = calculate_avg(i, letters_columns);
        if(avg < avg_ans) {
            res = i;
            avg_ans = avg;
        }
    }


    cout << res << endl; // print the result
    return 0;
}
