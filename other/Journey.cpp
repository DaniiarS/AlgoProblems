#include <iostream>
#include <cmath>

int main(){
    int distance, capacity;
    std:: cin >> distance >> capacity;

    int totalStations;
    std:: cin >> totalStations;
    int coordinates[totalStations];
    int minStops = ceil(float(distance)/capacity);

    for( int i = 0; i < totalStations; i++ ){
        std:: cin >> coordinates[i];
    }

    if( totalStations < minStops - 1){
        std:: cout << -1 << "\n";
        return 0; 
    }


    int currentStation = 0;
    int index = 0;
    int amount = 0;

    while(true){
        if(index == totalStations - 1){
            if( coordinates[index] - currentStation <= capacity ){
                if( distance - currentStation > capacity ){
                    amount++;
                }
                break;
            }
        }

        if( coordinates[index] - currentStation <= capacity ){
            if( coordinates[index + 1] - currentStation > capacity ){
                amount += 1;
                currentStation = coordinates[index];
            }
        }
        else{
            std:: cout << -1 << "\n";
            return 0;
        }
        index++;
    }
    std:: cout << amount << "\n";
}
