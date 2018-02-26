#ifndef VECTOR_H
#define VECTOR_H

template <class T>
class Vector {
    T* arr;
    int sz, capacity, NULL
    
    
    void grow() {
        capacity *=2;  // it will double the capacity
        
        T *tmp=new T[capacity]; // it will copy an old arr to a new array
        
        for (int x=0; x<sz; x++){
            
            tmp[x]=arr[x];// it will copy the tmp to the array
        }
        
        delete [] arr; // it will an array
        
        arr=tmp;
        
    }
    
public:
    
    Vector() {
        sz=0;
        
        capacity=10;
        
        arr= new T[10]; // copies an old array to the new array with capacity of 10
    }
    
    
    ~Vector() {
        if(arr!=NULL) // if array is not equal to null (....)
            
            delete [] arr; //then delete an array
        
    }
    
    void push_back(const T& elt) {
        if (sz==capacity){
            
            grow(); // it will go to grow function
            
        }
        
        arr[sz]=elt; // elt is something inside the temple which you are putting in the size
        
        
        sz++; // increment's sz
        
    }
    
    
    
    void pop_back() {
        if(!empty()){
            
            sz--; // decrement's sz
        }
        
    }
    
    
    void insert(const T& elt, int pos) {
        if(sz==capacity) grow(); // in every function we need to include the "grow function"
        
        if(pos>sz || pos<0)throw exception(); // if there is any error then we use throw exception()
        
        for (int j=sz; j>pos; j--) // when j is greater then array j decrements
            
            arr[j] = arr[j-1]; // does the array j is now equal to new array which is j-1 ? yes
        
        arr[pos]=elt; //  all the elements in the array fits in its position
        
        sz++;// increment's sz
        
    }
    
    
    void erase(int pos) {
        if(pos>=sz || pos<0) throw exception();
        
        for(int j=pos; j<sz-1; j++){
            
            arr[j]=arr[j+1];//arr[pos]=arr[pos+1]->.....->arr[lastpos-1]=arr[lastpos]
            //arr[lastpos-1]==arr[lastpos];
            //sz--;sz=10
            //ex: lastpos=10; lastpos-1=9
            //sz=9
        }
        
        sz--; // decrements sz
        
    }
    
    
    T& front() {
        return arr[0];
        
    }
    
    T& back() {
        return arr[sz-1];
        
    }
    
    
    T& at(int pos) {
        if(pos>=sz || pos<0) throw exception();
        
        return arr[pos];
        
    }
    
    
    T& operator[](int pos) {
        if(pos>sz || pos<0) throw exception();
        
        return arr[pos];
    }
    
    int size() { return sz; }
    
    
    bool empty() {
        if(sz==0)
            return true;
        
        else
            return false;
    }
};

#endif

