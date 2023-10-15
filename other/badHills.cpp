#include <iostream>


int main(){
    int hillsAmount;
    std:: cin >> hillsAmount;

    int hills[hillsAmount][hillsAmount];

    for( int i = 0; i < hillsAmount; i++ ){
        for( int j = 0; j < hillsAmount; j++ ){
            std:: cin >> hills[i][j];
        }
    }

    int vertices[hillsAmount];
    for( int i = 0; i < hillsAmount; i++ ){
        std:: cin >> vertices[i];
    }

    int count = 0;
    for( int i = 0; i < hillsAmount; i++ ){
        for( int j = i + 1; j < hillsAmount; j++ ){
            if( hills[i][j] == 1 && vertices[i] != vertices[j]){
                count++;
            }
        }
    }
    std:: cout << count << "\n";


    // std:: cout << "\n";
    // for( int i = 0; i < hillsAmount; i++ ){
    //     for( int j = 0; j < hillsAmount; j++ ){
    //         std:: cout <<  hills[i][j] << " ";
    //     }
    //     std:: cout << "\n";
    // }
    // std:: cout << "\n";
    // for( int i = 0; i < hillsAmount; i++ ){
    //     std:: cout << vertices[i] << " ";
    // }
    // std:: cout << "\n";

}