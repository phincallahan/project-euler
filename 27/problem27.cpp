#include <iostream>
#include <climits>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int range(int b, int c) {
    if(b*b - 4*c < 0 || b > 0) {
        return INT_MAX;
    } else {
        double z1 = (b + sqrt(b*b - 4*c))/(2*c);
        double z2 = (b - sqrt(b*b - 4*c))/(2*c);

        return (int) min(z1, z2);
    }
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

bool is_prime(int n, vector<int> primes) {
    if(n <= 1) {
        return false;
    } else if(binary_search(primes.begin(), primes.end(), n)) {
        return true;
    } else {
        for(int i = 0; i < primes.size(); i++) {
            if(primes[i] > sqrt(n)) break;
            if(n % primes[i] == 0) return false;
        }

        return true;
    } 
}

const int A_LIM = 1000;
const int B_LIM = 1000;

int main() {
    vector<int> primes = get_primes(1002);
    int is_valid = 0, n_max = 0, max_prod;

    for(int i = 0; i < primes.size(); i++) {
        int b = primes[i];
        for(int a = -1 * A_LIM + 1; a < A_LIM; a++) {
            if(range(a,b) > n_max) {
                int n = 0;
                while(is_prime(n*n + a*n + b, primes)) n++;

                if(n > n_max) {
                    n_max = n;
                    max_prod = a*b;
                }
            }
        }
    }

    cout << max_prod << '\n';
}