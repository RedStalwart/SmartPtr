#pragma once
#include"referencecount.h"

template<class T>
class smartptr 
{
private:
	T* ptr;
	refcount* counter;
public:
	explicit smartptr(T* p = NULL) :ptr(p),counter(NULL) {
		counter = new refcount();
		counter->addref();
		}
	~smartptr()
	{
		if(counter->release() == 0)
			{
				delete ptr; 
				delete counter;
			}
	}
	T& operator*()
	{
		return *ptr;
	}
	T* operator->()
	{
		return ptr;
	}
	smartptr(const smartptr<T>& sp):ptr(sp.ptr),counter(sp.counter)
	{
		counter->addref;
	}

	smartptr<T>& operator=(const smartptr<T>& sp)
	{
		if (this != sp)
		{
			if (counter->release == 0)
			{
				delete ptr;
				delete counter;
			}
			ptr = sp.ptr;
			counter = sp.counter;
			counter->addref();
		}
	}

};