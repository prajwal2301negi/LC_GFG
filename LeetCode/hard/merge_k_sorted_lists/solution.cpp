// Problem: Merge k Sorted Lists
// Difficulty: hard
// Runtime: 19 ms
// Memory: 24.7 MB

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* temp1= list1;
        ListNode* temp2 = list2;

        ListNode* ans = new ListNode(-1);
        ListNode* temp3 = ans;

        while(temp1 != NULL and temp2 != NULL){
            if(temp1->val<=temp2->val){
                temp3-> next = new ListNode(temp1->val);
                temp1 = temp1->next;
                temp3 = temp3->next;
            }
            else {
                temp3 -> next = new ListNode(temp2->val);
                temp2 = temp2->next;
                temp3 = temp3->next;
            }
        }
        while(temp1!=NULL){
            temp3 -> next = new ListNode(temp1->val);
            temp1 = temp1->next;
            temp3 = temp3->next;
        }
        while(temp2 != NULL){
            temp3-> next = new ListNode(temp2->val);
            temp2 = temp2->next;
            temp3 = temp3-> next;
        }
        return ans->next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();

        if(n == 0) return NULL;

         while (n > 1) {
            int k = (n + 1) / 2; 
            for (int i = 0; i < n / 2; i++) {
                lists[i] = mergeTwoLists(lists[i], lists[i + k]);
            }
            n = k;
        }

        return lists[0];
    }
};