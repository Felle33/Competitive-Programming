#include <vector>

using namespace std;

bool heights(int n, vector<int> z, vector<int> &h) {
    // scrivi qui la tua soluzione
    
    if(z[0] > z[1]) {
        for(int i = 1; i < n - 1; i++) {
            if(z[i] < z[i - 1]) {
                if(i - 2 >= 0 && z[i - 1] != z[i - 2]) {
                    return false;
                }
                
                h[0] = 0;
            }
        }

        h[n - 1] = z[n - 2];
    } else {
        for(int i = 1; i < n - 1; i++) {
            if(z[i] < z[i - 1]) {
                if(i - 2 >= 0 && z[i - 1] != z[i - 2]) {
                    return false;
                }
                
                h[0] = 0;
            }
        }

        h[n - 1] = z[n - 2];
    }
    
    return false;
}

int main() {
    vector<int> z(3);
    z[0] = 15, z[1] = 10, z[2] = 4;

    z = vector<int>(5);
    z[0] = 2, z[1] = 4, z[2] = 10, z[3] = 8, z[4] = 8;

    z = vector<int>(9);
    z[0] = 50, z[1] = 54, z[2] = 57, z[3] = 57, z[4] = 49, z[5] = 70, z[6] = 75, z[7] = 75, z[8] = 64;

}
