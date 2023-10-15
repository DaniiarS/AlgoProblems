#include <iostream>

void hanoi(int n, int i, int k){
    if( n == 1 ){
        std:: cout << 1 << " " <<  i << " " << k << "\n";
    }
    else{
        int tmp = 6 - i - k;
        hanoi(n -1, i, tmp);
        std:: cout << n <<  " " << i << " " << k << "\n";
        hanoi(n -1, tmp, k);
    }
}

int main(){
    int n;
    int from, to;
    std:: cin >> n;
    from = 1;
    to = 3;
    hanoi(n, from, to);
}