#include <iostream>
#include <vector>
#include <map>


int countImportantPlanets(std::map<int, std::vector<int>> &gr){
   int countImportantPlanets = 0;

   for(std::map<int, std::vector<int>>::iterator it = gr.begin(); it != gr.end(); it++ ){
        if( gr[it -> first].size() > 1 ){
            countImportantPlanets++;
        }
   }

   return countImportantPlanets;
}

void insertVertices( std::map<int, std::vector<int>> &gr, int v1, int v2){
        if( gr.count(v1) ){
            gr[v1].push_back(v2);
        }
        else{
            std::vector<int> line;
            line.push_back(v2);
            gr[v1] = line;
        }
}

int main(){
    int n;
    std::cin >> n;

    std::map<int, std::vector<int>> gr;

    int m = n - 1;
    int v1, v2;
    for(int i = 0; i < m; i++){
        std::cin >> v1 >> v2;
        insertVertices(gr, v1, v2);
        insertVertices(gr, v2, v1);
    }

    std::cout << countImportantPlanets(gr) << "\n";

    // for(std::map<int, std::vector<int>>::iterator it = gr.begin(); it != gr.end(); it++){
    //     if( gr[it->first].size() > 0){
    //         std::cout << it -> first << ": ";
    //         int size = gr[it -> first].size();
    //         for(int i = 0; i < size; i++ ){
    //             std::cout << gr[it -> first][i] << " ";
    //         }
    //         std::cout << "\n";
    //     }
    //     else{
    //         std::cout << it -> first << ": []\n";
    //     }
    // }

    return 0;
}