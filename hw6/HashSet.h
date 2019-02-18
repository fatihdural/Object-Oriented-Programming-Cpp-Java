#ifndef HASHSET_H
#define HASHSET_H
#include <set>
#include "Set.h"

namespace cpp{
	template <typename E, typename collection_type>					// abstract set classindan inherit edilmis HashSet class.
	class HashSet : public Set<E, collection_type>{
	public:
		HashSet(){}
		HashSet(E e);											// template de tanimlanmis typeleri constructorina alabilir.
		HashSet(collection_type c);
		virtual Iterator<E> iterator();
		virtual void add(E e);						
		virtual void addAll(collection_type c);					// fonksiyonlar.
		virtual void clear();
		virtual bool contains(E e);
		virtual bool containsAll(collection_type c);
		virtual bool isEmpty();
		virtual void remove(E e);
		virtual void removeAll(collection_type c);
		virtual void retainAll(collection_type c);
		virtual int	size();
	private:
		set<E> hash;
	};	
}
#endif