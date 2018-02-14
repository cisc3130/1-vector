#ifndef VECTOR_H
#define VECTOR_H

template <class T>
class Vector {
  T* arr;
  int size, capacity;

  // convenience function called by push_back and insert.
  // allocate a new array with double the capacity,
  // copy arr over the the new array,
  // deallocate arr,
  // point arr to the new array,
  // update capacity
  void grow() 
{
	// double the capacity so more elements can be added
	capacity *= 2;
	// create an even bigger array with the new capacity
	T* evenBiggerArray = new T [capcity];
	// copy all the elements of the old array into the new one
	for(int pie=0; pie<size; pie++)
	{
		evenBiggerArray[pie] = arr[pie];
	}
	// deletes location arr is pointing to, freeing up memory
	delete [] arr;
	// reassign arr
	arr = evenBiggerArray;
  }

  public:
  // allocate a new array with size 0 (nothing is in it yet)
  // and capacity 10
  // set sz, capacity, arr
  Vector() 
  {
	capacity = 10;
	arr = new T[capcity];
	size = 0;
  }

  // deallocate arr
  ~Vector() 
  {
	delete [] arr;
	arr = NULL;
  }

  // add elt to the end of arr (remember to update sz!)
  void push_back(const T& elt) 
  {
	// first, check if array is full
	if(size==capacity)
	{
		grow();
	}
	// add elt to the array
	arr[size] = elt;
	// update the size of the array
	size++;
  }

  // remove the last element in arr (remember to update sz!)
  void pop_back() 
{
	// subtract one from size so the last element will be overwritten
	size--;
  }

  // add elt to arr at position pos
  // throw an exception if pos is not legal
  // remember to update sz
  void insert(const T& elt, int pos) 
{
	// first, check if array is full
	if(size==capacity)
	{
		grow();
	}
	// second, check if pos is valid
	if(pos<0)
	{
		cout << "invalid position given" << endl;
		return;
	}
	// start at the end of the array and shift everything down one until you reach pos
	for(int lol = size; lol>pos; lol--)
	{
		arr[lol]= arr[lol-1];
	}
	// put elt in pos position
	arr[pos] = elt;
	// update size
	size++;
  }

  // erase elt at position pos
  // throw an exception if pos is not legal
  // remember to update sz
  void erase(int pos) 
{
	// first, check if array is full
	if(size==capacity)
	{
		grow();
	}
	// second, check if pos is valid
	if(pos<0)
	{
		cout << "invalid position given" << endl;
		return;
	}
	// shift everything down one overwriting pos's element in the process
	for(int smh = pos; smh < size-1; smh++)
	{
		arr[smh]=arr[smh+1];
	}
	// update size
	size--;
  }

	// return first element in vector
	T& front() 
	{
		return arr[0];
	}

	// return last element in vector
	T& back() 
	{
		return arr[size];
	}

  // return element at position pos
  // throw an exception if pos is not legal
  T& at(int pos) 
{
	// first, check if pos is valid
	if(pos<0)
	{
		cout << "invalid position given" << endl;
		return;
	}
	return arr[pos];
  }

  // return element at position pos (will break if pos is not legal)
  T& operator[](int pos) 
{
	  return arr[pos];
  }

  int size() 
  {
	  return sz; 
  }

  // return true if vector is empty
  bool empty() 
  {
	  if (size == 0)
	  {
		  return true;
	  }
	  else
		  return false;
  }
};

#endif
