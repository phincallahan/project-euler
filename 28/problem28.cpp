#include <iostream>
using namespace std;

const int GRID_SIZE = 1001;

int main() {
    long long sum = 1;
    for(int i = 1; i <= (GRID_SIZE - 1)/2; i++) sum += 4*(2*i-1)*(2*i-1) + 20*i;
    cout << sum << '\n';
}