#include <iostream>
#include <vector>

#define WHITE '0'
#define GREY '1'
#define BLACK '2'

bool isTree(const std::vector< std::vector<char> > &graph, std::vector<char> &vertices, int current, int size){
    vertices[current] = GREY;
    bool flag = true;

    for(int i = 0; i < size; i++){
        if( graph[current][i] == '1' ){
            if( vertices[i] == WHITE ){
                flag = isTree(graph, vertices, i, size);
                if(!flag){
                    break;
                }

            }
            else if( vertices[i] == BLACK ){
                return false;
            }
        }
    }

    vertices[current] = BLACK;

    return flag; 
}

int main(){
    int n;
    std::cin >> n;
    if(n == 0){
        std::cout << "NO\n";
        return 0;
    }

    std::vector< std::vector<char> > graph(n);
    std::vector<char> vertices(n, WHITE);

    char vertex;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            std::cin >> vertex;
            graph[i].push_back( vertex );
        }
    }

    bool found = isTree(graph, vertices, 0, n);
    
    for(int i = 0; i < n; i++){
        if(vertices[i] == WHITE){
            found = false;
            break;
        }
    }

    if(!found){
        std::cout << "NO\n";
    }
    else{
        std::cout << "YES\n";       
    }

    return 0;
}