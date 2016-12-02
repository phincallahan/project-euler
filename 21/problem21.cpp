#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

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

int sum_divisors(int n, vector<int> primes) {
    int org = n, sum = 1, i = 0;
    while(n != 1 && primes[i] < sqrt(n) + 1 && i < primes.size()) {
        if(n % primes[i] == 0) {
            int j = 0;
            while(n % primes[i] == 0) {
                j++;
                n /= primes[i];
            }

            sum *= ((int)(pow(primes[i], j + 1))-1)/(primes[i]-1);
        }

        i++;
    }

    if(n != 1) sum *= n + 1;
    return sum - org;
}

const int LIM = 10000;

int main() {
    const vector<int> primes = get_primes((int) sqrt(LIM) + 1);

    int sum = 0;
    vector<int> d_sums (0, LIM);
    for(int i = 1; i < LIM; i++) {
        int d = sum_divisors(i, primes);
        if(d > i && sum_divisors(d, primes) == i) {
            cout << i << " " << d << "\n";
            sum += i + d;
        }
    }

    cout << sum << "\n";
}