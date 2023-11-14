#include <vector>
#include <iostream>
#include <string>

using namespace std;

class function {
	int initial_val;
   public:
	function(int initial_val = 0) : initial_val{initial_val} {}
	vector<char> op;
	vector<int> parm;
	int getInitial() const {
		return initial_val;
	}
	void setInitial(const int num) { initial_val = num; }
};

int main() {
	function f;
	char c;
	int num;
	while(cin >> c) {
		switch(c) {
			case 's':
				cin >> num;
				f.setInitial(num);
				f.op.clear();
				f.parm.clear();
					break;
			case 'n':
				for(size_t i = 0; i < f.op.size(); ++i) {
					switch(f.op[i]) {
						case '+':
							f.setInitial(f.getInitial() + f.parm[i]);
							break;
						case '-':
							f.setInitial(f.getInitial() - f.parm[i]);
							break;
						case '*':
							f.setInitial(f.getInitial() * f.parm[i]);
							break;
						case '/':
							f.setInitial(f.getInitial() / f.parm[i]);
							break;
					}
				}
				cout << f.getInitial() <<endl;
				break;
			default:
				cin >> num;
				f.op.emplace_back(c);
				f.parm.emplace_back(num);
				break;
		}
	}
}
