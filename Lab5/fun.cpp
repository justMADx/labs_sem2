#include<iostream>
#include "fun.h"
#include <vector>
#include <typeinfo>
#include <exception>
namespace fun {
	template <typename T>
	T get_max(const vector<T>& array) {
		T max=0;
		try {
			if (array.size() <= 0)
				throw
				out_of_range{"Out of range"};

			for (int i = 0; i < array.size(); i++) {
				if (array[i] > max) 
					max = array[i];
			}
			return max;
		}
		 catch (const exception& e)
   {
      cerr << "Caught: " << e.what() <<'\n';
      cerr << "Type: " << typeid(e).name() << '\n';
	  cerr << "No elements in array\n";
   }
		return T(false);
	}
	template<size_t N, typename T>
	void Queue<N, T>::push(T value) {
		try {
			if (q.size() == MAX) throw out_of_range{ "" };
			q.push_back(value);
		}
		catch (out_of_range) {
			cout << "Queue is full\n";
		}
	}
	template<size_t N, typename T>
	T Queue <N, T>::pop() {
		try {
			if (q.empty())
				throw
				runtime_error{ "Runtime error" };
			int el = q.front();
			q.erase(q.begin());
			return el;
		}
		catch (const exception& e) {
			{
				cerr << "Caught: " << e.what() << '\n';
				cerr << "Type: " << typeid(e).name() << '\n';
				cerr << "Queue is empty\n";
			}
			return T(false);
		}

	}
}
