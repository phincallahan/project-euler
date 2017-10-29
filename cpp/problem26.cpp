#include <iostream>
#include <vector>

using namespace std;

const int D_MAX = 1000;

int get_repitend(int n) {
    vector<short> rem(n, 0);
    int curr_rem = 1;
    int index = 1;

    while(rem[curr_rem] == 0) {
        rem[curr_rem] = index++;
        if(curr_rem*10 >= n) curr_rem = (curr_rem * 10) % n;
        else curr_rem *= 10;

        if(curr_rem == 0) return 0;
    }

    return index - rem[curr_rem];
}

int main() {
    int max = 0, max_i = 0;
    for(int i = 2; i < D_MAX; i++) {
        int d = get_repitend(i);
        if(d > max) {
            max = d;
            max_i = i;
        }
    }

    cout << max_i << '\n';
}