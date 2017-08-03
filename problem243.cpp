#include <iostream>
#include <vector>
#include <cmath>
#include <cstdint>

using namespace std;

vector<int> get_primes(int n);

double N = 4.0/10.0;
double M = 15499.0/94744.0;
int P = 1000;

int main() {
    vector<int> primes = get_primes(P);

    int i = 0;
    long double p = 1; 
    int64_t n = 1;

    do {
        p *= (1 - 1/(double)primes[i]);
        n *= primes[i];
        i++;

        cout << p*n/(n-1) << " " << n << "\n";
    } while(p>= M);

    int k = 1;
    while(k*p*n/(k*n-1) >= M) {
        k++;
    }

    cout << n*k << "\n";
}

vector<int> get_primes(int n) {
    vector<bool> array (n, false);
    vector<int> primes;

    for(int i = 2; i < n; i++) {
        if(!array[i-2]) {
            for(int j = 2; i*j < n+2; j++) {
                array[i*j-2] = true;
            }
            primes.push_back(i);
        }
    }

    return primes;
}

