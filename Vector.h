#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <stdexcept>    //I changed exception for stdexcept

using namespace std;

template<class T>

class Vector{



private:
    T* arr;
    int sz;             //I changed the data member name from size to sz since having size
    int capacity;       //as a data member and function create a conflict, I chose to change
                        //size here because teacher used size to call functions in main
    void grow( ){
        capacity = capacity*2;
        T* bigArr = new T[capacity]; // creates a new array, twice the sz of original

        for(int i = 0; i < sz; i++){
            bigArr[i] = arr[i];
        }

        delete [] arr; // does NOT delete 'arr'. deletes the array 'arr' is pointing
        // arr is now pointing at nothing (dangling pointer)
        arr = bigArr; // point 'arr' to where 'bigArr'
    }



public:

    Vector(){ // default ctor
        sz = 0;
        capacity = 8;
        arr = new T[capacity]; // returns a pointer to [0] (arr now points ot [0] elemens)
    }



    Vector(int s){
        sz = s;
        capacity = sz*2;
        arr = new T[capacity];
    }

    Vector(int s, T val){ // fill ctor
        sz = s;
        capacity = sz*2;
        arr = new T[capacity];

        for(int i = 0; i < sz; i++){
            arr[i] = val; // *(arr+i) = val
        }
    }

    void push_back(T val){
        if(sz == capacity){
            grow();
        }
        arr[sz] = val;
        sz++;
    }

    void pop_back(){
        if(sz > 0){
            sz--;
        }
    }

    void insert(const T& val,int pos){
        if(pos < 0 || pos >= sz){
            throw std::overflow_error("Error: index out-of-bounds");
            return;
        }

        if(sz == capacity){
            grow();
        }

        for(int i = sz; i > pos; i--){
            arr[i] = arr[i-1];
        }

        arr[pos] = val;
        sz++;
    }

    void erase(int pos){
        if(pos < 0 || pos >= sz){
           // cout << "Error: index out-of-bounds" << endl;
            throw std::overflow_error("Error: index out-of-bounds");
            return;
        }

        for(int i = pos; i < sz - 1; i++){
            arr[i] =  arr[i+1];
        }

        sz--;
    }

    int size(){     // this is a getter
        return sz;
    }

    bool empty() {
        return sz == 0;
    }

    T& front() {
        return arr[0];
    }

    T& at(int pos) {
        if(pos >= sz || pos < 0){
            throw std::overflow_error("not legal position");
        }
        return arr[pos];
    }

    T& operator[](int pos) {
        if(pos >= sz || pos < 0){
            throw std::overflow_error("not legal position");
        }
        return arr[pos];
    }

    T& back() {
        return arr[sz-1];
    }
};



#endif
