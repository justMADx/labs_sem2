#include "fun.h"
#include <iostream>
#include<vector>
using namespace std;
namespace fun {
	coord::coord()
	{
	}
	coord::coord(double c1, double c2) {
		x = c1;
		y = c2;
	}
	Triangle::Triangle()
	{
		a.x = 0; a.y = 0;
		b.x = 0; b.y = 0;
		c.x = 0; c.y = 0;
		square = 0;

	}
	fun::Triangle::Triangle(coord p1, coord p2, coord p3){
		a = p1;
		b = p2;
		c = p3;
		square = abs((a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y)) / 2);
	}
	 bool fun::operator==(Triangle a, Triangle b)
	{
		 return a.square == b.square;
	}
	 bool fun::operator!=(Triangle a, Triangle b)
	 {
		 return a.square != b.square;
	 }
	 bool fun::operator>(Triangle a, Triangle b)
	 {
		 return a.square > b.square;
	 }
	 void fun::move(Triangle t, double x, double y)
	 {
		 t.a.x + x;
		 t.a.y + y;
		 t.b.x + x;
		 t.b.y + y;
		 t.c.x + x;
		 t.c.y + y;
	 }
	 bool fun::operator<(Triangle a, Triangle b)
	 {
		 return a.square < b.square;
	 }



	fun::Queue_real& operator>>(Queue_real& q, int x)
	{
		if (!q.q.empty()) {
			x = q.q.front();
			cout << q.q.front() << "\nPopped from queue\n";
			q.q.erase(q.q.begin());
			return q;
		}
		else cout << "Queue is empty\n";
		return q;
	}

	fun::Queue_real& operator<<(Queue_real& q, int x)
	{
		if (q.q.size() < q.maxsize) {
			q.q.push_back(x);
			cout << x << ": Pushed to queue\n";
			return q;
		}
		else return q;
	}
}
