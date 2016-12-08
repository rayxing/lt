/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <stdlib.h>

struct ListNode {
   int val;
   ListNode *next;
   ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode * newhead = NULL;
        ListNode * l3 = NULL;
        int bit = 0;
        int val = 0;

        while (l1 != NULL || l2!= NULL) {
            
            if (l1 != NULL) {
                val += l1->val;
                l1 = l1->next;
            }
            
            if (l2 != NULL) {
                val += l2->val;
                l2 = l2->next;
            }
                
            val += bit;
            
            if (val >= 10) {
                val = val - 10;
                bit = 1;
            } else {
                bit = 0;
            }
            
            if (newhead == NULL) {
                newhead = new ListNode(val);
                l3 = newhead;
            } else {
                l3->next = new ListNode(val);
                l3 = l3->next;
            }
            
            val = 0;
        } 
        
        if (bit != 0) {
            l3->next = new ListNode(bit);
        }
        
        return newhead;
    }
};

int main() {
    ListNode * l1;
    ListNode * l2;
    ListNode * l3;

    Solution s;

    l3 = s.addTwoNumbers(l1, l2); 

    return 0;
}
