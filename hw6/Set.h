#ifndef SET_H
#define SET_H

#include "Collection.h"
namespace cpp{
	template <typename E, typename collection_type> 			// Collection dan inherit edilmis abstract set class.
	class Set : public Collection<E, collection_type>{
	public:
		Set(){}
		virtual Iterator<E> iterator() = 0;
		virtual void add(E e) = 0;								// fonksiyonlar pure virtual.
		virtual void addAll(collection_type c) = 0;
		virtual void clear() = 0;
		virtual bool contains(E e) = 0;
		virtual bool containsAll(collection_type c) = 0;
		virtual bool isEmpty() = 0;
		virtual void remove(E e) = 0;
		virtual void removeAll(collection_type c) = 0;
		virtual void retainAll(collection_type c) = 0;
		virtual int	size() = 0;
	};	
}
#endif