#include "fun.h"
#include <iostream>
#include <algorithm>
using namespace std;
namespace fun {
	Circle::Circle() {
		x = 0, y = 0, rad = 0, m = 0;
	}
	void Circle::initFromDialog() {
		cout << "Coords of circle's center?\n";
		cin >> x >> y;
		cout << "Radius of circle?\n";
		cin >> rad;
		cout << "Mass of circle?\n";
		cin >> m;
	};
	double Circle::perimeter() {
		return 2 * 3.14 * rad*rad;
	};

	double Circle::square() {
		return 3.14*rad*rad;
	};
	double Circle::mass() const {
		return m;
	};
	CVector2D Circle::position() {
		CVector2D vec;
		vec.x = x;
		vec.y = y;
		return vec;
	};
	bool Circle::operator==(const IPhysObject& obj) const {
		return(m == obj.mass());
	};
	bool Circle::operator<(const IPhysObject& obj) const {
		return(m < obj.mass());
	};
	void Circle::draw() {
		cout << "Circle:\n" << "Center: [" << x << ',' << y << "]\n";
		cout << "Radius: " << rad << '\n';
		cout << "Mass: " << m << '\n';
	};
	const char* Circle::classname() {
		return typeid(this).name();
	};
	unsigned int Circle::size() {
		return sizeof * this;
	};
	////////////////////////////////////
	Rectangle::Rectangle() {
		x = 0, y = 0, f_edge = 0, s_edge = 0, m = 0;
	};
	void Rectangle::initFromDialog() {
		cout << "\nRectangle's coords: \n ";
		cin >> x >> y;
		cout << "\nRectangle's edges: \n";
		cin >> f_edge >> s_edge;
		cout << "\nMass: \n";
		cin >> m;
	};
	double Rectangle::square() {
		return f_edge * s_edge;
	};
	double Rectangle::perimeter() {
		return 2 * (f_edge + s_edge);
	};
	double Rectangle::mass() const {
		return m;
	};
	CVector2D Rectangle::position() {
		CVector2D pos;
		pos.x = x;
		pos.y = y;
		return pos;
	};
	bool Rectangle::operator==(const IPhysObject& obj)const {
		return(m == obj.mass());
	};
	bool Rectangle::operator<(const IPhysObject& obj)const {
		return(m < obj.mass());
	};
	void Rectangle::draw() {
		cout << "Center: [" << x << ',' << y << "]\n";
		cout << "Edges: \n \t First: " << f_edge << "\n \t Second: " << s_edge << '\n';
		cout << "Mass: " << m << '\n';
	};
	const char* Rectangle::classname() {
		return typeid(this).name();
	};

	unsigned int Rectangle::size() {
		return sizeof * this;
	};
	Menu::Menu() {};
	void Menu::action() {
		cout << "Choose action: \n";
		cout << "\t1.Add Circle\n";
		cout << "\t2.Add Rectangle\n";
		cout << "\t3.Show all figures\n";
		cout << "\t4.Sum of squares\n";
		cout << "\t5.Sum of perimiters\n";
		cout << "\t6.Center of mass\n";
		cout << "\t7.Size of classes\n";
		cout << "\t8.Sort mass of figures\n";
	};
	void Menu::Menu_action() {
		while (cin >> command) {
			switch (command) {
			case '1':
				createFigure<Circle>();
				break;

			case '2':
				createFigure<Rectangle>();
				break;

			case '3':
				cout << "Amount of figures: " << figures.size()-1<<'\n';
				for (int i = 0; i < figures.size(); i++) {
					cout << "Number: "<<i<<'\n';
					figures[i]->draw();
					cout << '\n';
				}
				break;
			case '4':
				cout << "Sum of squares:" << '\n';
				cout << sum_sq << '\n';
				break;

			case '5':
				cout << "Sum of perimeters:\n";
				cout << sum_perim << '\n';
				break;

			case '6':
				cout << "Sum of center mass:\n";
				cout << sum_m << '\n';
				break;

			case '7':
				cout << "Total memory:\n";
				cout << sum_size << '\n';
				break;

			case '8':
				sort(figures.begin(), figures.end(),
					[](G_Figure* lhs, G_Figure* rhs) {
						return *lhs < *rhs;
					}
				);
				break;
			default:
				cout << "Try another one:)\n";
				break;
			}
		}
	};
	void Menu::active() {
		action();
		Menu_action();
	}
}