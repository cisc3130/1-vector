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
    data[size] = element;
    size++;
    return true;
  }
  
  public void add(int index, E element) {
	if(size++==data.length) grow();	// insert the given element into index, and shift the elements after index.
        for(int i=size-2;i>=index;i--){ //because size was incremented once in line 64, so no need to increment size in the block        
            data[i+1]=data[i];            
        }
        data[index]=element;
        
        for(int i=0;i<size;i++)
            System.out.print(data[i]+" ");
  }
  
  public E remove(int index) {
        System.out.println("the size before remove is "+size);
        System.out.println(" the order before change is ");
        for(int i=0;i<size;i++)
            System.out.print(data[i]+" ");
        System.out.println();
	E removed=data(index);	// Remove the element at index. Make sure there are no gaps
        //data[index]=null;
        if(size++==data.length) grow();
        for(int i=index;i<size;i++){
            data[i]=data[i+1];
        } 
        size=size-2;//because size was incremented once in line 77, so size must minus 2 inorder to decrease size by 1
        System.out.println("The size after remove is "+size);
        System.out.println("The order after remove is ");
        for(int i=0;i<size;i++)
            System.out.print(data[i]+" ");
        System.out.println();
        System.out.println(removed +" is removed ");
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
               intlist.remove(5);
                System.out.println("the index of 5 after change is "+intlist.indexOf(5));
                System.out.println("the index of 7 after change contains "+intlist.indexOf(7));
                intlist.add(5,6);
  }
}
// Junjian Jiang @rivlev
