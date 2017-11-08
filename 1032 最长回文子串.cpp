/*
  1032 : 最长回文子串
  ZhouCheng（Sink）
  Aug 12, 2014
*/

#include <iostream>
#include <string>
using namespace std;

const char begin_char = '@';
const char sepe_char = '#';
const char end_char = '$';

int main() {
    int n;
    int ans[2000020];
    cin >> n;
    while (n --) {
        string a, b;
        int C, R;
        int max_ans = 0;
        cin >> a;
        b = begin_char;
        b += sepe_char;
        for (int i = 0, j = a.length(); i < j; i++) {
            b += a[i];
            b += sepe_char;
        }
        b += end_char;
        int len = b.length();
        C = 0;
        R = 0;
        for (int i = 0; i < len - 1; i ++) {
            int i_mirror = C - (i - C);
            ans[i] = (R > i) ? min(R - i, ans[i_mirror]) : 0;
            ans[i] ++;
            while (b[i+ans[i]] == b[i-ans[i]])
                ans[i] ++;
            ans[i] --;
            if (i + ans[i] >R) {
                C = i;
                R = i + ans[i];
            }
        }
        for (int i = 0; i < len - 1; i ++)
            max_ans = max(max_ans, ans[i]);
        cout << max_ans << endl;
    }
    return 0;
}
