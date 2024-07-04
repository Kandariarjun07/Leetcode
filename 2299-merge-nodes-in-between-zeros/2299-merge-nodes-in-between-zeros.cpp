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
    ListNode* mergeNodes(ListNode* head) {
        ListNode *newHead = new ListNode();
        int sum = 0;
        ListNode *temp = newHead;
        while(head != NULL){
            sum += head->val;
            if(head->next && head->next->val == 0){
                temp->next = new ListNode(sum);
                temp = temp->next;
                sum = 0;
            }
            head = head->next;
        }
        return newHead->next;
    }
};