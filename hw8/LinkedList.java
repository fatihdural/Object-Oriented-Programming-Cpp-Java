import java.security.InvalidParameterException;

/**
 *
 * @author fatih dural
 */

public class LinkedList<E> implements List<E>, Queue<E>
{
	private Object [] data;
	private int size = 0;

	@Override
	public Iterator<E> iterator(){								// kume icindeki datalari iceren bir iterator dondurur.
		Iterator <E> it = new Iterator<E>(data, size);
		return it;
	}

	@Override
	public void add(E e){
		Object [] data_copy = new Object[size + 1];				// sira yapisina uygun sekilde ekleme yap. data[0] head of queue.
		for( int i = 0; i < size; i++){
			data_copy[i] = data[i];
		}
		data_copy[size] = (Object) e;
		data = null;
		data = data_copy;
		size++;
	}

	@Override
	public void addAll(Collection<E> c){					// ekleme islemini tum collection icin yapar.
		Iterator <E> it = c.iterator();
		while(it.hasNext()){
			this.add(it.next());
		}
	}

	@Override
	public void clear(){
		if( size == 0) 
			throw new InvalidParameterException(); 	// Bos listeyi bosaltmaya calisma!!
		data = null;
		size = 0;
	}

	@Override
	public boolean contains(E e){					// bu sira e elemanini iceriyor mu.
		for( int i = 0; i < size; i++ ){
			if( data[i] == e )
				return true;
		}
		return false;
	}

	@Override
	public boolean containsAll(Collection<E> c){			// tum collection icin uygulanmasi.
		Iterator <E> it = c.iterator();
		while(it.hasNext()){
			if( !this.contains(it.next()) ) 
				return false;
		}
		return true;
	}
	
	@Override
	public boolean isEmpty(){						// yapi dolu mu bos mu kontrolu.
		if( size == 0 )
			return true;
		return false;
	}
	
	@Override
	public void remove(E e){						// sadece bastan siler.
		if( data[0] != e ){
			throw new InvalidParameterException();
		}
		for(int i = 0; i < size; i++){
  	      if(data[i] == e){					//silinecek elemanı sette bulma durumu
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
        size--; 	// size 'ı azalt
	}
	
	@Override
	public void removeAll(Collection<E> c){		// silme islemini collection da ki tum elemanlar icin yap.
		Iterator <E> it = c.iterator();
		while(it.hasNext()){
			this.remove(it.next());
		}
		this.size = 0;
	}

	@Override
	public void retainAll(Collection<E> c){		// collection daki elemanlar haric silme islemi yap.
		Iterator <E> it = c.iterator();
		while(it.hasNext()){
			E temp = it.next();
			if( !contains(temp) )
			this.remove(temp);
		}
	}

	@Override
	public int	size(){						// size i dondur.
		return this.size;
	}

	@Override
	public E element(){						// siranin basini dondur.
		@SuppressWarnings("unchecked") E temp = (E) data[0];
		return temp;
	}

	@Override
	public void offer(E e){					// eleman ekleme
		this.add(e);
	}

	@Override @SuppressWarnings("unchecked")
	public E poll(){						// siranin basini sil ve silinecek elemani dondur.
		if( size == 0)
			throw new InvalidParameterException();
		E temp = (E) data[0];
		this.remove((E) data[0]);
		return temp;
	}
}