#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
using namespace std;

string addBinary(string a, string b) {
    int n = a.size(), m = b.size();

    if(n != m){
        if(n > m){
            string s(n - m, '0');
            b.insert(0, s);
        }
        else{
            string s(m - n, '0');
            a.insert(0, s);
        }
    }

    bool carry = false;
    int i;
    n = max(n, m);
    for(i = n - 1; i >= 0; i--){
        if(a[i] == '0' && b[i] == '0'){
            if(carry) a[i] = '1';

            carry = false;
        }
        else if(a[i] == '1' && b[i] == '1'){
            if(!carry) a[i] = '0';
            carry = true;
        }
        else{
            if(carry) a[i] = '0';
            else a[i] = '1';
        }
    }

    if(carry){
        a.insert(a.begin(), '1');
    }

    return a;
}

int main(){
    cout << addBinary("1", "111");
}
