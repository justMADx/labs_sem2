#pragma once
#include <string>
#include <vector>
using namespace std;
namespace stringanalizer {
    class analyzer {
    private:
        string delimiter="";
        int amount;
        string s;
        vector<string> subs;
        string str;
        int sub_n=0;
    public:
        analyzer();
        analyzer(const string& stroka);
       vector<string> split();
        void get_sep();
        void add_delimiter();
        void get_all_substrings();
        void get_next_substring();
        void get_prev_substring();
        void delete_delimiters();
        string delete_all_delimiters();
        void get_string();
    };
}