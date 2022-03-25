#include <iostream>
#include "fun.h"
using namespace std;
using namespace fun;
int main()
{
	coord a1(0,0), b1(0,4), c1(4,0);
	coord a2(2,2), b2(2,6), c2(6,2);
	fun::Triangle t1 = fun::Triangle(a1, b1, c1);
	fun::Triangle t2 = fun::Triangle(a2, b2, c2);
	fun::Queue_real q = fun::Queue_real();
	char command;
	int task;
	cout << "\tChoose the task\n"<<"1: First task with Triangle\n"<<"2: Second task is FIFO\n";
	cin >> task;
	if (task == 1) {
		cout << "Commands for the first task: \n" << "'=': Equal '=='\n" << "'!': Equal '!='\n" << "'>': Equal '>'\n" << "'<': Equal '<'\n"<<"'m': To move triangle(you need to choose one)\n" << "'q': to EXIT\n";
		while (cin >> command) {
			switch (command) {
			case'=':
				if (t1 == t2)
					cout << "The areas of the triangles are equal.\n";
				else cout << "NO\n";
				break;
			case'!':
				if (t1 != t2)
					cout << "The areas of the triangles are not equal.\n";
				else cout << "NO\n";
				break;
			case'>':
				if (t1 > t2)
					cout << "The area of the first is larger than the second.\n";
				else cout << "NO\n";
				break;
			case'<':
				if (t1 < t2)
					cout << "The area of the first is smaller than the second.\n";
				else cout << "NO\n";
				break;
			case'm':
				cout << "I need your coordinats of vector: \n";
				double x, y;
				cin >> x >> y;
				cout << "Choose the triangle:\n" << "1 or 2\n";
				int value;
				cin >> value;
				if (value == 1) move(t1, x, y);
				else if (value == 2) move(t2, x, y);
				break;				
			case 'q':
				exit(0);
			default:
				cout << "Use only '=,!,>,<,m,q'\n";
				break;
			}
		}
	}
	if (task == 2) {
		cout << "\tCommands for the second task:\n"<<"'+': to add a number to the queue\n"<<"'-': to get a number from queue\n"<<"'q': to EXIT\n";
		while (cin >> command) {
			switch (command) {
			case'+':
				int x;
				cin >> x;
				(q << x);
				break;
			case '-':
				(q >> x);
				break;
			case'q':
				exit(0);
			default:
				cout << "Use only '+,-,q'\n";
				break;
			}
		}
	}
}

