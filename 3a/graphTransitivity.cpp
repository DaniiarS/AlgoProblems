#include <iostream>

int main(){
    int n, m;
    std:: cin >> n >> m;

    int graph[n][n];
    int vertices[n];

    for( int i = 0; i < n; i++ ){
        vertices[i] = 0;
        for( int j = 0; j < n; j++ ){
            graph[i][j] = 0;
        }
    }

    int j, k;
    for( int i = 0; i < m; i++ ){
        std:: cin >> j >> k;

        graph[j - 1][k -1] = 1;
        graph[k - 1][j -1] = 1;

        vertices[j - 1] = 1;
        vertices[k - 1] = 1;
    }

    for( int i = 0; i < n; i++ ){
        if( vertices[i] == 0 ){
            for( int j = 0; j < n; j++ ){
                if( i == j || graph[i][j] == -1 || graph[j][i] == -1 ){
                    continue;
                }
                if( graph[i][j] != 0 || graph[j][i] != 0 ){
                    std:: cout << "NO\n";
                    return 0;
                }
                graph[i][j] = -1;
                graph[j][i] = -1;
            }
        }
    }

    for( int i = 0; i < n; i++ ){
        for( int j = 0; j < n; j++ ){
            if( i == j ){
                continue;
            }
            if( graph[i][j] == 0 ){
                std:: cout << "NO\n";
                return 0;
            }
        }
    }

    std:: cout << "YES\n";

}