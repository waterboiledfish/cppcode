#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    string s;
    while (getline(cin, s)) {
        int totalnum = (int)s.length();
        if (totalnum == 0) continue;

        vector<int> rank(totalnum);
        rank[0] = 0;

        for (int i = 0, j = 1; i < totalnum - 1; i++, j++) {
            if (s[j] > s[i])
                rank[j] = rank[i] - 1;
            else if (s[j] < s[i])
                rank[j] = rank[i] + 1;
            else
                rank[j] = rank[i];
        }

        int minR = rank[0], maxR = rank[0];
        for (int i = 0; i < totalnum; i++) {
            if (rank[i] < minR) minR = rank[i];
            if (rank[i] > maxR) maxR = rank[i];
        }

        for (int r = minR; r <= maxR; r++) {
            string line(totalnum, ' ');
            for (int col = 0; col < totalnum; col++) {
                if (rank[col] == r)
                    line[col] = s[col];
            }
            // 必须等上面列循环全部填完后再改 line 长度，否则 line[col] 会越界
            while (!line.empty() && line.back() == ' ')
                line.pop_back();
            cout << line << endl;
        }
    }
    return 0;
}
