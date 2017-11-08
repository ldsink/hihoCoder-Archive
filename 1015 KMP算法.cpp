/*
  1015 : KMP算法
  ZhouCheng（Sink）
  Aug 11, 2014
*/

#include <iostream>
#include <string>
using namespace std;

int KMPMatch();
void getNext();

char sep = '$';
string s, p;
int sl, pl;
int next[10001];

int main () {
    int n;
    cin >> n;
    while (n --) {
        cin >> p;
        cin >> s;
        p += sep;
        cout << KMPMatch() << endl;
    }
}

int KMPMatch() {
    int i = 0;
    int j = 0;
    int k = 0;
    sl = s.length();
    pl = p.length();
    getNext();
    while(i <= sl) {
        if(j == -1 || s[i] == p[j]) {
            i++;
            j++;
        }
        else {
          // 永远不能匹配成功，但是看见 sep 符号认为匹配成功一次。
          if (p[j] == sep)
            k ++;
          j = next[j];
        }
    }
    return k;
}

void getNext()
{
    int j, k, l;
    next[0] = -1;
    j = 0;
    k = -1;
    while (j < pl) {
        if (k == -1 || p[j] == p[k]) {
            j++;
            k++;
            next[j] = k;
        }
        else
            k = next[k];
    }
}
