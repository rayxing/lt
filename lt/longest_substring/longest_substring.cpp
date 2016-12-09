#include <string>
#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        string substring("");
        int length = 0;
        int i = 0; 
        
        map<char, int> data_map;
        while (i < s.length()) {
            
            int j = 0;
            for (j=i; j<s.length(); j++) {
                map<char, int>::iterator itr = data_map.find(s[j]);
                if (itr == data_map.end()) {
                    data_map.insert(make_pair(s[j], j));
                }
		else if ((*itr).second < i) {
                    data_map[s[j]] = j;
		}
                else {
		   
                    if (j-i > length) {
                        length = j-i;
                        substring = s.substr(i, length);
                    } 
		    
                    i = (*itr).second + 1;

                    data_map[s[j]] = j;
                }
            }
            
            if (j == s.length()) {

                if (j-i > length) {
                    length = j-i;
                    substring = s.substr(i, length);
                }

		break;
            }
        }
        
	cout << "len:" << length << endl;
	cout << "str:" << substring << endl;

        return length;
    }
};

int main() {
	Solution s;

	//string str1("123123123");
	//string str1("pwwkew");
	string str1("qwnfenpglqdq");
	//string str1("bbbbb");
	int len1 = s.lengthOfLongestSubstring(str1);
	//cout << "len:" << len1 << endl;
	
	string str2("abba");
	int len2 = s.lengthOfLongestSubstring(str2);
	//cout << "len:" << len2 << endl;
	
	string str3("abcabcabc");
	int len3 = s.lengthOfLongestSubstring(str3);
	//cout << "len:" << len3 << endl;

	return 1;
}
