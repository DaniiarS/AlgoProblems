#include <iostream>
#include <queue>
#include <vector>

bool validCoord( int x1, int y1, int x2, int y2 ){
    if( (abs(x1 - x2) == 2 && abs(y1 - y2) == 1) || (abs(y1 - y2) == 2 && abs(x1 - x2) == 1)){
        return true;
    }

    return false;
}

bool validBoundry( int x, int y, int N ){
    if( (x >= 0 && x < N) && (y >= 0 && y < N) ){
        return true;
    }

    return false;
}

int main(){
    int n;
    int x1, y1;
    int x2, y2;

    std:: cin >> n;
    std:: cin >> x1 >> y1;
    std:: cin >> x2 >> y2;

    int steps[n][n];
    for( int i = 0; i < n; i++ ){
        for( int j = 0; j < n; j++ ){
            steps[i][j] = 0;
        }
    }

    bool visited[n][n];
    for( int i = 0; i < n; i++ ){
        for( int j = 0; j < n; j++ ){
            visited[i][j] = false;
        }
    }

    visited[x2 - 1][y2 - 1] = true;

    std:: queue<std:: pair< int, int > > q;
    std:: pair< int, int > start;

    start.first = x2 - 1;
    start.second = y2 - 1;

    std:: pair< int, int > from[n][n];
    const std:: vector<int> dx = {-2, -2, 2, 2, -1, -1, 1, 1};
    const std:: vector<int> dy = {-1, 1, -1, 1, 2, -2, 2, -2};
    const int round = dx.size();

    q.push(start);
    while( !q.empty() ){
        std:: pair< int, int > current;
        current = q.front();
        q.pop();

        int x0 = current.first;
        int y0 = current.second;

        for( int i = 0; i < round; i++ ){
            if( validBoundry( x0 + dx[i], y0 + dy[i], n ) ){
                if(!visited[x0 + dx[i]][y0 + dy[i]]){
                    steps[x0 + dx[i]][y0 + dy[i]] = steps[current.first][current.second] + 1;
                    from[x0 + dx[i]][y0 + dy[i]] = current;
                    visited[x0 + dx[i]][y0 + dy[i]] = true;
                
                    std:: pair< int, int > new_point;
                    new_point.first = x0 + dx[i];
                    new_point.second = y0 + dy[i];

                    q.push(new_point);
                }
            }
        }

       if( current.first == x1 - 1 && current.second == y1 - 1 ){
            break;
        }
    }


//    for( int i = 0; i < n; i++ ){
//         for( int j = 0; j < n; j++ ){
//             std:: cout << steps[i][j] << " ";
//         }
//         std:: cout << "\n";
//     }


    std:: cout << steps[x1-1][y1-1] << "\n";
    std:: cout << x1 << " " << y1 << "\n";

    int x, y;
    std:: pair<int ,int> p;

    x = from[x1 - 1][y1 - 1].first;
    y = from[x1 - 1][y1 - 1].second;

    for( int i = 0; i < steps[x1 - 1][y1 - 1]; i++ ){
        std :: cout << x + 1 << " " << y + 1 << "\n";
        p = from[x][y];

        x = p.first;
        y = p.second;
    }

    return 0;   
}

//  0 0 0 2 0 0 0
//  0 0 0 0 0 3 0
//  0 0 1 0 0 0 0
//  0 0 0 0 2 0 4
//  0 * 0 0 0 0 0
//  0 0 0 0 0 0 0
//  0 0 0 0 0 0 0
