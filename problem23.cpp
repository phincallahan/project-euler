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

const int LIM = 20161;
int main() {
    vector<int> primes = get_primes(sqrt(LIM) + 1);
    vector<int> abundant;

    for(int i = 1; i <= LIM; i++) {
        int d = sum_divisors(i, primes);
        if(d > i) abundant.push_back(i);
    }

    vector<bool> is_sum(20161, false);
    for(int i = 0; i < abundant.size(); i++) {
         for(int j = i; j < abundant.size() && abundant[i] + abundant[j] <= LIM; j++) {
             is_sum[abundant[i] + abundant[j] - 1] = true;
         }
    }

    long long sum = 0;
    for(int i = 0; i < LIM; i++) {
        if(!is_sum[i]) sum += i + 1;
    }

    cout << sum << '\n';
}