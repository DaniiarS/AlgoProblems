#include <iostream>


int main(){
    int vertices;
    std:: cin >> vertices;

    int graph[vertices][vertices];

    int amount = 0;
    
    for( int i = 0; i < vertices; i++ ){
        for( int j = 0; j < vertices; j++ ){
            std:: cin >> graph[i][j];
            if( j > i && graph[i][j] == 1){
                amount++;
            }
        }
    }


    // for( int i = 0; i < vertices; i++ ){
    //     for( int j = i + 1; j < vertices; j++ ){
    //         if( graph[i][j] == 1 ){
    //             amount++;
    //         }
    //     }
    // }
    std:: cout << amount << "\n";
}