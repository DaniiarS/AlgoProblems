#include <iostream>

int main(){
    char hexDigits[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    int HEX_BASE = 16;

    std:: string hex;
    std:: cin >> hex;

    for( int i = 0; i < hex.size(); i++ ){
        if( hex[i] >= 'A' || hex[i] <= 'F' ){
            std:: cout << 'F' - hex[i] + 10 << " ";
        }
    }
}