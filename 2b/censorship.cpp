#include <iostream>
#include <string>
#include <string.h>
#include <vector>

int main(){
    std:: string line;
    std:: vector< std:: string > lines;

    while (std::getline(std::cin, line))
    {
        if (!line.empty()){
            lines.push_back(line);
        }
        else{
            break;
        }
    }

    for( auto line : lines ){
        std:: cout << line << "\n";
    }
}