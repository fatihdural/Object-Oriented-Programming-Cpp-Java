import java.security.InvalidParameterException;

public class driverfile
{
	public static void main(String[] args) {
		try{
			System.out.println("\n--------------------HashSet--------------------");	
			// 	FOR INTEGER HASHSET

			HashSet<Integer> h1 = new HashSet<Integer>();
			System.out.println("h1 isimli HashSet<Integer> objesi olusturuldu. Size : " + h1.size());

			h1.add(10);
			h1.add(20); 
			h1.add(30);
			h1.add(40);
			h1.add(50);
			h1.add(50);		// Kumenin tanimi geregi bu 50 eklenmeyecek!!!!

			System.out.println("10 20 30 40 50 degerlerini set' e ekliyorum..");
			System.out.println("Bastan sonra elemanları bastırıyorum.");

			Iterator<Integer> iterh1 = h1.iterator();
			while(iterh1.hasNext()){
				System.out.printf("--%s--",iterh1.next());
			}

			System.out.println("\n30 degeri set de var mi ? ");

			if( h1.contains(30) ){
				System.out.println("--Yes--");
			}
			else{
				System.out.println("--No--");	
			}

			System.out.println("h1.remove(30)");
			h1.remove(30);

			System.out.println("30 degeri set de var mi ? ");

			if( h1.contains(30) ){
				System.out.println("--Yes--");
			}
			else{
				System.out.println("--No-- \nYeni size : " + h1.size());	
			}

			//	FOR STRING HASHSET

			HashSet<String> h2 = new HashSet<String>();
			System.out.println("\nh2 isimli HashSet<String> objesi olusturuldu. Size : " + h2.size());

			h2.add("FATIH");	// kume ozelligi geregi sadece 1 tane fatih eklenecek!!!
			h2.add("FATIH");
			h2.add("FATIH"); 
			h2.add("DURAL");
			h2.add("151044041");
			h2.add("TRABZON");

			Iterator<String> iterh2 = h2.iterator();
			while(iterh2.hasNext()){
				System.out.printf("--%s--",iterh2.next());
			}

			System.out.println("\n'TRABZON' stringi kumede mevcut mu ?");

			if( h2.contains("TRABZON") ){
				System.out.println("--Yes-- Size : " + h2.size());
			}
			else{
				System.out.println("--No--");
			}

			Collection<String> c1 = h2;
			System.out.println("Collection<String> tipinde, c1 isimli bir ust interface olusturdum.\nc1 = h2 ile polymorphism sagladim.");

			HashSet<String> h3 = new HashSet<String>();
			System.out.println("h3 isimli HashSet<String> objesi olusturuldu. Size : " + h3.size());

			h3.addAll(c1);
			System.out.println("h3.addAll(c1) ile interface in gosterdigi alt sinifdaki tum datalari h3 objesine ekleyecegim.");

			Iterator<String> iterh3 = h3.iterator();
			System.out.printf("%s %d\n","h3 size :", h3.size());

			while(iterh3.hasNext()){
				System.out.printf("--%s--",iterh3.next());
			}

			System.out.printf("\n%s %d\n","h3 size :", h3.size());

			System.out.println("\n--------------------ArrayList--------------------");

			//	 FOR INTEGER ARRAYLİST 

			ArrayList<Integer> a1 = new ArrayList<Integer>();
			System.out.println("a1 isimli ArrayList<Integer> objesi olusturuldu. Size : " + a1.size());

			Collection<Integer> c2 = a1;
			System.out.println("c2 isimli Collection<Integer> objesi olusturuldu. \nc2 = a1 islemi yapildi");

			c2.add(1);
			c2.add(2);
			c2.add(3);
			c2.add(4);
			c2.add(5);

			System.out.println("c2 uzerinden add metoduyla 1 2 3 4 5 degerleri eklendi. Size : " + c2.size());

			Iterator<Integer> itera1 = c2.iterator();
			while(itera1.hasNext()){
				System.out.printf("--%s--",itera1.next());
			}

			c2.remove(1);
			System.out.println("\nc2.remove(1)");

			itera1 = c2.iterator();
			while(itera1.hasNext()){
				System.out.printf("--%s--",itera1.next());
			}

			System.out.println("\nYeni size : " + c2.size());

			//	 FOR STRING ARRAYLIST

			ArrayList<String> a2 = new ArrayList<String>();
			System.out.println("\na2 isimli ArrayList<String> objesi olusturuldu." + a1.size());

			a2.add("GEBZE");
			a2.add("TEKNIK");
			a2.add("UNIVERSITESI");
			a2.add("BILGISAYAR");
			a2.add("MUHENDISLIGI");

			Iterator<String> itera2 = a2.iterator();
			while(itera2.hasNext()){
				System.out.printf("--%s--",itera2.next());
			}

			System.out.println("\nSize : " + a2.size());

			a2.clear();
			System.out.println("a2.clear()");

			if( a2.isEmpty() ){
				System.out.println("isEmpty ? : --Yes -- \n Size :  " + a2.size());
			}

			System.out.println("\n--------------------LinkedList--------------------");

			// FOR INTEGER LINKEDLIST 

			LinkedList<Integer> l1 = new LinkedList<Integer>();
			System.out.println("l1 isimli LinkedList<Integer> objesi olusturuldu.");

			l1.add(3);
			l1.add(6);
			l1.add(9);
			l1.add(12);
			l1.add(15);
			l1.add(12);
			l1.add(9);

			Iterator<Integer> iterl1 = l1.iterator();
			System.out.println("Sıra yapisi geregi ilk eklenen ilk, son eklenen en son okunur.");

			while(iterl1.hasNext()){
				System.out.printf("--%s--",iterl1.next());
			}

			System.out.println("\nSize : " + l1.size());
			
			l1.remove(3);
			System.out.println("l1.remove(3)");

			iterl1 = l1.iterator();

			while(iterl1.hasNext()){
				System.out.printf("--%s--",iterl1.next());
			}

			System.out.println("\nSize : " + l1.size());

			if( !l1.isEmpty() ){
				System.out.println("isEmpty ? --No--");
			}
			System.out.println("The head of queue - l1.element() : " + l1.element());

			// FOR STRING LINKEDLIST

			LinkedList<String> l2 = new LinkedList<String>();
			System.out.println("\nl2 isimli LinkedList<String> objesi olusturuldu.");

			l2.add("head");
			l2.add("elma");
			l2.add("armut");
			l2.add("portakal");
			l2.add("muz");
			l2.add("last");

			Iterator<String> iterl2 = l2.iterator();
			while(iterl2.hasNext()){
				System.out.printf("--%s--",iterl2.next());
			}

			System.out.println("\nSize : " + l2.size());
			System.out.println("l2.pool() call and returning element : " + l2.poll());

			iterl2 = l2.iterator();

			while(iterl2.hasNext()){
				System.out.printf("--%s--",iterl2.next());
			}

			System.out.println("\nLast size : " + l2.size());
		}
		catch(InvalidParameterException e)
		{
			System.out.printf("%s\n", "Invalid Parameter!!!!");
		}
		finally{
			System.out.println("********HW8 Completed - Fatih DURAL - 1510440041********");
		}
	}
}