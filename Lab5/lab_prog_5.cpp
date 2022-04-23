#include <iostream>
#include <vector>
#include "fun.h"
using namespace std;
using namespace fun;

int main()
{
	vector<int> a(1);
	cout << "==============\n";
	if (a.size() != 0) cout << "Gimme ur value\n";
	for (int i : a) {
		cin >> i;
		a.push_back(i);
	}
	try {
		int max = get_max(a);
		cout << "Max element: " << max << '\n';
	}
	catch (const exception& e) {
		cerr << "Caught: " << e.what() << endl;
		cerr << "Type: " << typeid(e).name() << '\n';
	}
	cout << "==============\n";
	Queue<0, int> MyQ;
	char command;
	try {
		MyQ.push(1);
	}
	catch (out_of_range) {
		cout << "Queue is full\n";
	}
	try {
		MyQ.pop();
		MyQ.pop();
	}
	catch (const exception& e) {
		{
			cerr << "Caught: " << e.what() << '\n';
			cerr << "Type: " << typeid(e).name() << '\n';
			cerr << "Queue is empty\n"; }
		cout << "==============\n";
		return 0;
	}
}

