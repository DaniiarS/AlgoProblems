#include <iostream>
#include <string>

class queue{
private:
    int head = 0;
    int tail = 0;
    int currentSize = 0;
    bool firstElement = true;
    int capacity = 10;

    int *val;

public:
    queue(){
        this->val = new int[this->capacity];
    }

    void push(int n){
        if(this->currentSize >= this->capacity){  
            this->resize();
        }

        if(this->firstElement){
            this->currentSize++;
            this->val[this->head] = n;
            this->firstElement = false;
            return;
        }

        this->tail++;
        this->val[ (this->tail) % (this->capacity) ] = n;
        this->currentSize++;
    }
    
    void pop(){
        if(this->currentSize <= 0){
            std:: cout << "error\n";
            return;
        }
        this->currentSize--;
        std:: cout << this->val[( this->head) % this->capacity ] << "\n";
        this->head++;
    }
    
    void front(){
        if(this->currentSize <= 0){
            std:: cout << "error\n";
            return;
        }
        std:: cout << this->val[ (this->head) % this-> capacity ] << "\n";
    }
    
    int size(){
        return this->currentSize;
    }

    void clear(){
        this->head = 0;
        this->tail = 0;
        this->firstElement = true;
        this->currentSize = 0;
    }
    int getCapacity(){
        return this->capacity;
    }

    void show(){
        for( int i = 0; i < this->currentSize; i++ ){
            std:: cout << this -> val[ (this->head + i) % this->capacity ] << " ";
        }
        std:: cout << "\n";
    }

    void resize(){
        int newCapacity = this->capacity * 2;
        int *newArray = new int[newCapacity];

        for( int i = 0; i < this->currentSize; i++ ){
            newArray[i] = this->val[ (this->head + i) % this->capacity ];
        }
        
        this->~queue();
        
        this->val = newArray;
        this->capacity *= 2;
        this->head = 0;
        this->tail = this->currentSize - 1;
    }

    ~queue(){
        delete[] this->val;
    }
};


int main(){
    queue q;

    std:: string cmd;
    int value;

    while(true){
        std:: cin >> cmd;
        if( cmd == "exit" ){
            std:: cout << "bye\n";
            break;
        }
        else if( cmd == "push" ){
            std:: cin >> value;
            q.push(value);
            std:: cout << "ok\n";
        }
        else if( cmd == "pop" ){
            q.pop();
        }
        else if( cmd == "front" ){
            q.front();
        }
        else if( cmd == "size" ){
            std:: cout << q.size() << "\n";
        }
        else if( cmd == "clear" ){
            q.clear();
            std:: cout << "ok\n";
        }
    }

}