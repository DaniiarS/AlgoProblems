#include <iostream>
#include <vector>

int countImportantPlanets(const std::vector< std::vector<bool> > &graph){

    int importantPlanetsAmount = 0;
    int size = graph[0].size();

    int count;
    for(int i = 0; i < size; i++){
        count = 0;
        for(int j = 0; j < size; j++){
            if(graph[i][j]){
                count++;
            }
        }
        if(count > 1){
            importantPlanetsAmount++;
        }
    }

    return importantPlanetsAmount;
}

int main(){
    int n;
    std::cin >> n;

    std::vector<bool> line(n, false);
    std::vector< std::vector<bool> > graph(n, line);

    int m = n - 1;
    int x, y;
    for(int i = 0; i < m; i++){
        std::cin >> x >> y;
        graph[x - 1][y - 1] = true;
        graph[y - 1][x - 1] = true;
    }

    std::cout << countImportantPlanets(graph);
}