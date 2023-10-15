#include <iostream>
#include <vector>
#include <stack>

#define WHITE '0'
#define GREY '1'
#define BLACK '2'
#define AROUND 4

bool insideBoundry(int x, int y, int a, int b){
    return (x >= 0 && x < a) && (y >= 0 && y < b);
}

void dfs(std::vector< std::vector<char> > &field, std::vector< std::vector<char> > &visited, std::pair<int, int> start, int size){
    std::pair<int, int> current, next;
    current.first = start.first;
    current.second = start.second;

    visited[current.first][current.second] = GREY;

    const int dx[AROUND] = {1, -1, 0, 0};
    const int dy[AROUND] = {0, 0, 1, -1};

    for(int i = 0; i < AROUND; i++){
        next.first = current.first + dx[i];
        next.second = current.second + dy[i];
        if(!insideBoundry(next.first, next.second, size, size)){
            continue;
        }
        if(field[next.first][next.second] == '.' && visited[next.first][next.second] == WHITE){
            dfs(field, visited, next, size);
        }
    }

    visited[current.first][current.second] = BLACK;
    return;
}

int main(){
    int n;
    std::cin >> n;

    std::vector< std::vector<char> > field(n);
    char v;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            std:: cin >> v;
            field[i].push_back(v);
        }
    }

    std::pair<int, int> start;
    std::cin >> start.first >> start.second;
    start.first--;
    start.second--;

    std::vector< std::vector<char> > visited(n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            visited[i].push_back(WHITE);
        }
    }

    dfs(field, visited, start, n);

    int result = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(visited[i][j] == BLACK){
                result++;
            }
        }
    }

    std::cout << result << "\n"; 
}