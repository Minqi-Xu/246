#include <iostream>

using namespace std;

void my_swap(int *a, int *b) {
	int c = *a;
	*a = *b;
	*b = c;
}

int main() {
	int n = 0, tot = 0;
	cin >> n;
	int *v = new int[n];
	for(int i = 0; i < n; i++)
		cin >> v[i];
	cin >> tot;

	for(int i = 0; i < n; i++) {
		for(int j = 1; j < n - i; j++) {
			if(v[j-1] < v[j]) my_swap(&v[j-1], &v[j]);
		}
	}

	int *num = new int[n];
	for(int i = 0; i < n; i++) {
		num[i] = tot / v[i];
		tot -= num[i] * v[i];
	}

	if(tot != 0) {
		cout << "Impossible" << endl;
		return 0;
	}

	for(int i = 0; i < n; i++) {
		if(num[i] != 0) {
			cout << num[i] <<" x " << v[i] << endl;
		}
	}

	delete[] num;
	delete[] v;

	return 0;
}
