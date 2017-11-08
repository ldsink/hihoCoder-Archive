/*
  1034 : 毁灭者问题
  ZhouCheng（Sink）
  Aug 12, 2014
*/

#include <iostream>

using namespace std;

int n, m;
int entity[100001][4];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i ++) {
        cin >> entity[i][0] >> entity[i][1] >> entity[i][2];
        entity[i][3] = 0;
    }
    cin >> m;
    int t, l, r, ans = 0;
    for (int i = 0; i < m; i ++) {
        cin >> t >> l >> r;
        while(l <= r) {
            ans += min(entity[l][0]+(t-entity[l][3])*entity[l][2], entity[l][1]);
            entity[l][0] = 0;
            entity[l][3] = t;
            l ++;
        }
    }
    cout << ans << endl;
    return 0;
}
