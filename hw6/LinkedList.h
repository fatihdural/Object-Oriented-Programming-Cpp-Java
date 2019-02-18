#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <queue>
#include "List.h"
#include "Queue.h"

namespace cpp{
	template <typename E, typename collection_type>					// abstract List ve Queue classindan inherit edilmis Linkedlist class.
	class LinkedList : public List<E, collection_type> , public Queue<E, collection_type> {
	public:
		LinkedList(){}
		LinkedList(E x);
		LinkedList(collection_type x);
		virtual Iterator<E> iterator();
		virtual void add(E e);
		virtual void addAll(collection_type c);					// template de tanimlanmis typeleri constructorina alabilir.
		virtual void clear();
		virtual bool contains(E e);
		virtual bool containsAll(collection_type c);
		virtual bool isEmpty();
		virtual void remove(E e);
		virtual void removeAll(collection_type c);				// fonksiyonlar.
		virtual void retainAll(collection_type c);
		virtual int	size();
		virtual E element();
		virtual void offer(E e);
		virtual E poll();	
	private:
		queue<E> linked;
	};	
}
#endif