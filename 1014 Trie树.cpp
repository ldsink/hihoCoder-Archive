#include <iostream>
#include <string>
using namespace std;

struct point {
  char ch;
  int count;
  point* left; // child
  point* right; // brother
};

string s;
void process(point*, int, int);
int query(point*, int, int, int);

int main() {
  int n, m;

  point *root = new point;
  root->ch = '\0';
  root->count = 0;
  root->left = NULL;
  root->right = NULL;

  cin >> n;
  for (int i = 0; i < n; i ++) {
    cin >> s;
    process(root, 0, s.length());
  }

  cin >> m;
  for (int i = 0; i < m; i ++) {
    cin >> s;
    cout << query(root, 0, s.length(), 0) << endl;
  }
  return 0;
}

void process(point* p, int pos, int len) {
  while (1) {
    if (pos >= len)
      break;
    char c = s[pos];
    if (p->ch == c) {
      p->count ++;
      if (p->left == NULL) {
        p->left = new point;
        p->left->ch = '\0';
        p->left->count = 0;
        p->left->left = NULL;
        p->left->right = NULL;
      }
      pos += 1;
      p = p->left;
      continue;
    }
    else {
      if (p->right == NULL) {
        p->right = new point;
        p->right->ch = c;
        p->right->count = 0;
        p->right->left = NULL;
        p->right->right = NULL;
      }
      p = p->right;
      continue;
    }
  }
}

int query(point* p, int pos, int len, int num) {
  while (1) {
    if (pos >= len)
      return num;
    char c = s[pos];
    if (p->ch == c) {
      if (p->left == NULL)
        return 0;
      num = p->count;
      pos += 1;
      p = p->left;
      continue;
    }
    else {
      if (p->right == NULL)
        return 0;
      p = p->right;
      continue;
    }
  }
}
