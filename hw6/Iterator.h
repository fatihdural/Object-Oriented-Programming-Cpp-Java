#ifndef ITERATOR_H
#define ITERATOR_H
#include <iostream>
#include <vector>

using namespace std;
namespace cpp{
	template <typename E>  // helper iterator class.
	class Iterator
	{
	public:
		Iterator(){}
		Iterator(vector<E> v);
		bool hasNext();
		E & next();
		E & remove();
		E operator*();		
	private:
		vector<E>iter;   	// verileri bir vektorde tutar.
		int indis;
	};	
}
#endif