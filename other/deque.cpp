#include <iostream>
#include <string>

class deque{
private:
    int head = 0;
    int tail = 0;
    bool firstElement = true;

    int currentSize = 0;
    int capacity = 10;

    int *values;

public:

    deque(){
        this->values = new int[this->capacity];
    }

    void push_front(int n){
        if( this->currentSize >= this->capacity ){
            this->resize();
        }

        if( this->checkFirst(this->firstElement, n) ){
            return;
        }

        this->head--;
        if( this->head < 0 ){
            this->head = this->capacity - 1;
        }
        this->values[ (this->head) % this->capacity ] = n;
        this->currentSize++;
    }

    void push_back(int n){
        if( this->currentSize >= this->capacity ){
            this->resize();
        }

        if( this->checkFirst(this->firstElement, n) ){
            return;
        }

        this->tail = (this->tail + 1) % this->capacity;
        this->values[ (this->tail) % (this->capacity) ] = n;
        this->currentSize++;
        
    }

    void pop_front(){
        if(this->currentSize <= 0){
            std:: cout << "error\n";
            return;
        }

        std:: cout << this->values[ (this->head) % (this->capacity) ] << "\n";
        this->head = (this->head + 1) % this->capacity;
        this->currentSize--;
    }

    void pop_back(){
        if(this->currentSize <= 0){
            std:: cout << "error\n";
            return;
        }
        
        std:: cout << this->values[ this->tail ] << "\n";
        this->tail--;
        if(this->tail < 0){
            this->tail = this->capacity - 1;
        }
        this->currentSize--; 
    }

    void front(){
        if(this->currentSize <= 0){
            std:: cout << "error\n";
            return;
        }

        std:: cout << this->values[ (this->head) % this->capacity ] << "\n";
    }

    void back(){
        if(this->currentSize <= 0){
            std:: cout << "error\n";
            return;
        }

        std:: cout << this->values[ (this->tail) % this->capacity ] << "\n";
    }
    
    int size(){
        return this->currentSize;
    }

    void clear(){
        this->head = 0;
        this->tail = 0;
        this->currentSize = 0;
        this->firstElement = true;
    }

    void resize(){
        int newCapacity = this->capacity * 2;
        int *newValues = new int[newCapacity];

        for( int i = 0; i < this->currentSize; i++ ){
            newValues[i] = this->values[ (this->head + i) % this->capacity ];
        }

        this->~deque();
        
        this->values = newValues;
        this->capacity = newCapacity;
        this->head = 0;
        this->tail = this->currentSize - 1;
    }

    bool checkFirst(bool first, int n){
        if(first){
            this->values[ (this->head) % this->capacity ] = n;
            this->currentSize++;
            this->firstElement = false;
            return true;
        }
        return false;
    }

    ~deque(){
        delete[] this->values;
    }

};


int main(){
    deque d;

    std:: string cmd;
    int value;

    while(true){
        std:: cin >> cmd;
        if( cmd == "exit" ){
            std:: cout << "bye\n";
            break;
        }
        else if( cmd == "push_front" ){
            std:: cin >> value;
            d.push_front(value);
            std:: cout << "ok\n";
        }
        else if( cmd == "push_back" ){
            std:: cin >> value;
            d.push_back(value);
            std:: cout << "ok\n";
        }
        else if( cmd == "pop_front" ){
            d.pop_front();
        }
        else if( cmd == "pop_back" ){
            d.pop_back();
        }
        else if( cmd == "front" ){
            d.front();
        }
        else if( cmd == "back" ){
            d.back();
        }
        else if( cmd == "size" ){
            std:: cout << d.size() << "\n";
        }
        else if( cmd == "clear" ){
            d.clear();
            std:: cout << "ok\n";
        }
    }
}