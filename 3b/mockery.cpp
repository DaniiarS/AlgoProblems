#include <iostream>
#include <utility>
#include <vector>

int main(){
    int vertexAmount;
    std:: cin >> vertexAmount;

    int graph[vertexAmount][vertexAmount];
    std:: vector< std:: pair< int, int > > minEdges;

    for( int i = 0; i < vertexAmount; i++ ){
        for( int j = 0; j < vertexAmount; j++ ){
            std:: cin >> graph[i][j];
        }
    }


    for( int i = 0; i < vertexAmount; i++ ){
        for( int j = 0; j < vertexAmount; j++ ){
            if( j == i ){
                continue;
            }

            

        }
    }

}