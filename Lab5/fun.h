#pragma once
#include "fun.h"
#include <vector>
using namespace std;
namespace fun {
template<typename T>
T get_max(const vector<T>& array);

template<size_t N, typename T>
class Queue {
private:
	vector<T>q;
public:
	int MAX = N;
	void push(T value);
	T pop();
};
}