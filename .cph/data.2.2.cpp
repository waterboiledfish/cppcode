#include <iostream>
#include <string>

using namespace std;

#define maxnum 1500

class stack {
private:
    char arr[maxnum];
    int count;
public:
    stack() : count(0) {}
    bool empty() const { return count == 0; }
    bool full() const { return count == maxnum; }
    bool pushchar(char c) {
        if (full()) return false;
        arr[count++] = c;
        return true;
    }
    bool pop() {
        if (empty()) return false;
        count--;
        return true;
    }
    bool top(char *ptr) const {
        if (empty()) return false;
        *ptr = arr[count - 1];
        return true;
    }
};

bool isbracket(char c) {
    return c == '(' || c == '[' || c == '{' || c == ')' || c == ']' || c == '}';
}

bool match(char c, char t) {
    return (c == ')' && t == '(') || (c == ']' && t == '[') || (c == '}' && t == '{');
}
bool handle_stack(char c, stack &s) {
    if (c == '(' || c == '[' || c == '{') {
        return s.pushchar(c);
    }
    char top_c;
    if (s.top(&top_c) && match(c, top_c)) {
        return s.pop();
    }
    return false;
}

int main() {
    stack s2;
    string line;
    int total = 0;
    bool in_block = false, is_valid = true, in_str = false;

    while (getline(cin, line)) {
        for (int i = 0; i < (int)line.size(); i++) {
            char c = line[i];
            if (!in_block && c == '"') { in_str = !in_str; continue; }
            if (in_str) continue;
            if (in_block) {
                if (c == '*' && i + 1 < (int)line.size() && line[i + 1] == '/') {
                    in_block = false; i++;
                }
                continue;
            }
            if (c == '/' && i + 1 < (int)line.size()) {
                if (line[i + 1] == '/') break; 
                if (line[i + 1] == '*') { in_block = true; i++; continue; }
            }
            if (isbracket(c)) {
                total++;
                if (!handle_stack(c, s2)) is_valid = false;
            }
        }
    }

    if (!s2.empty()) is_valid = false;
    cout << total << " " << (is_valid ? "yes" : "no") << endl;
    return 0;
}