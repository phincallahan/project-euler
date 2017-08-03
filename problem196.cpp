#include <iostream>
#include <vector>
#include <cstdint>

using namespace std;

const int N = 7208785;
const int M = 5678027;
const int L = 1000000;
const int O = 10000;

unsigned long long row_sum(int n, vector<int> primes) {
    uint64_t triangle = (uint64_t)(n-2)*(n-1)/2;

    vector< vector<bool> > is_prime (5);
    for(int row = 0; row < 5; row++) {
        int len = n+row-2;
        is_prime[row] = vector<bool>(n+2, 1);

        for(int i = 4-row; i > 0; i--)
            is_prime[row][len+i-1] = 0;

        for(int i = 0; i < primes.size() && primes[i] < triangle; i++) {
            int offset = triangle % primes[i];
            if(offset > len - 1)
                continue;
            if(triangle - offset != primes[i])
                is_prime[row][len-1-offset] = 0;

            for(int j = 1; j*primes[i]+offset < len; j++) 
                is_prime[row][len-1-offset-j*primes[i]] = 0;
        }

        triangle += n + (row-1);
    }

    triangle = ((uint64_t)n)*(n+1)/2;
    uint64_t sum = 0, prev_sum = 0;
    cout << triangle << "\n";
    int b, a;
    if( n%2 == 0) {
        b= 1; a= -1;
    }  
    else {
        b= -1; a= 1;
    }

    for(int i = 0; i < n; i++) {
        if(is_prime[2][i]) {
            int count = 0;
            
            if(is_prime[2+b][i]) {
                count += is_prime[2+2*b][i+1] + 1;
                if(i != 0) 
                    count += is_prime[2+2*b][i-1];
            }

            if(i != 0 && is_prime[2+a][i-1]) {
                count += is_prime[2+2*a][i-1] + 1;
                if(i != 1)
                    count += is_prime[2][i-2];
            }

            if(is_prime[2+a][i+1]) 
                count += is_prime[2+2*a][i+1] + is_prime[2][i+2] + 1;
            
            if(count >= 2) {
                prev_sum = sum;
                sum += triangle - n + i + 1;
            }
        }
    }

    return sum;
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

int main() {
    vector<int> primes = get_primes(10000000);
    cout << row_sum(M, primes) + row_sum(N, primes) << "\n";
}


