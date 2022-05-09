#include<iostream>
#include <vector>
#include <set>
#include "fun.h"
using namespace std;
using namespace fun;

int main() {
    vector<CPoint> anyof;
    CPoint need;
    need.x = 1.0;
    need.y = 1.0;
    anyof.push_back(need);
    need.x = 2.0;
    need.y = 1.0;
    anyof.push_back(need);
    need.x = 1.0;
    need.y = 3.0;
    anyof.push_back(need);
    CPoint predicate{ 1,3 };

    cout << "AnyOf Check:\n";
    if (any_of(anyof.begin(), anyof.end(), predicate))
        cout << "\tYou got at least one of the elements\n";
    else
        cout << "\tNone of the elements is 'good' for predicate\n";


    set<CPoint> anyof_;
    CPoint need_;
    need_.x = 1.2;
    need_.y = 1.3;
    anyof_.insert(need_);
    need_.x = 1.4;
    need_.y = 1.5;
    anyof_.insert(need_);
        need_.x = 1.2;
        need_.y = 1.3;
    anyof_.insert(need_);
    CPoint predicate_{ 1.2,1.3 };
    cout << "Set* AnyOf Check: \n";
    if (any_of(anyof_.begin(), anyof_.end(), predicate_))
        cout << "\t*Set* You got at least one of the elements\n";
    else
        cout << "\t*Set* None of the elements is 'good' for predicate\n";

 

   

    vector<int> oneof = { 1,3,3,4 };
    cout << "OneOf Check: \n";
    if (one_of(oneof.begin(), oneof.end(), OneOfPredicate<int>()))
        cout << "\tOnly one of the Elements is Divisible by Two\n";//Чётность
    else
        cout << "\tNot only one, or none is Divisible by Two\n";

    
    vector<int>vec = { 1,3,4,4,1 };
    cout << "Is_Palindrome Check:\n";
    if (isPalindrome(vec.begin(), vec.end(), PalindromePredicate<int>()))
        cout << "\tIsPalindrome\n";
    else
        cout << "\tNo,it's NOT\n";
    
	return 0;
}