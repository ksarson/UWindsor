#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>

//Part 1
    //Structure
    struct X
    {
        double radius = 5;
        double *n; //Must be dynamically allocated below
        
        //Default Constructor (Add a double 3.14)
        X():
            n(new double(3.14))
        {}
        
        //Copy Constructor
        X(X const& x):
            n(x.n != nullptr ? new double(*x.n) : nullptr)
        {}
        
        //Copy Assignment Operator (Exception Safe)
        X& operator =(X const& x){
            if(this != &x)
            {
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
            
        // Move Assignment Operator (Prototype)
        X& operator =(X&&);
        
        // Destructor
        ~X()
        {
            delete n;
        }
        
        //Member Function
        double circ(){return 2*n*radius;}
    };
    
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
            
        if (!(lhs.x < rhs.x) && !(rhs.x < lhs.x))
            return lhs.y < rhs.y; 
            
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