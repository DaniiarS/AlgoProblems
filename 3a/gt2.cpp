#include <iostream>

int main(){
    int N,M;
    std:: cin >> N >> M;
    int graph[N][N];

    for( int i = 0; i < N; i++ ){
        for( int j = 0; j < N; j++ ){
            graph[i][j] = 0;
        }
    }

    int j,k;
    for( int i = 0; i < M; i++ ){
        std:: cin >> j >> k;
        graph[j - 1][k - 1] = 1;
        graph[k - 1][j - 1] = 1;
    }

    int index;
    for( int i = 0; i < N; i++ ){
        for( int j = 0; j < N; j++ ){
            if( i == j ){
                continue;
            }

            if( graph[i][j] == 1 ){
                index = j + 1;
                while( index < N ){
                    if( graph[i][index] == 1 && graph[j][index] != 1 ){
                        std:: cout << "NO\n";
                        return 0;
                    }
                    index++;
                }
            }
        }
    }
    std:: cout << "YES\n";

}