#include <iostream>
#include <array>

using namespace std;

int num_change(int n, int* i, int* end) {
    if(n == 0) {
        return 1;
    }

    int ways = 0;
    while(i != end) {
        int val = *i;
        if(n >= val) {
            ways += num_change(n - val, i, end);
        }

        i++;
    }

    return ways;
}

int main() {
    array<int, 8> coins = {1, 2, 5, 10, 20, 50, 100, 200};
    cout << num_change(200, coins.begin(), coins.end()) << endl;
}