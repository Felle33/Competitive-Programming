#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define pi pair<int,int>


struct SegmentTree {
    vll tree;

    SegmentTree(vll numbers){
        int n = numbers.size();
        tree.resize(n * 2);
    
        for (int i = 0; i < n; i++){
            tree[i + n] = numbers[i];
        }
    
        for(int i = n - 1; i >= 1; i--){
            tree[i] = tree[i * 2] + tree[i * 2 + 1];
        }
    }
    
    ll findSum(int node_id, pi q, int l, int r){
        if(q.first > r || q.second < l)
            return 0;
        
        if(q.first <= l && r <= q.second)
            return tree[node_id];
        
        int tmp = (l + r) / 2;
    
        return findSum(node_id * 2, q, l, tmp) + findSum(node_id * 2 + 1, q, tmp + 1, r);
    }
    
    void updateValue(int k, int u){
        k--;
        int n = tree.size() / 2;
        tree[k + n] = u;
    
        for(int i = (k + n) / 2; i >= 1; i /= 2){
            tree[i] = tree[i * 2] + tree[i * 2 + 1];
        }
    }
};
 
int main(){
    int n, q;
    cin >> n >> q;
    vll numbers;
 
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        numbers.push_back(a);
    }
 
    while(__popcount(numbers.size()) != 1){
        numbers.push_back(0);
    }
    
    SegmentTree segmentTree = SegmentTree(numbers);
 
    for (int i = 0; i < q; i++){
        int o;
        cin >> o;
 
        if(o == 1){ // Update at position k to value u
            int k, u;
            cin >> k >> u;
            segmentTree.updateValue(k, u);
        }
        else{ // Find sum
            pi q;
            cin >> q.first >> q.second;
            q.first--;
            q.second--;
            //FIXME
            cout << segmentTree.findSum(1, q, 0, tree.size() / 2 - 1) << endl;
        }
    }
}