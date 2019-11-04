/*Part I: Multiple Choice, True/False, Fill-In-The-Blank & Short Answer Questions (mostly short answer)
	The questions in this section are largely conceptual*/
		//moves/copies,
		default constructor
    	Silly();

		move constructor
   		Silly(Silly&&);

		copy constructor
    	Silly(Silly const&);

		copy assignment operator 
    	Silly& operator =(Silly const&);

		move assignment operator 
   		Silly& operator =(Silly&&);

		destructor 
    	~Silly();
		
		//be able to explain differences between macros and templates,
		macros: more primitive, cant check data type of arguments, expanded in preprocessing phase
          #define GETMAX(a,b) ((a)>(b)?(a):(b))
          #define MAX 10;
          #define ADD(x,y) ((x) + (y))
      
    	templates: used in generics to make type-free code
        	//Format
          	template <class identifier> function_declaration;
			OR
          	template <typename identifier> function_declaration;

			//Example
            template <class myType>
            myType GetMax (myType a, myType b) {
            return (a>b?a:b);
            }
            
			//Usage
            int x,y;
			GetMax <int> (x,y);

			//How it works
			template <class int>
            int GetMax(int a, int b) {
            return (a>b?a:b);
            }
	            
		//object-oriented programming concepts (e.g., virtual-related topics),
		#include <iostream>
        using namespace std;
      	class base 
        {
        public:
            virtual void print()
            {
                cout << "Print Base Class\n";
            }
          	//pure virtual function (Alternative to abstract function in java)
          	virtual int func() = 0;
        };
        class derived : public base 
        {
        public:
            void print()
            {
                cout << "Print Derived Class\n";
            }
        };
        void printClass(base *b)
        {
            b->print();
        }
        int main() 
        {
            base *x = new base;
            derived *y = new derived;
            printClass(x);
            printClass(y);
          	y->print();
            return 0;
        }
    
        //be able to explain (high-level, e.g., in terms of < (less than)) total order v. strict order semantics + SWO equivalence,
        When (a < b) is false and the semantic rules applied to < are those of a total linear order, then does that
        logically imply or constrain in any way the possible result(s) of the valuation of (b < a)? Explain. [4 marks]
        	If (a < b) is false, then (a >= b) must be true in a total linear order.
        	Thus, (b < a)’s valuation can be true (if a != b) or false (if a == b).
        	A total linear order requires if !(a <= b) then (b <= a)

        When (a < b) is false and the semantic rules applied to < are those of a strict weak order, then does that
        logically imply or constrain in any way the possible result(s) of the valuation of (b < a)? Explain. [4 marks]
        	If (a < b) is false under SWO, this implies nothing about (b < a) which can also be false.
        	(The reverse is not true, if (a < b) is true, then (b < a) must be false.)
        	This is why equivalence is defined as !(a < b) && !(b < a).
      
        /*know what the high-level conceptual representations and differences are amongst std::vector<T>, std::list<T>, std::forward_list<T>, std::deque<T>, 
        std::set<T> and std::multiset<T> + unordered variants, and, std::map<K,V> and std::multimap<K,V> + unordered variants*/
        vector<T> - 		like an array, contiguous memory
							insert/delete not efficient, random access possible
                            
        list<T> - 			doubly linked list, non-contiguous memory 
							insert/delete more efficient than vectors, random access not possible
                            
        forward_list<T> - 	singly linked list, non-contiguous memory
        					insert/delete more efficient than vectors and lists, random access not possible
        
        deque<T> - 			double ended queue sequence containers, like an array, contiguous memory not guaranteed
							insert/delete more efficient than vectors but less than lists, random access possible
                            
        set<T> - 			containers which each element is unique, value cannot be modified once added to set, the value is the key
         					has SWO, slower direct access but more efficient range iteration
        
        UO set<T> -			containers which each element is unique, value cannot be modified once added to set, the value is the key	
        					has no ordering, faster direct access, less efficient range iteration
        
        multiset<T> - 		multiple elements can have same value, value cannot be modified once added to multiset, the value is the key
        					has SWO, slower direct access, more efficient range iteration
        
        UO multiset<T> - 	multiple elements can have same value, value cannot be modified once added to multiset, the value is the key
        					has no ordering, faster direct access, less efficient range iteration
        
        map<K,V> - 			containers which each key is unique, the value is different than the key
         					has SWO, slower direct access by key, more efficient range iteration
        
        UO map<K,V> -		containers which each key is unique, the value is different than the key
         					has no ordering, faster direct access by key, less efficient range iteration
        
        multimap<K,V> -		multiple values can have same key, the value is different than the key
        					has SWO, slower direct access, more efficient range iteration 
        
        UO multimap<K,V> -	multiple values can have same key, the value is different than the key
        					has no ordering, faster direct access, less efficient range iteration 
    
/*Part II: Coding (single class and related functions)
	Recall that Midterm 2 was not done well with respect to C++ class' specially named functions, etc. This section very specifically addresses such.
	This section also has everyone calling/implementing things I said in the last class including operator overloads.*/
	//Be able to use std::copy() and std::fill().
    
    std::fill()
    assigns value to all elements in range [begin, end)
    vector<int> vect(8);
    //Calling fill to initialize values in the range to 4 
    fill(vect.begin() + 2, vect.end() - 1, 4);
    //0 0 4 4 4 4 4 0
    int array[5] ={1, 2, 3, 4, 5};   
                                            
    std::copy()                    
    copy(array+1, array+4, vect.begin());
    //2 3 4
        
    //Defining constructors and assignment operators                                        
    struct X
    {
        double radius = 5;
        double *n; //Must be dynamically allocated below
        
        //Default Constructor (Add a double 3.14)
        Vector():
            n(new double(3.14))
        {}
        
        //Copy Constructor
        X(X const& x):
            n(x.n != nullptr ? new double(*x.n) : nullptr)
        {}
        
        //Copy Assignment Operator (Exception Safe)
        X& operator =(X const& x){
            if(this != &x){
            	using std::swap;
                X tmpX(x); //Make copy
                //Swap tmpX.n with this->n...
                swap(this->n, tmpX.n);
                //And tmpX destructor will destroy its n (which is what was in X)
            }
            return *this;
        }
        
        //Move Constructor
        X(X&& x) :
            n(x.n)
        {
            x.n = nullptr;
        }
            
        // Move Assignment Operator
        X& operator =(X&& x){
          if (this != &x){
            double *tmp = n; // Save old n pointer value
            n = x.n; // Copy x.n into n
            x.n = nullptr; // Null out x.n
            delete tmp; // Free memory tied to tmp
          }
        return *this;
        }
        
        // Destructor
        ~X()
        {  delete n; }
        
        //Member Function
        double circ(){return 2*n*radius;}
    };
    
    //Calling constructors
    int main(void){
        //Default
        	X a;
        //Copy
        	X b(a);
        //Copy Assignment
        	X c, d;
        	c = d;
        //Move
        	X b(X{});
        //Move Assignment
       		X c, d;
        	c = X{};
        //Member Function Call
        	double circumference = a.circ();
    }
    
    //I/O overload
  	istream& operator >>(istream& is, employee& e)
    {
      return is >> e.id >> e.name >> e.salary;
    }
    cin >> e  
    
    //+=Operator overlord >:)
    tally_predicate& operator +=(tallypredicate const& rhs)
    {
      this->n += rhs.n;
      this->true += rhs.true_;
      return *this;
    }
              
/*Part III: General Coding
	This is a very short, straight-forward coding task.
*/
 
/* 
Concerning Part II:
Ensure you can write constructors, member functions, operator overloads, etc. 
--including the specially named constructors and the stream I/O bitshift operator overloads.
Part II asks you to write the code for a container class. You are provided the type aliases (typedefs) required, e.g., iterator, 
as well as the definitions of begin() and end() for this class to be a container class (assuming all of the code you write is present). 
So your task is straight-forward to do. The data structure is very well-known, i.e., it is one you are all very familiar with, 
and Part II is similar to code you've seen and have been asked to write before. This is a snippet of some of the provided code in Part II (do try writing some code as part of your studying):
  using value_type = double;
  using size_type = std::size_t;
  using reference = value_type&;
  using const_reference = value_type const&;
  using difference_type = std::ptrdiff_t;
  using iterator = double*;
  using const_iterator = double const*;
  iterator begin() { return ptr_; }
  const_iterator begin() const { return ptr_; }
  const_iterator cbegin() const { return ptr_; }
  iterator end() { return ptr_ ? ptr_+size_ : ptr_; }
  const_iterator end() const { return ptr_ ? ptr_+size_ : ptr_; }
  const_iterator cend() const { return ptr_ ? ptr_+size_ : ptr_; }
*/
                                  
                                            
//Midterm 2 code
#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>

//Part 2
    //Structure
    struct point 
    { 
        int x; 
        int y; 
        std::string data; 
    }

    //Define '<' for points
    bool operator <(point lhs, point rhs)
    {   
        if (lhs.x < rhs.x)
            return true;
            
        if (!(lhs.x < rhs.x) && !(rhs.x < lhs.x))  //Equivalent to lhs.x = rhs.x
            return lhs.y < rhs.y; //RECURSI)O
            
        return false;
       
    }
    
    //One-dimensional
    [](int a, int b){return a < b;}
    std::vector<int> numbers;
    std::stable_sort(numbers.begin(),numbers.end(),[](int a, int b){return a < b;});
    std::for_each(numbers.begin(), numbers.end(), [](auto e){std::cout<<e;});
    
    //Two-Dimensional
    [](point a, point b){return a < b;}
    std::vector<point> coordinates;
    std::stable_sort(coordinate.begin(),coordinates.end(),[](point a, point b){return a < b;});
    std::for_each(coordinates.begin(), coordinates.end(), [](auto e){std::cout<<e;});
    
    //std::ostream output operator <<()
    ostream& operator <<(ostream& os, coordinates const& c)
    {
      return os << ' ' << c.x << ' ' << c.y;
    }

    //Passing lambda function to an algorithm
    std::sort(numbers.begin(), numbers.end(), [](int a, int b){return a < b;});

    //Throw exception for empty vector
    if(numbers.empty())
        throw "Empty vector";