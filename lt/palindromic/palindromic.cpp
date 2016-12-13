#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
		string output("");
		int max_len = 0;
		int len = s.size();
		
		for (int i=0; i<len; ++i) {

			int j = 0;
			int k = 0;
			
			//loop 1
			while (i+j<len && i-k>=0) {

				if (s[i+j] != s[i-k]) {
					break;
				}
				
				++j;
				++k;
			}

			if (j+k-1 > max_len) {
				max_len = j+k-1;	
					
				output = s.substr(i-k+1, max_len);
			}
	
			//loop 2
			j = 1;
			k = 0;
			while (i+j<len && i-k>=0) {

				if (s[i+j] != s[i-k]) {
					break;
				}
				
				++j;
				++k;
			}

			if (j+k-1 > max_len) {
				max_len = j+k-1;	
					
				output = s.substr(i-k+1, max_len);
			}	
		}			
        
		return output;
    }
};

int main() {
	Solution solution;
	//string input = "abcdefg";
	//string input = "babad";
	string input = "bbbbbb";
	string output;
	
	output = solution.longestPalindrome(input);

	cout << "input: " << input << endl;
	cout << "output: " << output << endl;
	
	return 0;
}
