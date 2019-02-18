#include "HashSet.cpp"
#include "ArrayList.cpp"
#include "LinkedList.cpp"
#include "Iterator.cpp"
#include "Collection.h"
#include <list>
#include <set>

using namespace cpp;

int main()
{
	try{
		vector<int> vect_int; 			// bazi stl containerler olusturuldu.
		vect_int.push_back(1);
		vect_int.push_back(3);
		vect_int.push_back(3);			
		vect_int.push_back(5);
		vect_int.push_back(7);
		vector<string> vect_str;
		set<int> set_int;
		set<string> set_str;
		list<int> list_int;
		list<string> list_str;

		HashSet<int, vector<int>> h1(vect_int); // HashSet class indan bir obje olusturuldu. // vector de 3 2 kez bulundugundan 1 defa 3 eklenir.
		h1.add(5); // hashset de bulundugundan eklemez.
		h1.add(0);
		h1.add(100);
		h1.add(1000);
		cout << "HashSet<int, vector<int>> h1(vect_int) objesi olusturuldu." << endl; 
		cout << "h1 objesi : "; 
		for ( auto it = h1.iterator(); it.hasNext(); it.next() ){
			cout << *it << " ";
		}
		cout << endl;
		cout << "h1 objesi size : " << h1.size() << endl;

		if( h1.contains(100) ){ // 100 var mi 
			cout << "100 sayisi mevcut" << endl;
		}

		if( h1.isEmpty() ) // obje dolu oldugundan girmez.
			cout << "HashSet bostur." << endl;
		h1.remove(100); // 100 sayisini kaldirdik.

		if( !h1.contains(100))
			cout << "100 sayisi kaldiriltiktan sonra, yeni size : " << h1.size() << endl; // 100 sayisi kaldiriltiktan sonra size.

		vector<int> vect_int_t;
		vect_int_t.push_back(1);
		vect_int_t.push_back(3); // icinde 1 ve 3 olan bir vectoru removeAll fonksiyonuna gonderildiginde.

		h1.removeAll(vect_int_t);
		cout << "removeAll ile 1 ve 3 silindikten sonra yeni size : " << h1.size() << endl; // 1 ve 3 silinir size azalir.
		cout << "Obje icindekiler(with iterator) : ";

		for ( auto it = h1.iterator(); it.hasNext(); it.next() ){
			cout << *it << " ";
		}
		cout << endl;
		cout << "------------------------------------------------" << endl << endl;

		HashSet<string, set<string>> h2(set_str); // stringlerden olusan bir h2 hashset objesi olusturulur.
		cout << "HashSet<string, set<string>> h2(set_str) objesi olusturuldu." << endl;
		set_str.insert(set_str.begin(), "a"); 
		set_str.insert(set_str.begin(), "b"); 
		set_str.insert(set_str.begin(), "a"); 
		set_str.insert(set_str.begin(), "x"); 
		set_str.insert(set_str.begin(), "y"); 
		cout << "a b a x y iceren bir kume HashSet' e arguman olarak verildi." << endl;

		h2.addAll(set_str); // addAll ile tum vector hashset objesine eklendi.
		cout << "h2 objesi : "; 
		for ( auto it = h2.iterator(); it.hasNext(); it.next() ){
			cout << *it << " ";
		}
		cout << endl;	
		cout << "HashSette 'a' bir kez yazildigina dikkat etmek gerekir." << endl;
		cout << "h2 objesi size : " << h2.size() << endl;
		cout << "x ve y mevcut mu ?" << endl;

		if( h2.contains("x") && h2.contains("y") ){
			cout << "x ve y mevcut" << endl;
		}
		h2.remove("x");			
		cout << "x silindikten sonra obje : ";
		for ( auto it = h2.iterator(); it.hasNext(); it.next() ){
			cout << *it << " ";
		}
		cout << endl;	
		cout << "x silindikten sonra size : " << h2.size() << endl;
		cout << "------------------------------------------------" << endl << endl;
		ArrayList<int, set<int>> a1(set_int);
		cout << "ArrayList<int, set<int>> a1(set_int) objesi olusturuldu." << endl;
		a1.add(15);
		a1.add(25);
		a1.add(15);
		a1.add(35);
		a1.add(15);

		cout << "15 25 15 35 15 sirasiyla add fonksiyonu cagirildi. " << endl;

		cout << "a1 objesi : "; 
		for ( auto it = a1.iterator(); it.hasNext(); it.next() ){
			cout << *it << " ";
		}
		cout << endl;

		if( a1.contains(35) ){ 
			cout << "35 sayisi mevcut, size : " << a1.size() << endl;
		}

		if( a1.isEmpty() ) // obje dolu oldugundan girmez.
			cout << "ArrayList bostur." << endl;

		cout << "Obje icindekiler(with iterator) : ";

		for ( auto it = a1.iterator(); it.hasNext(); it.next() ){
			cout << *it << " ";
		}
		cout << endl;
		cout << "------------------------------------------------" << endl << endl;
		ArrayList<string, list<string>> a2(list_str); // stringlerden olusan bir a2 hashset objesi olusturulur.
		cout << "ArrayList<string, list<string>> a2(list_str) objesi olusturuldu." << endl;
		list_str.insert( list_str.end(), "fatih"); 
		list_str.insert( list_str.end(), "dural");
		list_str.insert( list_str.end(), "trabzon");
		list_str.insert( list_str.end(), "151044041");

		a2.addAll(list_str); // addAll ile tum set hashset objesine eklendi.
		cout << "Obje icindekiler(with iterator) : ";
		for ( auto it = a2.iterator(); it.hasNext(); it.next() ){
			cout << *it << " ";
		}
		cout << endl;	
		cout << "size : " << a2.size() << endl;
		cout << "fatih mevcut mu ?" << endl;

		if( a2.contains("fatih") ){
			cout << "fatih mevcut" << endl;
		}
		else
			cout << "fatih mevcut degil" << endl;
		a2.clear();
		cout << "clear() fonksiyonu kullanildi. " << endl;

		if( a2.isEmpty() ){
			cout << "obje artik bostur, size : " << a2.size() << endl;
		}
		cout << "------------------------------------------------" << endl << endl;

		LinkedList<int, list<int>> l1(list_int);
		cout << "LinkedList<int, list<int>> l1(list_int) objesi olusturuldu." << endl;
		cout << "10 20 30 40 50 60 70 80 90 100 ekleniyor.. " << endl;
		l1.add(10); l1.add(20); l1.add(30); l1.add(40); l1.add(50); 
		l1.add(60); l1.add(70); l1.add(80); l1.add(90); l1.add(100);
		cout << "Obje icindekiler(with iterator) : ";
		for ( auto it = l1.iterator(); it.hasNext(); it.next() ){
			cout << *it << " ";
		}
		cout << endl;	
		cout << "Suan size : " << l1.size() << endl;
		cout << "l1.element() : " << l1.element() <<endl;
		l1.poll();
		l1.poll();
		cout << "poll() fonk. 2 kez cagirildi" << endl;
		cout << "Obje icindekiler(with iterator) : ";
		for ( auto it = l1.iterator(); it.hasNext(); it.next() ){
			cout << *it << " ";
		}
		cout << endl;
		cout << "Yeni size : " << l1.size() << endl;
		cout << "------------------------------------------------" << endl << endl;
		LinkedList<string, vector<string>> l2(vect_str); // stringlerden olusan bir a6 LinkedList objesi olusturulur.

		cout << "LinkedList<string, vector<string>> l2(vect_str) objesi olusturuldu." << endl;
		vect_str.push_back("C");
		vect_str.push_back("S");
		vect_str.push_back("E");
		vect_str.push_back("2");
		vect_str.push_back("4");
		vect_str.push_back("1");

		l2.addAll(vect_str); // addAll ile tum list LinkedList objesine eklendi.
		cout << " 'C' 'S' 'E' '2' '4' '1' stringleri bir list'e atilip addAll ile l2 objesine eklendi." << endl;
		cout << "Obje icindekiler(with iterator) : ";
		for ( auto it = l2.iterator(); it.hasNext(); it.next() ){
			cout << *it << " ";
		}
		cout << endl;
		cout << "size : " << l2.size() << endl;
		cout << "E mevcut mu ?" << endl;

		if( l2.contains("E") ){
			cout << "E mevcut" << endl;
		}
		else{
			cout << "E mevcut degil" << endl;
		}
		l2.poll();			
		cout << "poll() fonk. kullandiktan sonra size : " << l2.size() << endl;
		cout << "Obje icindekiler(with iterator) : ";
		for ( auto it = l2.iterator(); it.hasNext(); it.next() ){
			cout << *it << " ";
		}
		cout << endl;
		l2.clear();
		cout << "clear() fonksiyonu kullanildi. " << endl;
		if( l2.isEmpty() ){
			cout << "obje artik bostur, size : " << l2.size() << endl;
		}
		cout << "------------------------------------------------" << endl;			
	}
	catch(control i){
		i.hata();
	}
	return 0;
}