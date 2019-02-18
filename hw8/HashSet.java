import java.security.InvalidParameterException;

/**
 *
 * @author fatih dural
 */

public class HashSet<E> implements Set<E>
{
	private Object [] data;
	private int size = 0;

	public Iterator<E> iterator(){
		Iterator <E> it = new Iterator<E>(data, size); // kume icindeki datalari iceren bir iterator dondurur.
		return it;
	}

	public void add(E e){							// ayni eleman eklenmeyecek sekilde ekleme islemi yapar.
		if( !this.contains(e) ){
			Object [] data_copy = new Object[size + 1];
			for( int i = 0; i < size; i++){
				data_copy[i] = data[i];
			}
			data_copy[size] = (Object) e;
			data = null;
			data = data_copy;
			size++;
		}
	}

	public void addAll(Collection<E> c){				// verilen collectionun tum elemanlarini doner ve hepsini ekler.
		Iterator <E> it = c.iterator();
		while(it.hasNext()){
			this.add(it.next());
		}
	}

	public void clear(){
		if( size == 0) 
			throw new InvalidParameterException(); 	// Bos Seti bosaltmaya calisma!!
		data = null;
		size = 0;
	}

	@Override@SuppressWarnings("unchecked")
	public boolean contains(E e){					// eleman datada var mi bakilir.
		for( int i = 0; i < size; i++ ){
			if( (E) data[i] == e )
				return true;
		}
		return false;
	}

	public boolean containsAll(Collection<E> c){		// tum collection ın elemanları varsa true, yoksa false dondurur.
		Iterator <E> it = c.iterator();
		while(it.hasNext()){
			if( !this.contains(it.next()) ) 
				return false;
		}
		return true;
	}
	
	public boolean isEmpty(){					// bos mu dolu mu kontrolu 
		if( size == 0 )
			return true;
		return false;
	}
	
	@Override@SuppressWarnings("unchecked")
	public void remove(E e){
		for(int i = 0; i < size; i++){
  	      if((E) data[i] == e){						//silinecek elemanı sette bulma durumu
  	      	
  	      	if( size == 1 ){
  	      		data = null;
  	      	}
  	      	else{
  	      		Object [] data_copy = new Object[size-1]; 
  	      		int k = 0; 
				for( int j = 0; j < size; j++){			// eleman haric kopyalama.
					data_copy[k] = data[j];
					if( k == i && i == j) k--;
					k++;
				}

  	      		data = data_copy;
  	      	}
            break;               
          }
        }
        size--; // size 'ı azalt
	}
	
	public void removeAll(Collection<E> c){			// removun collection icin yapilmasi
		Iterator <E> it = c.iterator();
		while(it.hasNext()){
			this.remove(it.next());
		}
		this.size = 0;
	}

	public void retainAll(Collection<E> c){		// collectiondaki elemanlar haricini siler.
		Iterator <E> it = c.iterator();
		while(it.hasNext()){
			E temp = it.next();
			if( !contains(temp) )
			this.remove(temp);
		}
	}

	@Override
	public int	size(){						// size ı dondurur.
		return this.size;
	}
}