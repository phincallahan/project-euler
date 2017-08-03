#include <iostream>
#include <cmath>

using namespace std;

const short N = 20;
int main() {
    short prmfac[N][N] = {0};
    prmfac[0][0] = 1;

    for(short i = 1; i < N; i++) {
        short div = 2;
        short num = i+1;
        while( num % div != 0) div++;
          
        memcpy(prmfac[i], prmfac[num/div-1], sizeof(prmfac[0]));        
        prmfac[i][div-1] += 1;
    }

    int prod = 1;
    for(int i = 0; i < N; i++) {
        short max = 0;
        for(int j = 0; j < N; j++)
            if(max < prmfac[j][i]) 
                max = prmfac[j][i];
        prod *= pow(i+1, max);
    }

    cout << prod;
}
