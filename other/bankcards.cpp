#include <iostream>

int main(){
    int n;
    long long int Sherlock, Moriarty; 
    
    std:: cin >> n;
    std:: cin >> Sherlock >> Moriarty;

    int digitsS[n], digitsM[n];
    int copySherlock[n], copyMoriarty[n];

    // extract digits
    for( int i = 0; i < n; i++ ){
        digitsS[i] = (Sherlock%10);
        digitsM[i] = (Moriarty%10);
        copySherlock[i] = digitsS[i];
        copyMoriarty[i] = digitsM[i];
        Sherlock = Sherlock/10;
        Moriarty = Moriarty/10;
    }

    // sort Moriarty
    int temp;
    for( int i = 0; i < n; i++ ){
        for( int j = 0; j < n - 1; j++ ){
            if(digitsM[j] < digitsM[j + 1]){
                temp = digitsM[j];
                digitsM[j] = digitsM[j + 1];
                digitsM[j + 1] = temp;

                temp = copyMoriarty[j];
                copyMoriarty[j] = copyMoriarty[j + 1];
                copyMoriarty[j + 1] = temp; 

            }
        }
    }

    // std:: cout << "\nSherlock: ";
    // for( int i = 0; i < n; i++ ){
    //     std:: cout << digitsS[i] << " ";
    // }
    // std:: cout << "\nMoriarty: ";
    // for( int i = 0; i < n; i++ ){
    //     std:: cout << digitsM[i] << " ";
    // }
    // std:: cout << "\n";


    int minHits = 0;
    int maxHits = 0;

    //count minHits
    for( int i = n - 1; i >= 0; i-- ){
        for( int j = n - 1; j >= 0; j-- ){
            if( digitsM[j] == -1 ){
                continue;
            }
            if( digitsM[j] >= digitsS[i] ){
                digitsM[j] = -1;
                digitsS[i] = -1;
                break;
            }
        }
    }

    for( int i = 0; i < n; i++ ){
        if( digitsM[i] != - 1 ){
            minHits += 1;
        }
    }



    // count maxHits
    for( int i = n - 1; i >= 0; i-- ){
        for( int j = n - 1; j >= 0; j-- ){
            if( copyMoriarty[j] == -1){
                continue;
            }
            if( copyMoriarty[j] > copySherlock[i] ){
                maxHits += 1;
                // std:: cout << "crossing " << digitsS[i] << " with " << digitsM[j] << "\n";
                copyMoriarty[j] = -1;
                break;
            }   
        }
    }


    // std:: cout << "\nSherlock: ";
    // for( int i = 0; i < n; i++ ){
    //     std:: cout << copySherlock[i] << " ";
    // }
    // std:: cout << "\nMoriarty: ";
    // for( int i = 0; i < n; i++ ){
    //     std:: cout << copyMoriarty[i] << " ";
    // }
    // std:: cout << "\n";

    std:: cout << minHits << "\n" << maxHits << "\n";
}