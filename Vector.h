#ifndef VECTOR_H
#define VECTOR_H

template <class T>
class Vector {
  T* arr;
  int sz, capacity;

  // convenience function called by push_back and insert.
  // allocate a new array with double the capacity,
  // copy arr over the the new array,
  // deallocate arr,
  // point arr to the new array,
  // update capacity
  void grow() {
  }

  public:
  // allocate a new array with size 0 (nothing is in it yet)
  // and capacity 10
  // set sz, capacity, arr
  Vector() {
  }

  // deallocate arr
  ~Vector() {
  }

  // add elt to the end of arr (remember to update sz!)
  void push_back(const T& elt) {
  }

  // remove the last element in arr (remember to update sz!)
  void pop_back() {
  }

  // add elt to arr at position pos
  // throw an exception if pos is not legal
  // remember to update sz
  void insert(const T& elt, int pos) {
  }

  // erase elt at position pos
  // throw an exception if pos is not legal
  // remember to update sz
  void erase(int pos) {
  }

	// return first element in vector
	T& front() {
	}

	// return last element in vector
	T& back() {
	}

  // return element at position pos
  // throw an exception if pos is not legal
  T& at(int pos) {
  }

  // return element at position pos (will break if pos is not legal)
  T& operator[](int pos) {
  }

  int size() { return sz; }

  // return true if vector is empty
  bool empty() {
  }
};

#endif
