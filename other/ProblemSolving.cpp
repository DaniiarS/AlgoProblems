#include <iostream>

int main(){
    int N, A;

    std:: cin >> N >> A;
    int problems[N][2];

    for( int i = 0; i < N; i++ ){
        std:: cin >> problems[i][0] >> problems[i][1];
    }
    std:: cout << "\n";

    int temp;
    for( int i = 0; i < N; i++ ){
        for( int j = 0 ; j < N - 1; j++ ){
            if( problems[j][0] > problems[j + 1][0]){
                temp = problems[j][0];
                problems[j][0] = problems[j + 1][0];
                problems[j + 1][0] = temp;

                temp = problems[j][1];
                problems[j][1] = problems[j + 1][1];
                problems[j + 1][1] = temp;

            } 
        }
    }

    int equalElements = 1;
    for( int i = 0; i < N; i++ ){
        if( problems[i][0] != problems[i + 1][0]){
            for( int j = 0; j < equalElements; j++ ){
                for( int k = 0; k < equalElements - 1; k++ ){
                    if(problems[k][1] < problems[k + 1][1]){
                        temp = problems[k][1];
                        problems[k][1] = problems[k + 1][1];
                        problems[k + 1][1] = temp;
                    } 
                }
            }
            equalElements = 1;
        }
        else{
            equalElements++;
        }
    }

    // for( int i = 0; i < N; i++ ){
    //     std:: cout << problems[i][0] <<  " " << problems[i][1] << std::endl;
    // }

    int amount = 0;

    for( int i = 0; i < N; i++ ){
        if( problems[i][0] <= A ){
            amount++;
            A += problems[i][1];
        }
    }

    std:: cout << amount;

}