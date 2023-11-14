#include <iostream>
using namespace std;

struct IntArray {
  int size; //number of elements the array currently holds
  int capacity; //number of elements the array could hold,
                //given current memory allocation to contents
  int *contents; //the integer array
};

IntArray readIntArray();

void addToIntArray(IntArray& ia);

void printIntArray(const IntArray& ia);

IntArray readIntArray() {
	IntArray a{0,0,nullptr};
	int n = 0;
	while(cin >> n) {
		if(a.size + 1 <= a.capacity) {
			a.contents[a.size] = n;
			a.size++;
		} else {
			if(a.capacity == 0) {
				a.capacity = 5;
				a.contents = new int[5];
				a.contents[a.size] = n;
				a.size++;
			} else {
				int *arr = new int[a.capacity * 2];
				for(int i = 0; i < a.capacity; i++) {
					arr[i] = a.contents[i];
				}
				delete[] a.contents;
				a.contents = arr;
				a.capacity *= 2;
				a.contents[a.size] = n;
				a.size++;
			}
		}
	}
	cin.clear();
	cin.ignore();
	return a;
}

void addToIntArray(IntArray &a) {
	int n = 0;
	while(cin >> n) {
		if(a.size + 1 <= a.capacity) {
			a.contents[a.size] = n;
			a.size++;
		} else {
			if(a.capacity == 0) {
				a.capacity = 5;
				a.contents = new int[5];
				a.contents[a.size] = n;
				a.size++;
			} else {
				int *arr = new int[a.capacity * 2];
				for(int i = 0; i < a.capacity; i++) {
					arr[i] = a.contents[i];
				}
				delete[] a.contents;
				a.contents = arr;
				a.capacity *= 2;
				a.contents[a.size] = n;
				a.size++;
			}
		}
	}
	cin.clear();
	cin.ignore();
}

void printIntArray(const IntArray &a) {
	for(int i = 0; i < a.size; i++) {
		cout << a.contents[i] << " ";
	}
	cout << endl;
}

// Do not change this function!

int main() {  // Test harness for IntArray functions.
  bool done = false;
  IntArray a[4];
  a[0].contents = a[1].contents = a[2].contents = a[3].contents = nullptr;

  while(!done) {
    char c;
    char which;

    // Note:  prompt prints to stderr, so it should not occur in .out files
    cerr << "Command?" << endl;  // Valid commands:  ra, rb, rc, rd,
                                 //                  +a, +b, +c, +d,
                                 //                  pa, pb, pc, pd, 
                                 //                  q
    cin >> c;  // Reads r, +, p, or q
    if (cin.eof()) break;
    switch(c) {
      case 'r':
        cin >> which;  // Reads a, b, c, or d
        delete [] a[which-'a'].contents;
        a[which-'a'].contents = nullptr;
        a[which-'a'] = readIntArray();
        break;
      case '+':
        cin >> which;  // Reads a, b, c, or d
        addToIntArray(a[which-'a']);
        break;
      case 'p':
        cin >> which;  // Reads a, b, c, or d
        printIntArray(a[which-'a']);
        cout << "Capacity: " << a[which-'a'].capacity << endl;
        break;
      case 'q':
        done = true;
    }
  }

  for (int i = 0; i < 4; ++i) delete [] a[i].contents;
}
