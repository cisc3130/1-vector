import java.util.AbstractList;
import java.util.List;
import java.util.RandomAccess;
import java.lang.RuntimeException;
import java.util.Arrays;

public class Vector<E> extends AbstractList<E> implements List<E>, RandomAccess {
  
  protected Object[] data;
  protected int size;

  public int size() {
   	return size; 
  }
  
  private void rangeCheck(int index) {
   	 if (index < 0 || index >= size)
       throw new IndexOutOfBoundsException("");
  }
  
  @SuppressWarnings("unchecked")
  private E data(int index) {
    return (E) data[index];
  }
  
  private void grow() {
    int newCapacity = data.length*2;
   	data = Arrays.copyOf(data, newCapacity); 
  }
  
  public Vector() {
  	this(10); 
  }
  
  public Vector(int initialCapacity) {
   	data = new Object[initialCapacity];
    size = 0;
  }
  
  public E get(int index) {
    rangeCheck(index);
    return data(index);
  }
  
  public E set(int index, E element) {
    rangeCheck(index);
    E oldValue = data(index);
   	data[index] = element; 
  	return oldValue;
  }
  
  public boolean add(E element) {
   	if (size == data.length) grow(); 
    data[size++] = element;
    return true;
  }
  
  public void add(int index, E element) {
	if(size++==data.length) grow();	// insert the given element into index, and shift the elements after index.
        for(int i=size-1;i>=index;i--){
            data[i+1]=data[i];
        }
        data[index]=element;
  }
  
  public E remove(int index) {
	E removed=data(index);	// Remove the element at index. Make sure there are no gaps
        for(int i=size-1; i>=index;i--){
            data[i]=data[i-1];
        }		
        data[size-1]=null;
        return removed;// Return the removed element
  }
  
	public int indexOf(Object o) {
	for(int i=0;i<size;i++){
            if(data[i].equals(o))
                return i;
        }	// Returns the index of the first occurrence of the specified element 
        return -1;
		// in this list, or -1 if this list does not contain the element. 
  }
  
  public static void main(String[] args) {
  	Vector<Integer> intlist = new Vector<Integer>();
    Vector<String> stringlist = new Vector<String>();
    Vector<Vector<Integer>> intveclist = new Vector<Vector<Integer>>();

		for (Integer i = 0; i < 10; i++) {
				intlist.add(i);
		}

		System.out.println(intlist.indexOf(7));
		System.out.println(intlist.indexOf("seven"));
  }
}
