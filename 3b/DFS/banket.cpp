#include <iostream>
#include <vector>

#define WHITE '0'
#define RED '1'
#define BLUE '2'

char invertColor(char color){
    if(color == RED){
        return BLUE;
    }
    return RED;
}

bool paintVertices(const std::vector< std::vector<char> > &people, std::vector<char> &colors, int current, int size, char color){
    colors[current] = color;
    bool flag = true;

    for(int i = 0; i < size; i++){
        if(people[current][i] == '1'){
            if(colors[i] == colors[current]){
                return false;
            }
            else if(colors[i] == WHITE){
                flag = paintVertices(people, colors, i, size, invertColor(color));
                if(!flag){
                    break;
                }
            }
        }
    }

    return flag;
}

int main(){
    int n, m;
    std::cin >> n >> m;
    if( n == 1 ){
        std::cout << "YES\n";
        std::cout << 1;
    }
    std::vector<char> colors(n, WHITE);

    std::vector<char> temp(n, WHITE);
    std::vector< std::vector<char> > people(n, temp);

    int x, y;
    for(int i = 0; i < m; i++){
        std:: cin >> x >> y;
        people[x - 1][y - 1] = '1';
        people[y - 1][x - 1] = '1';
    }
    
    char color = RED;
    bool found = true;
    for(int i = 0; i < n; i++){
        if(colors[i] == WHITE){
            found = found && paintVertices(people, colors, i, n, color);
        }
    }
    
    if(!found){
        std::cout << "NO\n";
        return 0;
    }

    std::cout << "YES\n";
    for(int i = 0; i < n; i++){
        if(colors[i] == RED){
            std:: cout << i + 1 << " ";
        }
    }
    std:: cout << "\n";

    return 0;
}