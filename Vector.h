#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>



using namespace std;



template<class T>

class Vector{
    
    
    
private:
    
    T* arr;
    
    int size;
    
    int capacity;
    
    
    
    void grow(){
        
        capacity = capacity*2;
        
        T* bigArr = new T[capacity]; // creates a new array, twice the size of original
        
        
        
        for(int i = 0; i < size; i++){
            
            bigArr[i] = arr[i];
            
        }
        
        
        
        delete [] arr; // does NOT delete 'arr'. deletes the array 'arr' is pointing
        
        // arr is now pointing at nothing (dangling pointer)
        
        
        
        arr = bigArr; // point 'arr' to where 'bigArr'
        
    }
    
    
    
public:
    
    Vector(){ // default ctor
        
        size = 0;
        
        capacity = 8;
        
        arr = new T[capacity]; // returns a pointer to [0] (arr now points ot [0] elemens)
        
    }
    
    
    
    Vector(int s){
        
        size = s;
        
        capacity = size*2;
        
        arr = new T[capacity];
        
    }
    
    
    
    Vector(int s, T val){ // fill ctor
        
        size = s;
        
        capacity = size*2;
        
        arr = new T[capacity];
        
        
        
        for(int i = 0; i < size; i++){
            
            arr[i] = val; // *(arr+i) = val
            
        }
        
    }
    
    
    void push_back(T val){
        
        if(size == capacity){
            
            grow();
            
        }
        
        
        
        arr[size] = val;
        
        size++;
        
    }
    
    
    
    void pop_back(){
        
        if(size > 0){
            
            size--;
            
        }
        
    }
    
    
    
    void insert(const T& val,int pos){
        
        if(pos < 0 || pos >= size){
            
            throw std::overflow_error("Error: index out-of-bounds");
            
            return;
            
        }
        
        if(size == capacity){
            
            grow();
            
        }
        
        
        
        for(int i = size; i > pos; i--){
            
            arr[i] = arr[i-1];
            
        }
        
        
        
        arr[pos] = val;
        
        size++;
        
    }
    
    
    
    void erase(int pos){
        
        if(pos < 0 || pos >= size){
            
           // cout << "Error: index out-of-bounds" << endl;
            throw std::overflow_error("Error: index out-of-bounds");
            return;
            
        }
        
        
        
        for(int i = pos; i < size - 1; i++){
            
            arr[i] =  arr[i+1];
            
        }
        
        size--;
        
    }
    
    
    
    int Size(){     // this is a getter
        
        return size;
        
    }
    
    bool empty() {
        return size == 0;
    }
    T& front() {
        return arr[0];
    }
    
    T& at(int pos) {
        if(pos >= size || pos < 0){
            throw std::overflow_error("not legal position");
        }
        return arr[pos];
    }
    T& operator[](int pos) {
        return arr[pos];
    }
    T& back() {
        return arr[size-1];
    }
    
};


#endif
