#include <iostream>
#include <string>

using namespace std;

void print_intend(int n) {
	for(int i = 0; i < n; i++) {
		cout << " ";
	}
}

int main() {
	string s;
	cin >> s;
	int num_intend = 0;
	bool line_start = false;
	while(!cin.eof()) {
		if ( s == ";") {
			if(line_start) print_intend(num_intend);
			cout << ";" << endl;
			line_start = true;
			
		} else if ( s == "{" ) {
			if(line_start) print_intend(num_intend);
			cout << "{" << endl;
			num_intend++;
			line_start = true;
		} else if ( s == "}" ) {
			if(!line_start) cout << endl;
			num_intend--;
			print_intend(num_intend);
			cout << "}" << endl;
			line_start = true;
		} else if ( s == "//" ) {
			if(line_start) print_intend(num_intend);
			cout << "//";
			getline(cin, s);
			cout << s <<endl;
			line_start = true;
		} else {
			if(line_start) print_intend(num_intend);
			cout << s << " ";
			line_start = false;
		}
		cin >> s;
	}

	return 0;
}
