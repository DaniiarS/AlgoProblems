#include <iostream>
#include <vector>

#define INF 1000000000

int nextMinVertex(const std::vector<int> &d, const std::vector<bool> &visited){
    int minCost = INF + 1;

    int size = d.size();
    int minVertex;
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

    std::vector<int> d(n, INF);
    std::vector<bool> visited(n, false);
    d[s - 1] = 0;

    std::vector<int> line(n, 0);
    std::vector< std::vector<int> > graph(n, line);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            std:: cin >> graph[i][j];
        }
    }

    for(int i = 0; i < n; i++){
        if( graph[s-1][i] > 0 ){
            d[i] = graph[s-1][i];
        }
    }
    visited[s-1] = true;

    int current;
    for(int i = 0; i < n; i++){
        current = nextMinVertex(d, visited);
        visited[current] = true;

        for(int j = 0; j < n; j++){
            if((graph[current][j] != -1) && (d[current] + graph[current][j] < d[j])){
                d[j] = d[current] + graph[current][j];
            }
        }

    }

    if(d[f-1] >= INF){
        std::cout << -1;
        return 0;
    }
    std::cout << d[f-1] << "\n";

    return 0;
}