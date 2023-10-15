#include <iostream>
#include <queue>
#include <vector>

bool insideField(int x, int y, int n){
    return (x >= 0 && x < n) && (y >= 0 && y < n);
}

int main(){
    int n;
    std:: cin >> n;

    char field[n][n];
    std:: pair< int, int  > start, end;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            std:: cin >> field[i][j];
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(field[i][j] == '@'){
                start.first = i;
                start.second = j;
            }
            else if(field[i][j] == 'X'){
                end.first = i;
                end.second = j;
            }
        }
    }

    bool visited[n][n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            visited[i][j] = false;
        }
    }

    visited[end.first][end.second] = true;

    int steps[n][n];
    std:: pair< int, int > route[n][n];

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            steps[i][j] = 0;
            
            route[i][j].first = -1;
            route[i][j].second = -1;
        }
    }

    const int AROUND = 4;
    int dx[AROUND] = {1, -1, 0, 0};
    int dy[AROUND] = {0, 0, 1, -1};

    std:: queue< std:: pair< int, int > > q;
    q.push(end);

    std:: pair< int, int > current;
    std:: pair< int, int > next;

    bool found = false;

    while(!q.empty()){
        current = q.front();
        q.pop();

        for(int i = 0; i < AROUND; i++){
            next.first = current.first + dx[i];
            next.second = current.second + dy[i];

            if(!insideField(next.first, next.second, n)){
                continue;
            }

            if(field[next.first][next.second] == '.' || field[next.first][next.second] == '@'){
                if(!visited[next.first][next.second]){
                    steps[next.first][next.second] = steps[current.first][current.second] + 1;

                    route[next.first][next.second].first = current.first;
                    route[next.first][next.second].second = current.second;

                    visited[next.first][next.second] = true;
                    q.push(next);
                }
                else{
                    if(steps[current.first][current.second] + 1 < steps[next.first][next.second]){
                        steps[next.first][next.second] = steps[current.first][current.second] + 1;

                        route[next.first][next.second].first = current.first;
                        route[next.first][next.second].second = current.second;

                        visited[next.first][next.second] = true;
                        q.push(next);
                    }
                }
            }

            if(field[next.first][next.second] == '@'){
                found = true;
                break;
            }

        }

        if(found){
            break;
        }

    }
    
    if(visited[start.first][start.second]){
        std:: cout << "Y\n";
        next.first = route[start.first][start.second].first;
        next.second = route[start.first][start.second].second;

        int x, y;

        while(true){
            if(next.first == -1 && next.second == -1){
                break;
            }
            
            field[next.first][next.second] = '+';
            
            x = route[next.first][next.second].first;
            y = route[next.first][next.second].second;

            next.first = x;
            next.second = y;
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                std:: cout << field[i][j] << "";
            }
            std:: cout << "\n";
        }
        
    }
    else{
        std:: cout << "N\n";
    }

    return 0;
}

/*
20
....................
...............@....
....................
....................
....................
....................
....................
....................
....................
....................
....................
....................
....................
....................
....................
....................
....................
....................
.............O......
............O.X.....
.................... */