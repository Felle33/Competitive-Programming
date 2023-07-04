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

ll area(vector<ll> rect) {
	ll width = rect[2] - rect[0];
	ll height = rect[3] - rect[1];
	return width * height;
}

ll inter_area(vector<ll> s1, vector<ll> s2) {
	int bl_a_x = s1[0], bl_a_y = s1[1], tr_a_x = s1[2], tr_a_y = s1[3];
	int bl_b_x = s2[0], bl_b_y = s2[1], tr_b_x = s2[2], tr_b_y = s2[3];

	ll l1 = min(tr_a_x, tr_b_x) - max(bl_a_x, bl_b_x);
	ll l2 = min(tr_a_y, tr_b_y) - max(bl_a_y, bl_b_y);

	if(l1 <= 0 || l2 <= 0) return 0;

	return l1 * l2;
}

bool covered(ll x, ll y, vector<ll> s){
	return x >= s[0] && x <= s[2] && y >= s[1] && y <= s[3];
}

void solve(){
	vector<ll> white(4), black1(4), black2(4);

	for(int i = 0; i < 4; i++){
		cin >> white[i];
	}

	for(int i = 0; i < 4; i++){
		cin >> black1[i];
	}

	for(int i = 0; i < 4; i++){
		cin >> black2[i];
	}

	ll areaWhite = area(white);
	ll interAreaBlack1 = inter_area(white, black1);
	ll interAreaBlack2 = inter_area(white, black2);
	if(interAreaBlack1 == areaWhite || interAreaBlack2 == areaWhite){
		cout << "NO" << '\n';
		return;
	}

	// Vertici coperti da rettangolo nero1
	vector<bool> coveredVertex(4);

	if(covered(white[0], white[1], black1)) coveredVertex[0] = true;
	if(covered(white[0], white[3], black1)) coveredVertex[1] = true;
	if(covered(white[2], white[3], black1)) coveredVertex[2] = true;
	if(covered(white[2], white[1], black1)) coveredVertex[3] = true;

	if(covered(white[0], white[1], black2)) coveredVertex[0] = true;
	if(covered(white[0], white[3], black2)) coveredVertex[1] = true;
	if(covered(white[2], white[3], black2)) coveredVertex[2] = true;
	if(covered(white[2], white[1], black2)) coveredVertex[3] = true;


	// Se tutti i vertici non sono coperti -> NO
	for(int i = 0; i < 4; i++){
		if(!coveredVertex[i]){
			cout << "YES" << '\n';
			return;
		}
	}

	if(interAreaBlack1 + interAreaBlack2 >= areaWhite){
		cout << "NO" << '\n';
	}
	else{
		cout << "YES" << '\n';
	}
}

int main(){
    /* freopen("billboard.in", "r", stdin);
	freopen("billboard.out", "w", stdout); */
    solve();
}