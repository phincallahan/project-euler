#include <iostream>
#include <vector>
#include <map>
#include <iterator>

using namespace std;

const int N = 1000000;
int main() {
    map<long, int> chn_len;
    chn_len[1] = 1;
    int max = 0;
    int max_st = 0;

    for(int i = 2; i < N; i++) {
        if(chn_len.count(i))
            continue;

        long n = i;
        vector<long> chain;
        while(chn_len.count(n) == 0) {
            chain.push_back(n);    
            if(n%2 == 0) n = n/2;
            else         n = 3*n+1;
        }

        int count = (chn_len.find(n) -> second) + 1;

        vector<long>::reverse_iterator it = chain.rbegin();
        for(; it != chain.rend(); it++) {
            chn_len[*it] = count++;
        }

        if(count > max) {
            max = count;
            max_st = chain[0];
        }
    }

    cout << max_st;
}
