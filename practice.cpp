#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int difnum(string s) {
    set<char> st;
    for (int i = 0; i < (int)s.length(); i++) {
        st.insert(s[i]);
    }
    return (int)st.size();
}

int main() {
    int T;
    cin >> T;
    for (int x = 0; x < T; x++) {
        int n;
        cin >> n;
        cin.ignore();  
        cout << "case #" << x << ":" << endl;

        vector<pair<int, string>> vec;

        for (int i = 0; i < n; i++) {
            string line;
            getline(cin, line);
            vec.push_back({difnum(line), line});
        }

        sort(vec.begin(), vec.end(), [](const pair<int, string>& a, const pair<int, string>& b) {
            if (a.first != b.first) return a.first < b.first;  
            return a.second < b.second;                         
        });

        for (int i = 0; i < n; i++) {
            cout << vec[i].second << endl;
        }
    }
    return 0;
}