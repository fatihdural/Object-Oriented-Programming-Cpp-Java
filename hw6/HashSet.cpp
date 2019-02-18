#include "HashSet.h"

namespace cpp{
	template <typename E,typename collection_type>
	Iterator<E> HashSet<E,collection_type>::iterator(){					// bir iterator olusturulup dondurulur.
		vector<E> iter;
		for( auto iterator = hash.begin(); iterator!=hash.end(); iterator++ ){	
			iter.push_back( *iterator );
		}
		Iterator<E> it(iter);
		return it;
	}


	template <typename E,typename collection_type>
	HashSet<E,collection_type>::HashSet(E e){
		add(e);
	}

	template <typename E,typename collection_type>
	HashSet<E,collection_type>::HashSet(collection_type c){
		addAll(c);
	}


	template <typename E,typename collection_type>
	void HashSet<E,collection_type>::add(E e){					// gelen eleman eklenir.
		hash.insert( hash.end(), e );
	}

	template <typename E,typename collection_type>
	void HashSet<E,collection_type>::addAll(collection_type c){				// container bir tip geldiginde eklenir.
		for( auto iterator = c.begin(); iterator!=c.end(); iterator++ ){	
			hash.insert( hash.end(), *iterator );
		}
	}

	template <typename E,typename collection_type>						// verilerin temizlenmesi, HashSet objesi bosalir.
	void HashSet<E,collection_type>::clear(){
		for (auto iterator = hash.begin(); iterator!=hash.end(); iterator++){
			hash.erase(iterator);
		}
	}

	template <typename E,typename collection_type>
	bool HashSet<E,collection_type>::contains(E e){							// bir elemanin objede olup olmadigi kontrolu.
		for( auto iterator = hash.begin(); iterator!=hash.end(); iterator++ ){
			if( *iterator == e){
				return true;
			}
		}	
		return false;
	}

	template <typename E,typename collection_type>						// bir container daki tum elemanlarin olup olmadiginin kontrolu.
	bool HashSet<E,collection_type>::containsAll(collection_type c){
		int count;
		auto iterator1 = hash.begin();
		auto iterator2 = c.begin();
		for( auto iterator2 = c.begin(); iterator2!=c.end(); iterator2++ ){
			for( auto iterator1 = hash.begin(); iterator1!=hash.end(); iterator1++ ){
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

	template <typename E,typename collection_type>
	bool HashSet<E,collection_type>::isEmpty(){				// obje bos mu kontrolu.
		if( hash.size() == 0 )
			return true;
		return false;
	}

	template <typename E,typename collection_type>
	void HashSet<E,collection_type>::remove(E e){			// herhangi bir elemanin cikartilmasi.
		if( this->isEmpty() ){
			throw control();
		}
		for( auto iterator = hash.begin(); iterator!=hash.end(); iterator++ ){
			if( (*iterator) == e ){
				hash.erase(iterator);
			}
		}
	}

	template <typename E,typename collection_type>
	void HashSet<E,collection_type>::removeAll(collection_type c){			// bir containerdaki tum elemanlarin objeden cikartilmasi.
		if( this->isEmpty() ){
			throw control();
		}		
		for( auto iterator2 = c.begin(); iterator2!=c.end(); iterator2++ ){
			for( auto iterator = hash.begin(); iterator!=hash.end(); iterator++ ){
				if( (*iterator) ==  *iterator2){
					hash.erase(iterator);
					break;
				}
			}
		}	
	}

	template <typename E,typename collection_type>
	void HashSet<E,collection_type>::retainAll(collection_type c){ 			// bir containerda bulunan elemanlar haric cikartma islemi yapilmasi.
		for( auto iterator2 = c.begin(); iterator2!=c.end(); iterator2++ ){
			for( auto iterator = hash.begin(); iterator!=hash.end(); iterator++ ){
				if( (*iterator) !=  *iterator2){
					hash.erase(iterator);
					break;
				}
			}
		}	
	}

	template <typename E,typename collection_type>					// obje icindeki veri adeti.
	int	HashSet<E,collection_type>::size(){
		return hash.size();
	}	
}
