import java.security.InvalidParameterException;

/**
 *
 * @author fatih dural
 */

public class ArrayList<E> implements List<E>
{
	private Object [] data;
	private int size = 0;

	@Override
	public Iterator<E> iterator(){
		Iterator <E> it = new Iterator<E>(data, size); 	// kume icindeki datalari iceren bir iterator dondurur.
		return it;
	}

	@Override
	public void add(E e){
		Object [] data_copy = new Object[size + 1];		// sirali bir sekilde ekleme yapar, elemanlar pek cok kez eklenebilir.
		for( int i = 0; i < size; i++){
			data_copy[i] = data[i];
		}
		data_copy[size] = (Object) e;
		data = null;
		data = data_copy;
		size++;
	}

	@Override
	public void addAll(Collection<E> c){				// eklemeyi tum collection icin yapar.
		Iterator <E> it = c.iterator();
		while(it.hasNext()){
			this.add(it.next());
		}
	}

	@Override
	public void clear(){
		if( size == 0) 
			throw new InvalidParameterException();	// Bos ArrayList i bosaltmaya calisma!!
		data = null;
		size = 0;
	}

	@Override
	public boolean contains(E e){				// liste bu E tipindeki e elemanini iceriyor mu.
		for( int i = 0; i < size; i++ ){
			if( data[i] == e )
				return true;
		}
		return false;
	}

	@Override
	public boolean containsAll(Collection<E> c){		// contains islemini tum collection icin yapar.
		Iterator <E> it = c.iterator();
		while(it.hasNext()){
			if( !this.contains(it.next()) ) 
				return false;
		}
		return true;
	}
	
	@Override
	public boolean isEmpty(){					// liste dolu mu bos mu kontrolu.
		if( size == 0 )
			return true;
		return false;
	}
	
	@Override
	public void remove(E e){
		for(int i = 0; i < size; i++){
  	      if(data[i] == e){			//silinecek elemanı sette bulma durumu
  	      	if( size == 1 ){
  	      		data = null;
  	      	}
  	      	else{
  	      		Object [] data_copy = new Object[size-1]; 
  	      		int k = 0;
				for( int j = 0; j < size; j++){		// eleman haric kopyalama.
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
	
	@Override
	public void removeAll(Collection<E> c){			// silme islemini tum collection icin yapar.
		Iterator <E> it = c.iterator();
		while(it.hasNext()){
			this.remove(it.next());
		}
		this.size = 0;
	}

	@Override
	public void retainAll(Collection<E> c){		// collection daki elemanlar haric olanları sil.
		Iterator <E> it = c.iterator();
		while(it.hasNext()){
			E temp = it.next();
			if( !contains(temp) )
			this.remove(temp);
		}
	}

	@Override
	public int	size(){						// size ' ı dondurur.
		return this.size;
	}
}