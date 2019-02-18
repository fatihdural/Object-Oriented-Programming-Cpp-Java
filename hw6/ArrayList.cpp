#include "ArrayList.h"

namespace cpp{
	template <typename E,typename collection_type>
	ArrayList<E,collection_type>::ArrayList(E e){
		add(e);
	}

	template <typename E,typename collection_type>
	ArrayList<E,collection_type>::ArrayList(collection_type c){
		addAll(c);
	}

	template <typename E,typename collection_type>
	Iterator<E> ArrayList<E,collection_type>::iterator(){				// bir iterator olusturulup dondurulur.
		vector<E> iter;
		for( auto iterator = array.begin(); iterator!=array.end(); iterator++ ){	
			iter.push_back( *iterator );
		}	
		Iterator<E> it(iter);
		return it;
	}

	template <typename E,typename collection_type>						// gelen eleman eklenir.
	void ArrayList<E,collection_type>::add(E e){
		array.insert( array.end(), e );
	}

	template <typename E,typename collection_type>
	void ArrayList<E,collection_type>::addAll(collection_type c){		// container bir tip geldiginde eklenir.
			for( auto iterator = c.begin(); iterator!=c.end(); iterator++ ){	
				array.insert( array.end(), *iterator );
			}
	}

	template <typename E,typename collection_type>					// verilerin temizlenmesi, HashSet objesi bosalir.
	void ArrayList<E,collection_type>::clear(){
		array.clear();
	}

	template <typename E,typename collection_type>
	bool ArrayList<E,collection_type>::contains(E e){				// bir elemanin objede olup olmadigi kontrolu.
		for( auto iterator = array.begin(); iterator!=array.end(); iterator++ ){
			if( *iterator == e){
				return true;
			}
		}	
		return false;
	}

	template <typename E,typename collection_type>
	bool ArrayList<E,collection_type>::containsAll(collection_type c){		// bir container daki tum elemanlarin olup olmadiginin kontrolu.
		int count;
		auto iterator1 = array.begin();
		auto iterator2 = c.begin();
		for( auto iterator2 = c.begin(); iterator2!=c.end(); iterator2++ ){
			for( auto iterator1 = array.begin(); iterator1!=array.end(); iterator1++ ){
				if( *iterator1 == *iterator2 ){
					count++;
				}
			}
		}
		if ( count == c.size() ){
			return true;
		}
		return false;
	}

	template <typename E,typename collection_type>					// obje bos mu kontrolu.
	bool ArrayList<E,collection_type>::isEmpty(){
		if( array.size() == 0 )
			return true;
		return false;
	}

	template <typename E,typename collection_type>
	void ArrayList<E,collection_type>::remove(E e){				// herhangi bir elemanin cikartilmasi.
		if( this->isEmpty() ){
			throw control();
		}
		for( auto iterator = array.begin(); iterator!=array.end(); iterator++ ){
			if( (*iterator) == e ){
				array.erase(iterator);
			}
		}
	}

	template <typename E,typename collection_type>
	void ArrayList<E,collection_type>::removeAll(collection_type c){		// bir containerdaki tum elemanlarin objeden cikartilmasi.
		if( this->isEmpty() ){
			throw control();
		}		
		for( auto iterator = array.begin(); iterator!=array.end(); iterator++ ){
			auto iterator2 = c.begin();
			if( (*iterator) ==  *iterator2){
				array.erase(iterator);
				iterator2++;
				iterator = array.begin();
			}
		}
	}

	template <typename E,typename collection_type>
	void ArrayList<E,collection_type>::retainAll(collection_type c){			// bir containerda bulunan elemanlar haric cikartma islemi yapilmasi.
		auto iterator1 = array.begin();
		auto iterator2 = c.begin();
		for( auto iterator2 = c.begin(); iterator2!=c.end(); iterator2++ ){
			for( auto iterator1 = array.begin(); iterator1!=array.end(); iterator1++ ){
				if( *iterator1 != *iterator2 ){
					array.erase(iterator1);
				}
			}
		}	
	}

	template <typename E,typename collection_type>
	int	ArrayList<E,collection_type>::size(){						// obje icindeki veri adeti.
		return array.size();
	}
}
