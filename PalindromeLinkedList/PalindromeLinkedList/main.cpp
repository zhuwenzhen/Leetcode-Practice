//
//  main.cpp
//  PalindromeLinkedList
//
//  Created by Wenzhen Zhu on 6/16/17.
//  Copyright © 2017 Wenzhen Zhu. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
    };
    
    bool isPalindrome(ListNode* head) {
        ListNode* reversed = reverseList(head);
        while(head != NULL){
            if(head->val != reversed->val){
                return false;
            }
            head = head->next;
            reversed = reversed->next;
        }
        return true;
    }
    
    ListNode* reverseList(ListNode* head) {
        ListNode* pre=NULL;
        ListNode* next=NULL;
        while(head!=NULL){
            next=head->next;
            head->next=pre;
            pre=head;
            head=next;
        }
        return pre;
    }
};

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

int main(int argc, const char * argv[]) {
    
    ListNode* n1 = new ListNode(1);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(1);
    
    n1->next = n2;
    n2->next = n3;
    
    Solution s;
    ListNode *res = NULL;
    res = s.reverseList(&n1);
    
    cout << res->val << res->next->val << res->next->next->val << endl;
    return 0;
}
