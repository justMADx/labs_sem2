#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include "fun.h"
using namespace std;
namespace stringanalizer {
    analyzer::analyzer() {
        s = "";
        sub_n = 0;
    }
analyzer::analyzer(string stroka) {
     s = stroka;
    sub_n = 0;
}
void stringanalizer::analyzer::get_string() {
    string stroka;
    cin >> stroka;
    s = stroka;
    str = s;
    subs={};
    subs.push_back(s);

}
vector<string> analyzer::split() {
    if (s == "\0") {
        cerr << "Error. Nothing exists" << '\n';
    }
    else{
        size_t pos_start = 0, pos_end, delim_len = delimiter.length();
        string token;
        vector<string> res;

        while ((pos_end = s.find(delimiter, pos_start)) != string::npos) {
            token = s.substr(pos_start, pos_end - pos_start);
            pos_start = pos_end + delim_len;
            res.push_back(token);
        }
        res.push_back(s.substr(pos_start));
        subs = res;
        cout << "Separated"<<"\n";
        return subs;
        }
}
void analyzer::get_sep() {
    char sep;
    int amount;
    cout << "Amount of delimiters? . .";
    cin >> amount;
    for (int i = 0; i < amount; i++) {
        cin >> sep;
        delimiter.push_back(sep);
    }

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
        if (s == "\0") {
            cerr << "Error. Nothing exists" << '\n';
        }
        else {
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
    void stringanalizer::analyzer::delete_all_delimiters() {

        size_t position = str.find_first_of(delimiter);
        while (position != string::npos)
        {
            str.erase(str.begin() + position);
            position = str.find_first_of(delimiter);
        }
        s = str;
        cout << "All delimiters deleted" << '\n';
    }
 

