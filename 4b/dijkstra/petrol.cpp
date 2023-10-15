#include <iostream>
#include <vector>

#define INF 1000000000

int nextMinStation(const std::vector<int> &totalCost, const std::vector<bool> &visited){
    int minCost = INF + 1;
    int size = visited.size();
    int nextMinCostStation;

    for(int i = 0; i < size; i++){
        if(!visited[i] && totalCost[i] < minCost){
            minCost = totalCost[i];
            nextMinCostStation = i;
        }
    }

    return nextMinCostStation;
}

int main(){
    int n, m;
    std::cin >> n;

    std::vector<int> petrolCost(n);
    std::vector<int> totalCost(n, INF);
    totalCost[0] = 0;
    
    std::vector<bool> visited(n, false);

    for(int i = 0; i < n; i++){
        std::cin >> petrolCost[i];
    }

    std::vector<int> line(n, 0);
    std::vector< std::vector<int> > roadMap(n, line);

    std:: cin >> m;
    int x, y;
    for(int i = 0; i < m; i++){
        std::cin >> x >> y;
        roadMap[x - 1][y - 1] = 1;
        roadMap[y - 1][x - 1] = 1;
    }


    int currentStation, currentCost;

    for(int i = 0; i < n; i++){
        currentStation = nextMinStation(totalCost, visited);
        currentCost = petrolCost[currentStation];
        visited[currentStation] = true;

        for(int j = 0; j < n; j++){
            if((roadMap[currentStation][j] == 1) && (currentCost + totalCost[currentStation] < totalCost[j])){
                totalCost[j] = currentCost + totalCost[currentStation];
            }   
        }
    }

    if(totalCost[n - 1] >= INF){
        std::cout << - 1;
        return 0;
    }

    std::cout << totalCost[n - 1] << "\n";
    return 0;
}   