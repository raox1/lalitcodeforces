/* 
Problem - D Least Cost Bracket Sequence.
*/
#include <cstring>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <random>
#include <ctime>
#include <cstdio>
#include <queue>

namespace std {
    class Read {
        public:
        template<typename T>
        inline Read operator >> (T & x) {
            T sum = 0, opt = 1;
            char ch = getchar();
            while(!isdigit(ch)) opt = (ch == '-') ? -1 : 1, ch = getchar();
            while( isdigit(ch)) sum = ( sum << 1) + (sum << 3) + (ch ^ 48), ch = getchar();
            x = sum * opt;
            return *this;
        }
};
}

#define int long long
#define all(a) a.begin(), a.end()

using namespace std;

const int INF = 0x3f3f3f3f3f3f3f3f, Mod = 1e9 + 7;

Read fin;

using PII = pair<int,int>;

priority_queue<PII> q;
signed main() {
    string str; cin >> str;

    int mark = 0, res = 0;

    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '(')
            mark ++ ;
        else if (str[i] == ')')
            mark -- ;
        else {
            int a, b;
            fin >> a >> b;
            q.push(make_pair(b - a, i));
            str[i] = ')';
            res += b;
            mark --;
        }


        if (mark < 0){
            if (q.size()) {
                res -= q.top().first;
                int pos = q.top().second;
                q.pop();
                str[pos] = '(';
                mark += 2;
            } else {
                res = -1;
                break;
            }
        }

    }

    if (res != -1 && mark == 0)
        cout << res << endl << str << endl;
    else
        cout << -1 << endl;
}