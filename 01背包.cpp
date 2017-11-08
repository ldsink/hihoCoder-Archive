#include <iostream>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	int bag[100001] = { 0 };
	for (int i = 0, need, value; i < n; i++) {
		cin >> need >> value;
		for (int j = m - need; j >= 0; j--) {
			if (bag[j] + value > bag[j + need])
				bag[j + need] = bag[j] + value;
		}
	}
	cout << bag[m] << endl;
	return 0;
}