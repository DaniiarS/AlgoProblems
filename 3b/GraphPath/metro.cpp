#include <iostream>
#include <queue>
#include <vector>
#include <string>

int main(){
    int n, m;
    int start, end;

    std::cin >> n;
    std::cin >> m;

    std::vector< std::vector<int> > lines;
    std::string inputLine;
    std::getline(std::cin, inputLine);

    for(int i = 0; i < m; i++){
        std::getline(std::cin, inputLine);
        std::vector< int > line;

        for(auto c: inputLine){
            if(isdigit(c)){
                line.push_back(int(c) - int('0'));
            }
        }
        lines.push_back(line);
    }

    std::cin >> start >> end;


    return 0;
}