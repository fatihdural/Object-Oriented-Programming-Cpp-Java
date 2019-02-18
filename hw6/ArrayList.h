#ifndef ARRAYLIST_H
#define ARRAYLIST_H
#include <list>
#include "List.h"

namespace cpp{
	template <typename E, typename collection_type>					// abstract List classindan inherit edilmis ArrayList class.
	class ArrayList : public List<E, collection_type> {
	public:
		ArrayList(){}
		ArrayList(E e);
		ArrayList(collection_type c);								// template de tanimlanmis typeleri constructorina alabilir.
		virtual Iterator<E> iterator();
		virtual void add(E e);	
		virtual void addAll(collection_type c);
		virtual void clear();
		virtual bool contains(E e);									// fonksiyonlar.
		virtual bool containsAll(collection_type c);
		virtual bool isEmpty();
		virtual void remove(E e);
		virtual void removeAll(collection_type c);
		virtual void retainAll(collection_type c);
		virtual int	size();
	private:
		list<E> array;
	};	
}
#endif