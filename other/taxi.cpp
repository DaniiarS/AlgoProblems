#include <iostream>

int main() {
    int N;
    std:: cin >> N;
    int distance[N];
    int price[N];
    int sequence[N];

    for( int i = 0; i < N; i ++ ){
        std:: cin >> distance[i];
    }

    for( int i = 0; i < N; i++ ){
        std:: cin >> price[i];
    }

    int minDistance = distance[0];
    int maxPrice = price[0];
    int indexD = 0, indexP = 0;

    for( int i = 0; i < N; i++ ){
        for( int j = 0; j < N; j++ ){
            if( distance[j] == -1){
                continue;
            }
            if( distance[j] <= minDistance ){
                minDistance = distance[j];
                indexD = j;
            }
        }

        for( int k = 0; k < N; k++ ){
            if( price[k] == -1 ){
                continue;
            }
            if( price[k] >= maxPrice ){
                maxPrice = price[k];
                indexP = k;
            }
        }

        distance[indexD] = -1;
        minDistance = 2000;

        price[indexP] = -1;
        maxPrice = -1000;

        sequence[indexD] = indexP + 1;
    }

    for( int i = 0; i < N; i++ ){
        std:: cout << sequence[i] << " ";
    }
}