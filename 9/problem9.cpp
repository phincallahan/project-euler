#include <iostream>

using namespace std;

const int N = 1000;
int main() {
    for(int a = 1; a < N-1; a++)
        for(int b = a; b < N - a; b++) {
            int c = N - a - b;
            if(a*a + b*b == c*c) {
                cout << a*b*c;
                return 0;
            }
        }
}

