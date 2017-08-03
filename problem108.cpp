#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

using namespace std;

class MinHeap {
    public:
        MinHeap() {};
        ~MinHeap() {};
        
        void insert(int el) {
            heap.push_back(el);
            int index = heap.size() - 1;
            while(index != 0 && parent(index) >= 0 && heap[parent(index)] > heap[index]) {
                int temp = heap[parent(index)];
                heap[parent(index)] = el;
                heap[index] = temp;
                index = parent(index);
            }
        }

        int pop() {
            int min = heap.front();
            
            heap[0] = heap.back();
            heap.pop_back();

            heap_down(0);
            return min;
        }

        void print() {
            for(int i = 0; i < heap.size(); i++) 
                cout << heap[i] << ' ';

            cout << endl;
        }

        int size() { return heap.size(); }
    private:
        int left(int parent) {
            int child = (parent << 1) + 1;
            return (child < heap.size()) ? child : -1;
        }
        
        int right(int parent) {
            int child = (parent << 1) + 2;
            return (child < heap.size()) ? child : -1;
        }

        int parent(int child) { 
            int parent = (child - 1) >> 1;
            return (child == 0) ? -1 : parent;
        }

        void heap_down(int index) {
            int child = left(index);

            if(child > 0 && right(index) > 0 && heap[child] > heap[right(index)]) {
                child = right(index);
            }

            if(child > 0 && heap[child] < heap[index]) {
                int temp = heap[child];
                heap[child] = heap[index];
                heap[index] = temp;
                heap_down(child);
            }
        }

    private:
        vector<int> heap;    
};

// template< class T, size_t K , size_t N >
// class Comb {
//     friend class CombIter < T, N >;

//     typedef RingIter<T, N> iterator;
//     typedef ptrdiff_t difference_type;
//     typedef size_t size_type;
//     typedef T value_type;
//     typedef T * pointer;
//     typedef T & reference;
    
//     public:
//         Comb(array<T, K>& pop) {
//             pop = pop;
//         }
        
//         iterator being() {
//             return 
//         }
        
//     private:
//         array<T, K> pop;
// };

template <typename T>
class ComboGen {
    private:
        vector<T> pop;
        string mask;

    public: 
        ComboGen(vector<T> & vec, size_t K): pop(vec) {
            mask = string(K, '1') + string(vec.size()-K, '0');
        }

        bool readCombo(vector<T> & curr) { 
            if(mask == "") return false;

            int j = 0;
            for(int i = 0; i < mask.length(); i++) {
                if(mask[i] == '1') {
                    curr[j++] = pop[i];
                }
            }

            if(!prev_permutation(mask.begin(), mask.end())) {
                mask = "";
            }

            return true;
        }
};

int base_10(string base2) {
    int num = 0;
    int power = 1;
    for(int i = base2.length() - 1; i >= 0; i--) {
        num += (base2[i] - '0') * power;
        power *= 2;
    }

    return num;
}

int has_divisors(MinHeap primes, int divisors) {
    int n = 1;
    int prod = 1;
    while(n < divisors) {
        int min = primes.pop();
        primes.insert(min*min);
        n *= 2;
        prod *= min;
    }

    return prod;
}

int main() {
    vector<int> primes(5);
    vector<int> curr(2);
    primes[0] = 2;
    primes[1] = 3;
    primes[2] = 5;
    primes[3] = 7;
    primes[4] = 11;

    ComboGen<int> combo(primes, 2);
    while(combo.readCombo(curr)) {
        cout << curr[0] << ' ' << curr[1] << endl;
    }
}