#include <iostream>
#include <vector>

int main(){
    int n;
    std:: cin >> n;

    int graph[n][n];
    int routeLength = 3;

    for( int i = 0; i < n; i++ ){
        for( int j = 0; j < n; j++ ){
            std:: cin >> graph[i][j];
        }
    }

    int minRouteCost = 1000000;
    int minRoute[ routeLength ];

    for( int i = 0; i < n; i++ ){
        for( int j = 0; j < n; j++ ){
            if( i == j ){
                continue;
            }
        
            for( int k = 0; k < n; k++ ){
                if( k == i || graph[j][k] == 0 ){
                    continue;
                }
                
                if( graph[i][j] + graph[j][k] + graph[k][i] < minRouteCost ){
                    minRouteCost = graph[i][j] + graph[j][k] + graph[k][i];
                    minRoute[0] = i;
                    minRoute[1] = j;
                    minRoute[2]= k;
                }
            }
            
        }
    }

    for( int i = 0; i < routeLength; i++ ){
        std:: cout << minRoute[i] + 1 << " ";
    }
    std:: cout << "\n";
}