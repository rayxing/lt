#include <string>
#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
		stack<char> mystack;
		char data;		

		for (int i=0; i<s.size(); ++i) {
			switch (s[i]) {
				case '[':
					mystack.push('[');
					break;

				case ']':
					if (mystack.empty())
						return false;

					data = mystack.top();
					if (data != '[')
						return false;

					mystack.pop();
					break;

				case '(':
					mystack.push('(');
					break;

				case ')':
					if (mystack.empty())
						return false;

					data = mystack.top();
					if (data != '(')
						return false;

					mystack.pop();
					break;

				case '{':
					mystack.push('{');
					break;
				case '}':
					if (mystack.empty())
						return false;

					data = mystack.top();
					if (data != '{')
						return false;

					mystack.pop();
					break;
				
				default:
					break;
			}
		}
		
		if (mystack.empty())
			return true;

		return false;
    }
};

int main() {
	Solution solution;
	string s = "()[]{}";

	bool ret;
	string ret_str;

	ret  = solution.isValid(s);

	ret ? ret_str="True" : ret_str="False";	

	cout << "Output: " << ret_str << endl;	
	
	return 0;
}
