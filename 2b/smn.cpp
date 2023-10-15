#include <iostream>
#include <vector>

int main(){
    int n;
    int DIGITS = 10;
    std:: cin >> n;

    long long int table[n][DIGITS];

    for(int i = 0; i < DIGITS; i++ ){
        table[0][i] = 1;
    }

    for( int i = 1; i < n; i++ ){
        for( int j = 0 ; j < DIGITS; j++ ){
            long long int localSum = 0;
            for( int k = -1; k < 2; k++ ){
                if( k + j < 0 || k + j > 9 ){
                    continue;
                }

                localSum += table[i - 1][j + k];
            }
            table[i][j] = localSum;
        }
    }

    int numberAmount = 0;
    for( int i = 1; i < DIGITS; i++ ){
        numberAmount += table[n - 1][i];
    }

    std:: cout << numberAmount << "\n";
}