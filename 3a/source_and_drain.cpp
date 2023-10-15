#include <iostream>
#include <vector>

int main(){
    int N;
    std:: cin >> N;
    int graph[N][N];

    for( int i = 0; i < N; i++ ){
        for( int j = 0; j < N; j++ ){
            std:: cin >> graph[i][j];
        }
    }

    std:: vector<int> edgeIn;
    std:: vector<int> edgeOut;

    bool in;
    bool out;

    for( int i = 0; i < N; i++ ){
        in = true;
        out = true;
        for( int j = 0; j < N; j++ ){
            if( graph[i][j] == 1 ){
                out = false;
            }
            if( graph[j][i] == 1 ){
                in = false;
            }
        }
        if( in ){
            edgeIn.push_back(i);
        }
        if( out ){
            edgeOut.push_back(i);
        }
    }

    int inSize = edgeIn.size();
    int outSize = edgeOut.size();

    std:: cout << inSize << "\n";
    for( int i = 0; i < inSize; i++ ){
        std:: cout << edgeIn[i] + 1 << "\n";
    }

    std:: cout << outSize << "\n";
    for( int i = 0; i < outSize; i++ ){
        std:: cout << edgeOut[i] + 1 << "\n";
    }


}