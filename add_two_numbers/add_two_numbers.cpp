/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <stdlib.h>
#include <iostream>

using namespace std;

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
    ListNode * h1;
    ListNode * l1;

    ListNode * h2;
    ListNode * l2;

    ListNode * h3;

    Solution s;
    
    //init list 1
    h1 = new ListNode(2);

    h1->next = new ListNode(4);
    l1 = h1->next;

    l1->next = new ListNode(3);

    //init list 2
    h2 = new ListNode(5);

    h2->next = new ListNode(6);
    l2 = h2->next;

    l2->next = new ListNode(4);


    h3 = s.addTwoNumbers(h1, h2); 

    while (h3 != NULL) {
        cout << h3->val << endl;
        h3 = h3->next;
    }

    return 0;
}
