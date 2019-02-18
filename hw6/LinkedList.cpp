#include "LinkedList.h"

namespace cpp{
	template <typename E,typename collection_type>
	LinkedList<E,collection_type>::LinkedList(E e){
		add(e);
	}

	template <typename E,typename collection_type>
	LinkedList<E,collection_type>::LinkedList(collection_type c){
		addAll(c);
	}

	template <typename E,typename collection_type>
	Iterator<E> LinkedList<E,collection_type>::iterator(){					// bir iterator olusturulup dondurulur.
		vector<E> iter;
		queue<E> linked_t = linked;
		for ( int i = 0; i < linked.size(); i++){
			iter.push_back( linked_t.front() );
			linked_t.pop(); 
		}
		Iterator<E> it(iter);
		return it;
	}

	template <typename E,typename collection_type>							// gelen eleman eklenir.
	void LinkedList<E,collection_type>::add(E e){
		linked.push(e);	
	}

	template <typename E,typename collection_type>
	void LinkedList<E,collection_type>::addAll(collection_type c){			// container bir tip geldiginde eklenir.
		for( auto iterator = c.begin(); iterator!=c.end(); iterator++ ){	
			linked.push(*iterator);
		}
	}

	template <typename E,typename collection_type>
	void LinkedList<E,collection_type>::clear(){					// verilerin temizlenmesi, HashSet objesi bosalir.
		while (!linked.empty()){
			linked.pop();
		}
	}

	template <typename E,typename collection_type>
	bool LinkedList<E,collection_type>::contains(E e){				// bir elemanin objede olup olmadigi kontrolu.
		queue<E> linked_t(linked);
		while (!linked_t.empty()){
			if( linked_t.front() == e ){
				return true;
			}
		    linked_t.pop();
		}
		return false;
	}

	template <typename E,typename collection_type>
	bool LinkedList<E,collection_type>::containsAll(collection_type c){		// bir container daki tum elemanlarin olup olmadiginin kontrolu.
		int count;	
		for( auto iterator = c.begin(); iterator!=c.end(); iterator++ ){
			queue<E> linked_t(linked);
			while (!linked_t.empty()){
				if( linked_t.front() == *iterator ){
					count++;
				}
			    linked_t.pop();
			}		
		}
		if ( count == c.size() ){
			return true;
		}
		return false;
	}

	template <typename E,typename collection_type>
	bool LinkedList<E,collection_type>::isEmpty(){				// obje bos mu kontrolu.
		return linked.empty();
	}

	template <typename E,typename collection_type>
	void LinkedList<E,collection_type>::remove(E e){
		if( linked.front() == e ){							// herhangi bir elemanin cikartilmasi.
			linked.pop();
		}
		else{
			throw control();	
		}
	}

	template <typename E,typename collection_type>
	void LinkedList<E,collection_type>::removeAll(collection_type c){
		for( auto iterator = c.begin(); iterator!=c.end(); iterator++){
			if( linked.front() == *iterator ){								// bir containerdaki tum elemanlarin objeden cikartilmasi.
				linked.pop();
			}
			else{
				throw control();
				break;
			}
		}
	}

	template <typename E,typename collection_type>
	void LinkedList<E,collection_type>::retainAll(collection_type c){
		for( auto iterator = c.begin(); iterator!=c.end(); iterator++){
			if( linked.front() != *iterator ){								// bir containerda bulunan elemanlar haric cikartma islemi yapilmasi.
				linked.pop();
			}														
			else{
				throw control();
				break;
			}
		}
	}	

	template <typename E,typename collection_type>					// obje icindeki veri adeti.
	int	LinkedList<E,collection_type>::size(){
		return linked.size();
	}

	template <typename E,typename collection_type>
	E LinkedList<E,collection_type>::element(){				// last element return edilmesi.
		return linked.front();
	}

	template <typename E,typename collection_type>
	void LinkedList<E,collection_type>::offer(E e){				// eleman eklenmesi.
		linked.push(e);
	}

	template <typename E,typename collection_type>				// son elemanin dondurulup, cikartilmasi.
	E LinkedList<E,collection_type>::poll(){
		if( linked.empty() ){
			throw control();
		}
		E temp = linked.front();
		linked.pop();
		return temp;
	}	
}
