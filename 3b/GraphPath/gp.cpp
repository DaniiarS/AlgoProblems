#include <iostream>
#include <queue>
#include <vector>

int main(){
    int N;
    int first, last;
    std:: queue<int> q;

    std:: cin >> N;
    if( N == 1 ){
        std:: cout << 0 << "\n";
        return 0;
    }
    int graph[N][N];

    for( int i = 0; i < N; i++ ){
        for( int j = 0; j < N; j++ ){
            std:: cin >> graph[i][j];
        }
    }

    std:: cin >> last >> first;
    first--;
    last--;

    if( first == last ){
        std:: cout << 0;
        return 0;
    }


    // p.first - steps, p.second - vertex indexes
    std:: vector< std:: pair< int, int > > dist;
    std:: pair< int, int > p;
    for( int i = 0; i < N; i++ ){
        p.first = 0;
        p.second = i;

        dist.push_back( p );
    }



    q.push( first );
    int cur;
    bool found = false;
    while( !q.empty() ){
        cur = q.front();
        q.pop();

        for( int i = 0; i < N; i++ ){
            if( graph[cur][i] == 1 ){
                
                if( dist[i].first == 0 || dist[i].first + 1 < dist[cur].first ){ // if not visited yet
                    dist[i].first = dist[cur].first + 1;
                }
                graph[i][cur] = -1;

                if( i == last ){
                    found = true;
                    break;
                }
                
                q.push( i );
            }
        }

        if( found ){
            break;
        }
    }



    int nextStep = dist[last].first;
    std:: vector<int> res;
    
    for( int i = 0; i < N; i++ ){
        if( nextStep == 0 ){
            break;
        }
        for( int j = 0; j < N; j++ ){
            if( dist[j].first == nextStep ){
                res.push_back( dist[j].second );
                break;
            }
        }
        nextStep--;
    }
    res.push_back( dist[first].second );

    if( res.size() == 1 ){
        std:: cout << -1 << std::endl;
        return 0;
    }

    std:: cout << dist[last].first << "\n";
    for( auto v: res ){
        std:: cout << v + 1 << " ";
    }

    return 0;
}
