#pragma once
#include <vector>
using namespace std;
namespace fun {
	class coord {
	public:
		double x = 0.0;
		double y = 0.0;
		coord();
		coord(double x, double y);
	};
	class Triangle {
	public:
		coord a, b, c;
		double square;
	public:
		Triangle();
		Triangle(coord a, coord b, coord c);
		friend bool  operator==(Triangle a, Triangle b);
		friend bool  operator !=(Triangle a, Triangle b);
		friend bool  operator <(Triangle a, Triangle b);
		friend bool  operator >(Triangle a, Triangle b);
		friend void move(Triangle t, double x, double y);
	};
	class Queue_real {
	private:
			vector<int>q;
	public:
		int maxsize=100;
		friend Queue_real& operator >>(Queue_real& q,int x);
		friend Queue_real& operator <<(Queue_real& q, int x);
	};
}