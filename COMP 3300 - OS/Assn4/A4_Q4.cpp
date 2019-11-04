class shoeShine{
      public:
            void Customer();
      private:
            Semaphore Customers = 0; 
            Semaphore shoeShine = 0; 
            Mutex Seats = 1; 
            int FreeSeats = N;
} 
  
shoeShine::shoeShine(){ 
      while(true) { 
            //Waits for a customer (sleeps)
            down(Customers); 
            //Mutex to protect the number of available seats
            down(Seats); 
            //A chair gets free
            FreeSeats++;        
            //Bring up customer for shine
            up(shoeShine);    
            //Release the mutex on the chair
            up(Seats); 
            //shoeShine is shining
      } 
} 
  
shoeShine::Customer(){ 
      while(true){ 
            /*Protects seats so only 1 customer tries to sit 
            in a chair if that's the case*/
            down(Seats); 
            if(FreeSeats > 0){ 
                  //Sitting down
                  FreeSeats--; 
                  //Notify the shoeShine
                  up(Customers); 
                  //Release the lock
                  up(Seats); 
                  //Wait in the waiting room if shoeShine is busy
                  down(shoeShine); 
                  //Customer is having shine
            } 
            else{ 
                  //Release the lock
                  up(Seats); 
                  //Customer leaves 
            } 
      } 
} 