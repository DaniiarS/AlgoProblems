#include <iostream>
#include <queue>


int main(){
    int n;
    std:: cin >> n;
    int graph[n][n];

    if( n == 1 ){
        std:: cout << 0;
        return 0;
    }

    for( int i = 0; i < n; i ++ ){
        for( int j = 0; j < n; j++ ){
            std:: cin >> graph[i][j];
        }
    }

    int start, end;
    std:: cin >> end >> start;
    if( start == end ){
        std:: cout << 0;
        return 0;
    }

    // vertexDist.first: flag int -- visited/not visited, 
    // vertexDist.second: int  -- distanse 'from' - 'to'
    std:: vector< std:: pair< int, int > > vertexDist;
    std:: pair< int, int > p;

    for( int i = 0; i < n; i++ ){
        p.first = 0;
        p.second = 0;

        vertexDist.push_back( p );
    }


    std:: queue<int> q;
    int from[n];
    for( int i = 0; i < n; i++ ){
        from[i] = 0;
    }

    q.push(start - 1);

    int currentV;
    int step = 1;

    while( !q.empty() ){
        currentV = q.front();
        vertexDist[currentV].first = 1; // the vertex is visited

        for( int i = 0; i < n; i++ ){
            if( graph[currentV][i] == 1 && vertexDist[i].first == 0 ){
                from[i] = currentV + 1;

                q.push(i);

                vertexDist[i].first = 1;
                vertexDist[i].second = vertexDist[currentV].second + 1;

            }
        }

        q.pop();
    }

    // if path does not exist
    if( vertexDist[end-1].second == 0 ){
        std:: cout << - 1;
        return 0;
    }

    std:: cout << vertexDist[end - 1].second << "\n";
    std:: cout << end << " ";

    int idx = end-1;
    for( int i = 0; i < vertexDist[end - 1].second; i++ ){
        std:: cout << from[idx] << " ";
        idx = from[idx] - 1;
    }

    return 0;
}