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

	ListNode * next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		if (n <= 0)
			return head;

		ListNode * last = NULL;
		ListNode * temp = head;
	
		int i = 0;
		while (temp) {
			
			if (i > n-1) {
				if (last == NULL)
					last = head;
				else 
					last = last->next;
			}

			++i;
			
			temp = temp->next; 
		}
		
		if (i == n){
			temp = head;
			head = head->next;
			delete temp;	
		}
		else if (i > n) {
			temp = last->next;
			last->next = last->next->next;
			delete temp;
		}
		
		return head;
    }
};

void printList(ListNode * head) {
	
	ListNode * temp = head;
	
	while (temp!=NULL) {
		cout << temp->val;
		
		if (temp->next != NULL)
			cout << " -> ";

		temp = temp->next;
	}

	cout << endl;
}

int main() {

	Solution solution;
	
	ListNode * head = new ListNode(1);
	/*ListNode * temp = head;
	temp->next = new ListNode(2);
	temp = temp->next;
	temp->next = new ListNode(3);
	temp = temp->next;
	temp->next = new ListNode(4);
	temp = temp->next;
	temp->next = new ListNode(5);
	temp = temp->next;
	*/
	
	int x = 1;

	printList(head);

	head = solution.removeNthFromEnd(head, x);
	
	printList(head);
	
	return 0;
}
