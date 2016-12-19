#include <iostream>
#include <string>
#include <string.h>

using namespace std;

class Solution {
public:
	string convert(string s, int numRows) {
		bool debug = false;

		if (numRows <= 0)
			return string("");
		else if (numRows == 1)
			return s;

		int len = s.size();

		int col = 0;
		int count = 0;

		while (1) {
			if (col % (numRows-1) == 0) 
				count += numRows;	
			else
				count ++;

			col ++;

			if (count >= len)
				break;				
		}

		if (debug)
			cout << "col: " << col << endl;
		
		string ret = "";
		int idx = 0;

		for (int j=0; j<numRows; ++j) {
			for (int i=0; i<col; ++i) {
				if (i % (numRows-1) == 0) {
					idx = (i/(numRows-1))*(2*numRows-2) + j;	

					if (idx < len) {
						if (debug) cout << "(" << j << "," << i << ") => " << idx << endl;

						ret.push_back(s[idx]);
					}
				}	
				else if ((i + j) % (numRows - 1) == 0) {
					
					idx = (i/(numRows-1))*(2*numRows-2) + numRows + (i%(numRows-1)) - 1;	

					if (idx < len) {
						if (debug) cout << "(" << j << "," << i << ") => " << idx << endl;

						ret.push_back(s[idx]);
					}
				}
			}	
		}
		

		return ret;	
    }
};

int main() {
	Solution solution;
	//string s = "ABCD";
	string s = "PAYPALISHIRING";
	//string s = "ABC";
	string res;
	int row = 3;
	
	res = solution.convert(s, row);

	cout << "input:" << s << endl;
	cout << "output:"  << res << endl;
	
}
