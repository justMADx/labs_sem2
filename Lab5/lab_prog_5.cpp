#include <iostream>
#include <vector>
#include "fun.h"
#include "fun.cpp"
using namespace std;
using namespace fun;

int main()
{
	vector<int> a(0);
	cout << "==============\n";
	for (int i : a) {
		cin >> i;
		a.push_back(i);
	}
	int max = get_max(a);
	cout <<"Max element: "<<max << '\n';
	cout << "==============\n";
	Queue<2, int> MyQ;
	MyQ.push(1);
	MyQ.push(2);
	MyQ.pop();
	MyQ.pop();
	MyQ.pop();
	cout << "==============\n";
	return 0;
}

