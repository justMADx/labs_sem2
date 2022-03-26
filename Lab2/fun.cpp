#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include "fun.h"
using namespace std;
namespace stringanalizer {
    vector<string> analyzer::split() {
        if (s == "\0") {
            cerr << "Error. Nothing exists" << '\n';
            return {};
        }
        else {
            size_t pos_start = 0, pos_end;//delim_len = delimiter.length();
            string token;
            int i = 0;
            string copy = delimiter;
            for (int i = 0; i < amount + 1; i++) {
                while ((pos_end = s.find(delimiter[i], pos_start)) != string::npos) {
                    token = s.substr(pos_start, pos_end - pos_start);
                    subs.push_back(token);
                    pos_start = pos_end + 1;
                }
            }
            delimiter = copy;
            subs.push_back(s.substr(pos_start));
            cout << "Separated" << "\n";
            return subs;
        }
    }
    analyzer::analyzer() {
        s = "";
        sub_n = 0;
    }
analyzer::analyzer(const string& stroka) {
     s = stroka;
    sub_n = 0;
}
void stringanalizer::analyzer::get_string() {
    string stroka;
    cin >> stroka;
    s = stroka;
    str = s;
    subs.clear();
    subs.push_back(s);
    split();
}
void analyzer::get_sep() {
    char sep;
    cout << "Amount of delimiters? . .";
    cin >> amount;
    delimiter.clear();
    delimiter.resize(amount);
    for (int i = 0; i != amount; i++) {
        cin >> sep;
       delimiter[i] = sep;
     }
    split();
}

void analyzer::add_delimiter() {
    if (s == "\0")
        cerr << "Error. Nothing exists" << '\n';
    else {
        string str;
        str.resize(s.length() * 2);
        size_t size = 0;

        for (size_t i = 0; i < s.length(); ++i) {
            str[size++] = s[i++];
            if (i < s.length()) {
                str[size++] = s[i];
                if (i != s.length() - 1)
                    str[size++] = delimiter[0];
            }
        }
        str.resize(size);
        swap(str, s);
        cout << "Delimiter added" << '\n';
     }
}
    void analyzer::get_all_substrings()
    {
        if (subs.empty()) {
             cout << s << '\n';
         }
        else{
            for (int i = 0; i < subs.size(); i++)
                cout << subs[i] << '\n';
        }
    }


    void analyzer::get_next_substring() {
        if (s == "\0") {
            cerr << "Error. Nothing exists" << '\n';
        }
        else{
            if (sub_n >= subs.size()) {
                cerr << "Nothing remained" << '\n';
            }
            else {
                cout << subs[sub_n] << '\n';
                if (sub_n <= subs.size() - 1)
                    sub_n++;
            }
        }
        }
    }
    void stringanalizer::analyzer::get_prev_substring() {
        if (s == "\0") {
            cerr << "Error. Nothing exists" << '\n';
        }
        else{
            if (sub_n != 0) {
                cout << subs[sub_n - 1] << '\n';
                if (sub_n > 0){
                    sub_n--;
            }
            }
            else {
                cerr << "Nothing remained" << '\n';
            }
        }
    }
    string stringanalizer::analyzer::delete_all_delimiters() {

        size_t position = s.find_first_of(delimiter);
        while (position != string::npos)
        {
            s.erase(s.begin() + position);
            position = s.find_first_of(delimiter);
        }
        subs.clear();
        subs.push_back(s);
        cout << "All delimiters deleted" << '\n';
        return s;
    }
 

