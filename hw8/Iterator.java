import java.security.InvalidParameterException;

/**
 *
 * @author fatih dural
 */

public class Iterator<E>
{
	private Object [] data;
	private int size = 0;	
	private int indis = 0;

	public Iterator(Object [] arr, int size){
		data = arr;
		this.size = size;
	}

	public boolean hasNext(){
		return (indis < size);		
	}

	@SuppressWarnings("unchecked")
	public E next(){
		indis++;
		return (E) data[indis - 1];
	}
	@SuppressWarnings("unchecked")
	public E remove(){
		if( size == 0)
			throw new InvalidParameterException();
		E e = (E) new Object();
		e = (E) data[size-1];
		size--;
		return e;
	}
}