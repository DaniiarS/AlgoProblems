#include <iostream>
#include <vector>
#include <stack>

#define PRESENT true
#define ABSENT false

#define WHITE 0
#define GREY 1
#define BLACK 2


void topSort(const std::vector< std::vector<bool> > &graph, std::vector<int> &vertices, std::vector<int> &line, int current, int size){
    vertices[current] = GREY;

    //Check if the vertex contains neighbours
    for(int i = 0; i < size; i++){
        if(graph[current][i] == PRESENT){
            if( vertices[i] == GREY ){
                line.push_back(-1);
                return;
            }
            if(vertices[i] == WHITE){
                topSort(graph, vertices, line, i, size);
            }
        }
    }

    vertices[current] = BLACK;
    line.push_back(current);

    return;
}

int main(){
    int n , m;
    std::cin >> n >> m;

    std::vector<int> vertices(n, WHITE);
    std::vector<int> line;

    std::vector<bool> temp(n, ABSENT);
    std::vector< std::vector<bool> > graph(n, temp);
    
    int x, y;
    for(int i = 0; i < m; i++){
        std::cin >> x >> y;
        graph[x - 1][y - 1] = PRESENT;

        if(graph[y - 1][x - 1] == PRESENT){
            std::cout << "No\n";
            return 0;
        }
    }

    for(int i = 0; i < n; i++){
        if(vertices[i] == WHITE){
            topSort(graph, vertices, line, i, n);
        }
    }


    for(int i = 0; i < n; i++){
        if(line[i] == -1){
            std::cout << "No\n";
            return 0;
        }
    }

    reverse(line.begin(), line.end());
    std::cout << "Yes\n";
    for(auto i: line){
        std::cout << i + 1 << " ";
    }
    std::cout << "\n";


    return 0;
}