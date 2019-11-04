#include <iostream>

using namespace std;

template< class T> class vector 
{
public:
	using value_type = T;
	using size_type = size_t;
	using reference = value_type&;
	using const_reference = value_type const&;
	using difference_type = ptrdiff_t;
	using iterator = T*;
	using const_iterator = T const*;

	iterator begin() { return ptr_; }
	const_iterator begin() const {return ptr_; }
	const_iterator cbegin() const {return ptr_; }
	iterator end() {return ptr_ ? ptr_ + size_ : ptr_;}
	const_iterator end() const { return ptr_ ? ptr_ + size_ : ptr_;}
	const_iterator cend() const { return ptr_ ? ptr_ + size_ : ptr_;}

	vector() 
	{
		capacity_ = 0;
		size_ = 0;
		ptr_ = 0;
	}

	vector(const vector<T> & v)
	{
		size_ = v.size_;
		capacity_ = v.capacity_;
		ptr_ = new T[size_];
		for (int i = 0; i < size_; i++){
			ptr_[i] = v.ptr_[i];
		}
	}

	vector(unsigned int size)
	{
		capacity_ = size;
		size_ = size;
		ptr_ = new T[size];
	}

	vector(unsigned int size, const T & initial)
	{
		size_ = size;
		capacity_ = size;
		ptr_ = new T[size];
		for(int i = 0; i < size; i++){
			ptr_[i] = initial;
			T();
		}
	}

	vector(initializer_list<T> const& lst)
	{
		size_ = lst.size();
		int vector_count = 0;
		capacity_ = size_ + size_/2 + 1;
		ptr_ = new T[size_];
		for(auto i : lst) {
			ptr_[vector_count++] = i;
		}

	}

	~vector()
	{
		delete[] ptr_;
	}

	void push_back(const T & v)
	{
		if (size_ >= capacity_){
			reserve(capacity_ +5);
		}
		ptr_[size_++] = v;

	}

	void pop_back()
	{
		size_--;
	}

	void reserve(unsigned int capacity)
	{
	    if(ptr_ == 0)
	    {
	        size_ = 0;
	        capacity_ = 0;
	    }    
	    T * newPtr_ = new T [capacity];
	    //assert(Newbuffer);
	    unsigned int l_Size = capacity < size_ ? capacity : size_;
	    //copy (buffer, buffer + l_Size, Newbuffer);

	    for (unsigned int i = 0; i < l_Size; i++)
	        newPtr_[i] = ptr_[i];

	    capacity_ = capacity;
	    delete[] ptr_;
	    ptr_ = newPtr_;
	}

	vector<T>& operator =(const vector<T>& v)
	{
		delete[] ptr_;
		size_ = v.size_;
		capacity_ = v.capacity_;
		ptr_ = new T[size_];
		for(unsigned int i = 0; i < size_; i++)
			ptr_[i] = v.ptr_[i];
		return *this;
	}

	vector<T>& operator =(initializer_list<T> const& il)
	{
		int counter = 0;
		size_ = il.size();
		capacity_ = size_ + ((size_/2)+1);
		ptr_ = new T[capacity_];
		for (const T& i : il){
			ptr_[counter++] = i;
		}
		return *this;
	}

	T& operator [](unsigned int index)
	{
		return ptr_[index];
	}

	void clear()
	{
		capacity_ = 0;
		size_ = 0;
		ptr_ = 0;
	}


private:
	T * ptr_;
	unsigned int size_;
	unsigned int capacity_;
};
