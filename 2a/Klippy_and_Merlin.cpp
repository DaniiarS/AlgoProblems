#include <iostream>
#include <vector>


int main(){
    int N, K;
    std:: cin >> N >> K;

    int bank[N];
    int prefixedMax[N];
    int prefixedIndeses[N];

    for( int i = 0; i < N; i++ ){
        std:: cin >> bank[i];
    }

    
    prefixedMax[N - 1] = bank[N - 1];
    prefixedIndeses[N - 1] = N - 1;
    for( int i = N - 1; i > 0; i-- ){
        if( prefixedMax[i] > bank[i - 1] ){
            prefixedMax[i - 1] = prefixedMax[i];
            prefixedIndeses[i - 1] = prefixedIndeses[i];
        }
        else{
            prefixedMax[i - 1] = bank[i - 1];
            prefixedIndeses[i - 1] = i - 1;
        }
    }
    
    int first = 0;
    int last = 0;
    int maxPair = -1;
    for( int i = 0; i + K + 1 < N; i++ ){
        if( bank[i] + prefixedMax[i + K + 1] > maxPair ){
            maxPair = bank[i] + prefixedMax[i + K + 1];
            first = i;
            last = prefixedIndeses[i + K + 1];
        }
    }

    std:: cout << first + 1 << " " << last + 1 << "\n";

}