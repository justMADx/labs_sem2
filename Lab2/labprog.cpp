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
    cout << "Put your string\n";
    cin >> stroka;
    stringanalizer::analyzer az = stringanalizer::analyzer(stroka);
    cout << "Choose the variant: " << '\n' <<"\t0.Set seps(default '-')."<<'\n'<<"\t*.Add delimiters every two letters."<<'\n' << "\t1.Set a string." << '\n';
    cout << "\t3.Get all substrings" << '\n' << "\t4. Get next substring." << '\n' << "\t5.Get previous substring." << '\n' << "\t6. To delete all delimiters." << '\n' << "\t\tPut 'q' to quit..." << '\n';
 
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
        case'q':
            cout << "Bye-bye" << '\n';
            exit(0);
            break;
        default:
            break;
        }
    }
        return 0;
    }