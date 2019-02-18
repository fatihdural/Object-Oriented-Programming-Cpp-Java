// FATİH DURAL 151044041 CSE241

public interface Queue<E> extends Collection<E>
{
	Iterator<E> iterator(); 
	void add(E e);
	void addAll(Collection<E> c);
	void clear();
	boolean contains(E e);
	boolean containsAll(Collection<E> c);
	boolean isEmpty();
	void remove(E e);
	void removeAll(Collection<E> c);
	void retainAll(Collection<E> c);
	int	size();
	E element();
	void offer(E e);
	E poll();
}