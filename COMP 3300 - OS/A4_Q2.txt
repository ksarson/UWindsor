class PizzaShop{
	public:
		void Enter(); 
		void Finish();
	private:
		int ticket;
		Semaphore mutex; //Control access to shared variables
		Semaphore servers; //Sales people
}

PizzaShop::PizzaShop(int n){
	ticket = 0;
	mutex.value = 1;
	servers.value = n; //Number of Sales people
}

PizzaShop::Enter(){
	mutex.Wait();
	ticket++;
	mutex.Signal();
	servers.Wait();
}

PizzaShop::Finish(){
	servers.Signal();
}