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
  
  public void add (int index, E element) {
	if (index < 0) throw new IndexOutofBoundsException(“”); //check if index is valid
	while (index > data.length){ //if index is too large, grow it
		grow();
	}
	for (int i = index; i < data.length; i++){
		element = set(i, element); //recursive replacement until end of vector
	}
  }

  public E remove (int index) {
	rangeCheck(index); //range check for no errors
	E otherelement = null; //we need to return an element, it’s initialized here
	for (int i = data.length - 1; i > index; i--){
		otherelement = set(i, otherelement); //modified add code (reversed) so it removes)
	}
	return otherelement;
  }

  public int indexOf(Object o) {
	for (int i = 0; i < data.length; i++){
		if(data[i].equals(o)) return I; //for loop, first element that matches is returned
	}
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

