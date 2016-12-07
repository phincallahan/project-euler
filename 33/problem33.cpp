#include <iostream>

using namespace std;

bool frac_eq(int n1, int d1, int n2, int d2) { return d1*n2 == n1*d2; }

int main() {
    int den[4], num[4], counter = 0;;

    for(int shared = 1; shared < 10; shared++) {
        for(int i = 0; i <= shared; i++) {
            int j = shared == i ? shared + 1 : 1;
            for(;j < 10; j++) {
                if(frac_eq(i * 10 + shared, shared * 10 + j, i, j)) {
                    den[counter] = j;
                    num[counter++] = i;
                }
            }
        }
    }

    int n = 1, d = 1;
    for(int i = 0; i < 4; i++) {
        n *= num[i];
        d *= den[i];
    }

    int divisor = 2;
    while(divisor * divisor <= n) {
        while(n % divisor + d % divisor == 0) {
            n /= divisor;
            d /= divisor;
        }

        divisor++;
    }

    cout << d << endl;
}