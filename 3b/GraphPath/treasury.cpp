#include <iostream>
#include <queue>
#include <vector>

bool insideBoundry(int x, int y, int n, int m){
    return (x >= 0 && x < n) && (y >= 0 && y < m);
}

int main(){
    int n, m;
    std::cin >> n >> m;

    char originalField[n][m];
    char fieldWithEntries[n][m];

    std::pair<int, int> end;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            std::cin >> originalField[i][j];
            fieldWithEntries[i][j] = originalField[i][j];

            if(originalField[i][j] == '*'){
                end.first = i;
                end.second = j;
            }
        }
    }

    bool visited[n][m];
    for(int i = 0; i < n; i ++){
        for(int j = 0; j < m; j++){
            visited[i][j] = false;
        }
    }
    visited[end.first][end.second] = true;

    int steps[n][m];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            steps[i][j] = 0;
        }
    }

    int k;
    std::cin >> k;
    std::pair<int, int> points[k];

    // Marks entries
    for(int i = 0; i < k; i++){
        std::cin >> points[i].first >> points[i].second;
        fieldWithEntries[points[i].first - 1][points[i].second - 1] = '#';
    }

    const int AROUND = 4;
    int dx[AROUND] = {1, -1, 0, 0};
    int dy[AROUND] = {0, 0, 1, -1};

    std::queue< std::pair<int, int> > q;
    q.push(end);

    std::pair<int, int> current, next;

    while(!q.empty()){
        current = q.front();
        q.pop();

        for(int i = 0; i < AROUND; i++){
            next.first = current.first + dx[i];
            next.second = current.second + dy[i];

            if(originalField[next.first][next.second] == '1' || originalField[next.first][next.second] == '*' || visited[next.first][next.second] || !insideBoundry(next.first, next.second, n, m)){
                continue;
            }

            steps[next.first][next.second] = steps[current.first][current.second] + 1;
            visited[next.first][next.second] = true;

            q.push(next);
        }

    }

    std::pair< int, int > res;
    res.first = -1;
    res.second = -1;

    int minSteps = n * m + 1;
    for(int i = 0; i < n; i++ ){
        for(int j = 0; j < m; j++){
            if(fieldWithEntries[i][j] == '#' && visited[i][j] && steps[i][j] < minSteps){
                minSteps = steps[i][j];
                
                res.first = i;
                res.second = j;
            }
        }
    }

    for(int i = 0; i < k; i++){
        if(steps[points[i].first - 1][points[i].second - 1] == minSteps || points[i].first - 1 == res.first && points[i].second - 1 == res.second){
            std::cout << i + 1 << "\n";
            return 0;
        }
    }
    std:: cout << -1 << "\n";

    return 0;
}





    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < m; j++){
    //         std:: cout << steps[i][j] << " ";
    //     }
    //     std:: cout << "\n"; 
    // }
    // std:: cout << "\n";


    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < m; j++){
    //         std:: cout << visited[i][j] << " ";
    //     }
    //     std:: cout << "\n";
    // }
    // std:: cout << "\n";
    
    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < m; j++){
    //         std:: cout << fieldWithEntries[i][j] << " ";
    //     }
    //     std:: cout << "\n";
    // }
    // std:: cout << "\n";

    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < m; j++){
    //         std:: cout << steps[i][j] << " ";
    //     }
    //     std:: cout << "\n";
    // }
    // std:: cout << "\n";

    // std:: cout << res.first << " " << res.second << "\n";
