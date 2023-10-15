#include <iostream>


int main(){
    int vertexAmount;
    std:: cin >> vertexAmount;

    int graph[vertexAmount][vertexAmount];

    for( int i = 0; i < vertexAmount; i++ ){
        for( int j = 0; j < vertexAmount; j++ ){
            std:: cin >> graph[i][j];
        }
    }

    int vertexDegree[vertexAmount];
    int count = 0;

    for( int i = 0; i < vertexAmount; i++ ){
        for( int j = 0; j < vertexAmount; j++ ){
            if( graph[i][j] == 1 ){
                count++;
            }
        }
        vertexDegree[i] = count;
        count = 0;
    }

    for( int i = 0; i < vertexAmount; i++ ){
        std:: cout << vertexDegree[i] << "\n";
    }
}