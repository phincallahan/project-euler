#include <iostream>
#include <vector>

using namespace std;

void swap_el(int arr[], int a, int b) {
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

void print(int vec[], int len) {
    for(int i = 0; i < len; i++) cout << vec[i];
    cout << "\n";
}

bool permute(int curr[], int len) {
    int k = -1;
    for(int i = len - 1; i > 0; i--) {
        if(curr[i-1] < curr[i]) {
            k = i-1;
            break;
        }
    }

    if(k == -1) return false;
    int l = len - 1;

    int piv = (int)((len - k)/2) + k;
    for(int i = 0; i < len - 1 - piv; i++) {
        int m = k + 1 + i;
        int n = len - 1 - i;
        swap_el(curr, n, m);

        if(curr[n] > curr[k] && n < l) l = n;
        if(curr[m] > curr[k] && m < l) l = m;
    }

    if((len - k) % 2 == 0 && piv < l && curr[piv] > curr[k]) l = piv;

    swap_el(curr, k, l);
    return true;
}

const int LEN = 10;
const int PERM_N = 1000000;

int main() {
    int p[LEN];
    for(int i = 0; i < LEN; i++) p[i] = i;

    int counter = 1;
    while(permute(p, LEN) && ++counter < PERM_N);
    print(p, LEN);
}