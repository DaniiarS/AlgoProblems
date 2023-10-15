#include <iostream>
#include <vector>
#include <map>

#define WHITE 0
#define BLACK 1
#define PRESENT 1

void countComponents(std::map< int, std::vector<int> > &gr, std::vector<int> &visited, int current, std::vector<int> &vertices){
    visited[current] = BLACK;
    vertices.push_back(current + 1);
    int size = gr[current].size();

    for(int i = 0; i < size; i++){
        if( visited[ gr[current][i] ] == WHITE ){
            countComponents(gr, visited, gr[current][i], vertices);
        }
    }
}

void insertVertices(std::map< int, std::vector<int> > &gr, int key, int value){
    if( gr.count(key) ){
        gr[key].push_back(value);
    }
    else{
        std::vector<int> line;
        line.push_back(value);
        
        gr[key] = line;
    }
}

int main(){
    int n, m;
    std::cin >> n >> m;

    std::map< int, std::vector<int> >gr;

    std:: vector<int> visited(n , WHITE);

    int x, y;
    for(int i = 0; i < m; i++){
        std::cin >> x >> y;

        insertVertices(gr, x - 1, y - 1);
        insertVertices(gr, y - 1, x - 1);
    }

    std::vector< std::vector<int> > components;
    int connectedComponents = 0;
    for(int i = 0; i < n; i++){
        if( visited[i] == WHITE ){
            std::vector<int> vertices;
            countComponents(gr, visited, i, vertices);
            connectedComponents++;
            components.push_back(vertices);
        }
    }

    std::cout << connectedComponents << "\n";
    int size = components.size();
    for(int i = 0; i < size; i++){
        std:: cout << components[i].size() << "\n";
        int sizeComponent = components[i].size();
        for(int j = 0; j < sizeComponent; j++){
            std::cout << components[i][j] << " ";
        }
        std::cout << "\n";
    }
    return 0;
}