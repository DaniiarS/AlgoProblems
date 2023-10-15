#include <iostream>
#include <vector>

#define INF 1000000000

int nextMinVertex(const std::vector<int> &d, const std::vector<bool> visited){

    int minCost = INF + 1;
    int minVertex;
    int size = d.size();
    for(int i = 0; i < size; i++){
        if(!visited[i] && d[i] < minCost){
            minCost = d[i];
            minVertex = i;
        }
    }

    return minVertex;
}

int main(){
    int n, s, f;
    std::cin >> n >> s >> f;

    std::vector<int> d(n,INF);
    d[s-1] = 0;

    std::vector<bool> visited(n, false);

    std::vector<int> line(n, 0);
    std::vector< std::vector<int> > graph(n, line);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            std::cin >> graph[i][j];
        }
    }

    std::vector<int> parents(n, -1);
    for(int i = 0; i < n; i++){
        if( graph[s-1][i] > 0 ){
            d[i] = graph[s-1][i];
            parents[i] = s - 1;
        }
    }

    
    int current;
    for(int i = 0; i < n; i++){
        current = nextMinVertex(d, visited);
        visited[current] = true;

        for(int j = 0; j < n; j++){
            if( (graph[current][j] != -1) && (d[current] + graph[current][j] < d[j]) ){
                d[j] = d[current] + graph[current][j];
                parents[j] = current;
            }
        }
    }

    if( d[f - 1] >= INF ){
        std::cout << -1;
        return 0;
    }

    std::vector<int> path;
    current = f - 1;
    while( true ){
        if( current == s - 1 ){
            path.push_back(current + 1);
            break;
        }
        path.push_back(current + 1);
        current = parents[current];
    }

    reverse(path.begin(), path.end());
    for(auto i: path){
        std::cout << i << " ";
    }

    return 0;
}