#include <iostream>
#include <vector>

#define WHITE '0'
#define GREY '1'
#define BLACK '2'

void dfs(const std::vector< std::vector<int> > &graph, std::vector<char> &color, int v, int size){
    color[v] = GREY;

    for(int i = 0; i < size; i++){
        if(graph[v][i] == 1 && color[i] == WHITE){
            dfs(graph, color, i, size);
        }
    }

    color[v] = BLACK;

    return;
}

int main(){
    int n, s;
    std::cin >> n >> s;

    std::vector< std::vector<int> > graph(n);
    int v;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            std::cin >> v;
            graph[i].push_back(v);
        }
    }

    std::vector<char> color(n, WHITE);

    dfs(graph, color, s - 1, n);

    int result = 0;
    for( auto v: color ){
        if( v != WHITE ){
            result++;
        }
    }

    std::cout << result << "\n";
}