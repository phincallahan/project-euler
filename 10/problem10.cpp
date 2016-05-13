#include <iostream>

using namespace std;

const int N = 2000000;
int main() {
    long sum = 0;
    bool prime[N] = {false};

    for(int i = 2; i <= N; i++) {
        if(!prime[i-1]) {
            for(int j = 2; i*j <= N; j++) {
                prime[i*j-1] = 1;
            }
        }
    }

    cout << sum;
}
