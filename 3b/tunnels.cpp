#include <iostream>


int main(){
    int tunnels, crossRoads;
    std:: cin >> tunnels >> crossRoads;

    int graph[tunnels][tunnels];
    for( int i = 0; i < tunnels; i++ ){
        for( int j = 0; j < tunnels; j++ ){
            graph[i][j] = 0;
        }
    }

    int j,k;
    for( int i = 0; i < crossRoads; i++ ){
        std:: cin >> j >> k;
        graph[j - 1][k - 1] = 1;
        graph[k - 1][j - 1] = 1;
    }

    int amount;
    for( int i = 0; i < tunnels; i++ ){
        amount = 0;
        for( int j = 0; j < tunnels; j++ ){
            if( i == j ){
                continue;
            }
            if( graph[i][j] == 1 ){
                amount++;
            }
        }
        std:: cout << amount << " ";
    }
    std:: cout << "\n";
}