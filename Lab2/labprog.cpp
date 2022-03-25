#include <iostream>
#include <vector>
#include "fun.h"
#include <string>
using namespace std;
using namespace stringanalizer;
int main()
{
    char command;
    string stroka;
    cin >> stroka;
    stringanalizer::analyzer az = stringanalizer::analyzer(stroka);
    cout << "Choose the variant: " << '\n' <<"0.Set seps(default '-')."<<'\n'<<"*. Add delimiters every two letters."<<'\n' << "    1.Set a string." << '\n' << "   2.Separate a string" << '\n';
    cout << "   3.Get all substrings" << '\n' << "  4. Get next substring." << '\n' << "    5.Get previous substring." << '\n' << "     6. To delete all delimiters." << '\n' << "          Put 7 to quit..." << '\n';
 
   while (cin >> command) {
  
        switch (command) {
        case'*':
            az.add_delimiter();
            break;
        case'0':
            az.get_sep();
            break;
        case'1':
            az.get_string();
                break;
        case'2':
            az.split();
            break;
        case'3':
            az.get_all_substrings();
            break;
        case'4':
            az.get_next_substring();
            break;
        case'5':
            az.get_prev_substring();
            break;
        case'6':
            az.delete_all_delimiters();
            break;
        case'7':
            cout << "Bye-bye" << '\n';
            exit(0);
            break;
        default:
            break;
        }
    }
        return 0;
    }