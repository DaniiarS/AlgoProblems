#include <iostream>

int main(){
    int N;
    std:: cin >> N;

    int minutes[N];
    int sequence[N];

    for( int i = 0; i < N; i++ ){
        std:: cin >> minutes[i];
    }

    int maxValue = minutes[0];
    int index = 0;
    int count = 0;

    for( int i = 0; i < N; i++ ){
        for( int j = 0; j < N; j++ ){
            if( minutes[j] == -1 ){
                continue;
            }
            if( minutes[j] > maxValue ){
                maxValue = minutes[j];
                index = j;
            }
        }
        maxValue = -100;
        minutes[index] = -1;
        sequence[count] = index + 1;
        count += 1;
    }

    for( int i = 0; i < N; i++ ){
        std:: cout << sequence[i] << " ";
    }
    std:: cout << "\n";
}