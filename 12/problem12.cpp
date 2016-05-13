#include <iostream>
#include <vector>

using namespace std;

vector<int> get_primes(int n);
int divisors(int n, vector<int> primes);

const int N = 500;
int main() {
    int num = 2;
    int trig = 1;
    vector<int> primes = get_primes(100);

    while(divisors(trig, primes) <= N) {
        trig += num;
        num++;
    }
    
    cout << trig;
}

int divisors(int n, vector<int> primes) {
    int div_count = 1;

    for(int i = 0; i < primes.size(); i++) {
        int count = 0;
        while(n % primes[i] == 0) {
            n /= primes[i];
            count++;
        }

        if(count != 0)
            div_count *= count+1;
        if( n == 1) {
            break;
        }
    }

    return div_count;
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

