#pragma once
#include<iostream>
#include "fun.h"
#include <vector>
using namespace std;
namespace fun {
template<typename T>
T get_max(const vector<T>& array){
	if (array.size() <= 0)
		throw
		out_of_range{ "Out of range" };

	T max = array[0];

	for (int i = 0; i < array.size(); i++) {
		if (array[i] > max)
			max = array[i];
	}
	return max;
};

template<size_t N, typename T>
class Queue {
private:
	vector<T>q;
public:
	void push(const T& value) {
		if (q.size() == N)
			throw out_of_range{ "" };
		q.push_back(value);
	};
	T pop() {
		if (q.empty())
			throw
			runtime_error{ "Runtime error" };
		int el = q.front();
		q.erase(q.begin());
		return el;
	};
};
}