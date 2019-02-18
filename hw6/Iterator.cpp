#include "Iterator.h"
#include "Collection.h"
#include <typeinfo>

namespace cpp{
	template <typename E>
	Iterator<E>::Iterator(vector<E> v){				// vector constructor.
		for ( int i = 0; i < v.size(); i++){		// argumani kendi member datasina kopyalar.
			iter.push_back(v.at(i));
		}
		indis = 0;
	}

	template <typename E>
	E Iterator<E>::operator*() {				// elemana erismek icin * operator.
		return iter[indis];
	}

	template <typename E>
	bool Iterator<E>::hasNext(){				// bir sonraki elemanin varligina bakar.
		if( typeid(string) == typeid(E) ){
			int size = iter.size() - 1;
			if(indis <= size)
				return true;
			return false;
		}
		else{
			int size = iter.size();
			if(indis < size)
				return true;
			return false;			
		}
	}

	template <typename E>
	E & Iterator<E>::next(){				// indisi arttirir.
		indis++;
	}

	template <typename E>
	E & Iterator<E>::remove(){
		if( iter.size() <= 0 ){			// son elemani siler.
			throw control();
		}
		E last = iter.last();
		iter.pop_back(); 
		indis--;
		return last;
	}	
}


