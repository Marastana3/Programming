class Main {

	public static void main(String[] args) {
		
		Human human1 = new Human("Rick",65,70);
		Human human2 = new Human("Morty",16,50);
			
		human1.drink();
		human2.eat();
		
	}
}
//******************************************************
class Human {

	String name;
	int age;
	double weight;
	
	Human(String name,int age,double weight){
		
		this.name = name;
		age = age;
		this.weight = weight;
	}
	
	void eat() {
		System.out.println(this.age+" is eating");
	}
	void drink() {
		System.out.println(this.name+" is drinking *burp*");
	}
		
}