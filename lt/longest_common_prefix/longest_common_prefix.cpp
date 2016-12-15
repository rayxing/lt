#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
		string prefix("");
		for (int i=0; ; ++i) {
			char data = '\0';
			for (int j=0; j<strs.size(); ++j) {
				if (i >= strs[j].size())
					return prefix;

				if (data == '\0')
					data = strs[j][i];
				else if(data != strs[j][i])
					return prefix;
			}
			
			if (data == '\0')
				return prefix;
			
			prefix.push_back(data);
		}
        
    }
};

int main() {
	Solution solution;
	string output;

	vector<string> strs;
	
	strs.push_back("");
	//strs.push_back("111hello");
	//strs.push_back("1111111");
	//strs.push_back("1111abc");
	//strs.push_back("1111111aaa");

	output = solution.longestCommonPrefix(strs);
	
	cout << "output: " << output << endl;

	return 0;
}
