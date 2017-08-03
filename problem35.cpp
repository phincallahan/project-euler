#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

template <typename T>
class ComboGen {
    private:
        vector<T> pop;
        vector<int> pos;
        int K;
        int N;
        int mul;

    public: 
        ComboGen(vector<T> & vec, int size) { ComboGen(vec, size, false); }
        ComboGen(vector<T> & vec, int size, bool with_repl): pop(vec), K(size) {
            mul = with_repl ? 0 : 1;
            N = pop.size() - 1;
            pos = vector<int>(K, 0);

            for(int i = K - 2; i >= 0; i--) {
                pos[i] = pos[i+1] + mul;
            }
        }

        bool readCombo(vector<T> & curr) { 
            if(pos[K - 1] == N - K * mul + 1) 
                return false;

            int j = 0;
            for(int i = K - 1; i >= 0; i--) {
                curr[j++] = pop[pos[i]];
            }

            int index;
            for(index = 0; index < K; index++) {
                if(N - index * mul - pos[index] > 0) {
                    pos[index]++;
                    break;
                } 
            }

            if(index == K) {
                pos[K - 1]++;
            } else {
                for(index -= 1; index >= 0; index--) {
                    pos[index] = pos[index + 1] + mul;
                }
            }

            return true;
        }
};

int rotate(int val) {
    string tmp = to_string(val);
    tmp = tmp.back() + tmp;
    tmp.pop_back();
    return stoi(tmp);
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

int main() {
    const int D[] = {1, 3, 7, 9};
    vector<int> prime_dig(D, D+4);
    vector<int> primes = get_primes(1001);
    unordered_set<int> seen;
    int cycles = 0;

    for(int d = 1; d < 7; d++) {
        vector<int> curr_digits(d);
        ComboGen<int> combo(prime_dig, d, true);

        while(combo.readCombo(curr_digits)) {
            do {
                int val = 0, power = 1;
                for(int i = d-1; i >= 0; i--) {
                    val += curr_digits[i] * power;
                    power *= 10;
                }

                if(seen.count(val) > 0) continue;
                int cyl_len = 1;

                seen.insert(val);
                bool is_prime_cycle = is_prime(val, primes);
                val = rotate(val);

                while(seen.count(val) == 0) {
                    if(is_prime_cycle && !is_prime(val, primes)) is_prime_cycle = false;
                    cyl_len++;
                    seen.insert(val);
                    val = rotate(val);
                }

                if(is_prime_cycle) cycles += cyl_len;
            } while(next_permutation(curr_digits.begin(), curr_digits.end()));
        }
    }

    cout << cycles + 2 << endl;
}