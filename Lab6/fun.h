#pragma once
#include<iostream>
using namespace std;
namespace fun{
	template<class Iter, class Predicate>
	bool any_of(Iter first,const Iter&last, const Predicate& value) {
		bool flag = false;
		while (first != last) {
			if (*first == value) {
				flag = true;
				break;
			}
			++first;
		}
		return flag;
	};
	
	template<typename iterator, class Predicate>
	bool one_of(const iterator& begin,
		const iterator& end,
		const Predicate& p) {
			int counter = 0;
		for (iterator it = begin; it != end; it++) {
			if ((p(*it))) {
				counter++;
				if (counter > 1)
					return false;
			}
		}
		return true;
	};
	template<class T>
	class OneOfPredicate {
	public:
		bool operator() (const T& a)const {
			return a % 2 == 0;
		}
	};

	template <class Iter, class Predicate>
	bool isPalindrome(Iter first, Iter last, Predicate p) {
		last--;
		while (first != last) {
			if (!p(*first, *last))
				return false;
			first++;
			if (!(first != last))
				break;
			last--;
		}
		return true;
	}

	template <class Type>
	class PalindromePredicate {
	public:
		bool operator() (const Type& a, const Type& b) {
			return a == b;
		}
	};


	class CPoint {
	public:
		double x;
		double y;

		friend bool operator== (const CPoint& left, const CPoint& right){
			return (left.x == right.x && left.y == right.y);
		}
		friend bool operator!= (const CPoint& left, const CPoint& right){
			return (left.x != right.x && left.y != right.y);
		}
		friend bool operator< (const CPoint& left, const CPoint& right)
			{
				if (left.x == right.x)
					if (left.y >= right.y)
						return false;
					else
						return true;

				if (left.x > right.x)
					return false;

				return true;

			}
	};
	
}