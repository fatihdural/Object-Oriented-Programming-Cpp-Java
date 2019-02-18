#ifndef COLLECTION_H
#define COLLECTION_H
#include "Iterator.h"

class control : public exception{ // exception class.
	public:
		void hata(){
			cout << "Invalid operation!!" << endl;
		}
};

namespace cpp{
	template <typename E, typename collection_type> // template Collection class.
	class Collection{
	public:
		Collection(){}
		virtual Iterator<E> iterator() = 0;		// fonksiyonlar pure virtual oldugundan, class abstracttir.
		virtual void add(E e) = 0;
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
