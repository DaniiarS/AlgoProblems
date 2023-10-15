#include <iostream>
#include <vector>
#include <queue>

bool crossBorder(int x, int y, int n){
    if((x == - 1 && y == 0) || (y == - 1 && x == 0 ) || (x == n && y == n - 1) || ( x == n - 1 && y == n)){
        return false;
    }
    else if((x < 0 || x > n - 1) || (y < 0 || y > n - 1)){
        return true;
    }
    return false;
}

bool insideLabyrinth(int x, int y, int n){
    if((x >= 0 && x < n) && (y >= 0 && y < n)){
        return true;
    }
    return false;
}

int main(){
    int n;
    int colorBag = 0;
    const int wallArea = 9;

    std:: cin >> n;

    char labyrinth[n][n];
    char visited[n][n];

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            std:: cin >> labyrinth[i][j];
        }
    }

    for(int i = 0; i < n; i++ ){
        for(int j =0; j < n; j++){
            visited[i][j] = '0';
        }
    }

    const std:: vector<int> dx = {1, -1, 0, 0};
    const std:: vector<int> dy = {0, 0, -1, 1};
    const int directions = dx.size();

    std:: queue<std:: pair<int, int>> points;
    std:: pair<int, int> currentPoint;
    std:: pair<int, int> startPoint;
    std:: pair<int, int> endPoint;

    startPoint.first = 0;
    startPoint.second = 0;

    endPoint.first = n - 1;
    endPoint.second = n - 1;
    
    points.push(startPoint);
    points.push(endPoint);
    visited[0][0] = '1';
    visited[n - 1][n - 1] = '1';

    while(!points.empty()){
        currentPoint = points.front();
        points.pop();

        int x, y;
        for(int i = 0; i < directions; i++){
            x = currentPoint.first + dx[i];
            y = currentPoint.second + dy[i];

            if(crossBorder(x, y, n) || labyrinth[x][y] == '#'){
                colorBag += wallArea;
            }
            else if(insideLabyrinth(x, y, n) && (labyrinth[x][y] == '.' && visited[x][y] == '0')){
                visited[x][y] = '1';

                std:: pair<int, int> newPoint;
                newPoint.first = x;
                newPoint.second = y;

                points.push(newPoint);
            }
        }
    }

    std:: cout << colorBag << "\n";
    return 0;
}