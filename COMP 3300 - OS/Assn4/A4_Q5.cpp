enum Direction{North, South};

class Tunnel{
	public:
		Arrive(Direction dir); 
		Depart(Direction dir);
	private:
		Lock lock;
		CVar goNorth, goSouth;
		int northWait; //Waiting to go north
		int southWait; //Waiting to go south
		int northBound; //Going north in Tunnel
		int southBound; //Going south in Tunnel
}

Tunnel::Tunnel(){
	lock.value = 1; //Lock for shared variables is available
	northWait = 0; //Nobody waiting
	southWait = 0; //Nobody waiting
	northBound = 0; //Nobody in tunnel
	southBound = 0; //Nobody in tunnel
}

Tunnel::Arrive(Direction dir){
	lock.Wait();
	//If no one in the tunnel, car goes
	if ((northBound > 0) || (southBound > 0)){ 
		if (dir == North){
			//If no one is waiting to go south, car goes north
			if ((southWait > 0) || (southBound > 0)){
				//Otherwise, we count north waiters, and wait for a signal
				northWait++;
				goNorth.Wait(lock);
				northWait--;
			}
			else{
				//If no one is waiting to go north, car goes south
				if ((northWait > 0) || (northBound > 0)){
					southWait++;
					goSouth.Wait(lock);
					southWait--;
				}
			}
		}
		//Count how many cars are in the tunnel
		if (dir == North) 
			northBound++;
		else 
			southBound++;
		lock.Signal();
	}
}

//When a northbound car departs, we signal all southbound cars if any
//are waiting only if no northbound cars are in the tunnel. Similarly,
//when a southbound car departs. Note, in the Arrive routine above
//the car only waits if a car going the other direction is in the tunnel.
Tunnel::Depart(Direction dir){
	lock.Wait();
	if (dir == North){
		northBound--;
		if (southWait > 0){
			if (northBound == 0)
				goSouth->Broadcast();
			}
		}
	else{
	southBound--;
		if (northWait > 0){
			if (southBound == 0)
				goNorth.Broadcast();
		}
	}
	lock.Signal();
}