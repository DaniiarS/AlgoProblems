#include <iostream>

int main(){
    int n;

    std:: cin >> n;
    int *arr = new int(n);

    for( int i = 0; i < n; i++ ){
        std:: cin >> arr[i];
    }

    for( int i = 0; i < n; i++ ){
        std:: cout << arr[i] << " ";
    }
    std:: cout << "\n";
}