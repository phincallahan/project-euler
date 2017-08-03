#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

const int N = 15;

double prob_B(int turn);

int main() {
    vector< vector<double> > p (N+1, vector<double>(N+1, 0));
    p[0][0] = 1;

    for(int turn = 1;turn  <= N; turn++) {
        for(int count = 0; count <= turn; count++) {
            double prob = p[turn-1][count] * (1-prob_B(turn));
            prob += count > 0 ? p[turn-1][count-1] * prob_B(turn) : 0;
            p[turn][count] = prob;
        }
    }

    double total_prob = 0;
    for(int count = N/2+1; count <= N; count++) {
       total_prob += p[N][count]; 
    }
    
    int max = (1-total_prob)/total_prob + 1;

    cout << max;
}

double prob_B(int turn) {
   return 1.0L/(turn+1);
}
