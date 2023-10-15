#include <iostream>
#include <queue>
#include <utility>

std::queue<int> *compare( std:: queue<int> &p1, std:: queue<int> &p2 ){
    
    int firstCard = p1.front();
    int secondCard = p2.front();

    if( firstCard > secondCard ){
        if( firstCard == 9 && secondCard == 0 ){
            return &p2;
        }
        return &p1;
    }
    else{
        if( firstCard == 0 && secondCard == 9 ){
            return &p1;
        }
        return &p2;
    }

}

void addBottom( std:: queue<int> &p, int firstCard, int secondCard ){
    p.push(firstCard);
    p.push(secondCard);
}

int main(){
    std:: queue<int> player1;
    std:: queue<int> player2;
    std:: queue< int > *winner;
    int steps = 0;
    int value;
    for( int i = 0; i < 5; i++ ){
        std:: cin >> value;
        player1.push( value );
    }
    for( int i = 0; i < 5; i++ ){
        std:: cin >> value;
        player2.push( value );
    }


    while(steps < 1000000){
        if( player1.empty() ){
            std:: cout << "second " << steps << "\n";
            return 0; 
        }
        else if( player2.empty() ){
            std:: cout << "first " << steps << "\n";
            return 0;
        }

        winner = compare( player1, player2 );
        addBottom( *winner, player1.front(), player2.front() );

        player1.pop();
        player2.pop();
        
        steps++;
    }
    std:: cout << "botva\n";
}