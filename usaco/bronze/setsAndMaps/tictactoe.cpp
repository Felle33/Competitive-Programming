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

vector<vector<char>> grid(3, vector<char>(3));

int winSingle(char cow){
    for(int i = 0; i < 3; i++){
        bool win = true;
        for(int j = 0; j < 3; j++){
            if(grid[i][j] != cow) win = false;
        }

        if(win) return 1;
    }

    for(int j = 0; j < 3; j++){
        bool win = true;
        for(int i = 0; i < 3; i++){
            if(grid[i][j] != cow) win = false;
        }

        if(win) return 1;
    }

    bool win = true;
    for(int i = 0, j = 0; i < 3; i++, j++){
        if(grid[i][j] != cow) win = false;
    }

    if(win) return 1;

    win = true;
    for(int i = 0, j = 2; i < 3; i++, j--){
        if(grid[i][j] != cow) win = false;
    }

    return win ? 1 : 0;
}

int winDouble(char cow1, char cow2){
    for(int i = 0; i < 3; i++){
        bool win = true;
        bool valid1 = false, valid2 = false;
        for(int j = 0; j < 3; j++){
            if(grid[i][j] != cow1 && grid[i][j] != cow2) win = false;
            if(grid[i][j] == cow1) valid1 = true;
            if(grid[i][j] == cow2) valid2 = true;
        }

        if(win && valid1 && valid2) return 1;
    }

    for(int j = 0; j < 3; j++){
        bool win = true;
        bool valid1 = false, valid2 = false;
        for(int i = 0; i < 3; i++){
            if(grid[i][j] != cow1 && grid[i][j] != cow2) win = false;
            if(grid[i][j] == cow1) valid1 = true;
            if(grid[i][j] == cow2) valid2 = true;
        }

        if(win && valid1 && valid2) return 1;
    }

    bool win = true;
    bool valid1 = false, valid2 = false;
    for(int i = 0, j = 0; i < 3; i++, j++){
        if(grid[i][j] != cow1 && grid[i][j] != cow2) win = false;
        if(grid[i][j] == cow1) valid1 = true;
        if(grid[i][j] == cow2) valid2 = true;
    }

    if(win && valid1 && valid2) return 1;

    win = true;
    valid1 = false, valid2 = false;
    for(int i = 0, j = 2; i < 3; i++, j--){
        if(grid[i][j] != cow1 && grid[i][j] != cow2) win = false;
        if(grid[i][j] == cow1) valid1 = true;
        if(grid[i][j] == cow2) valid2 = true;
    }

    return win && valid1 && valid2 ? 1 : 0;
}

void solve(){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cin >> grid[i][j];
        }
    }

    int single = 0;
    for(char c = 'A'; c <= 'Z'; c++){
        single += winSingle(c);
    }

    int doubleW = 0;
    for(char c1 = 'A'; c1 <= 'Z'; c1++){
        for(char c2 = c1 + 1; c2 <= 'Z'; c2++){
            doubleW += winDouble(c1, c2);
        }
    }

    cout << single << '\n' << doubleW << '\n';
}

int main(){
    freopen("tttt.in", "r", stdin);
	freopen("tttt.out", "w", stdout);
    solve();
} 