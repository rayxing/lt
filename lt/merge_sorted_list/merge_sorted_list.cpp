/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <iostream>
#include <string>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		
		ListNode * l3 = NULL;
		ListNode * t3 = NULL;
		int val;

		while (l1!=NULL || l2!=NULL) {
			val = 0;
			if (l1 == NULL)	{
				val = l2->val;	
				
				l2 = l2->next;
			}else if (l2 == NULL) {
				val = l1->val;	
				
				l1 = l1->next;
			}else {
				if (l1->val < l2->val) {
					val = l1->val;
					l1 = l1->next;
				}else {
					val = l2->val;
					l2 = l2->next;
				}
			}

			if (l3 == NULL) {
				l3 = new ListNode(val);
				t3 = l3;
			}
			else {
				t3->next = new ListNode(val);
				t3 = t3->next;
			} 
		}
		
		return l3;
    }
};

int main() {

	ListNode * l1 = new ListNode(1);
	l1->next = new ListNode(2);
	ListNode * t1 = l1->next;
	t1->next = new ListNode(6);
	
	ListNode * l2 = new ListNode(3);
	l2->next = new ListNode(4);
	ListNode * t2 = l2->next;
	t2->next = new ListNode(5);

	Solution solution;
		
	ListNode * l3 = solution.mergeTwoLists(l1, l2);

	ListNode * t3 = l3;
	while (t3 != NULL) {
		cout << "data: " << t3->val << endl;
		t3 = t3->next;
	}	
	
	return 0;
}
