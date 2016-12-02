#include <fstream>
#include <iostream>
#include <list>
#include <string>
#include <regex>

using namespace std;

list<string> read_names(string path) {
    ifstream f (path); 
    string s; 
    f >> s;
    
    regex r("\"(.*?)\"");
    regex_token_iterator<string::iterator> st(s.begin(), s.end(), r, 1);
    regex_token_iterator<string::iterator> rend;
    return list<string>(st, rend);
}

int main() {
    long long total = 0;
    
    list<string> names = read_names("problem22_names.txt");
    names.sort();

    int index = 0; 
    list<string>::iterator it = names.begin();
    while(it != names.end()) {
        string name = *it++;
        index++;
        for(int i = 0; i < name.length(); i++) {
            total += (name[i] - '@')*index;
        }
    }

    cout << total << "\n";
}
