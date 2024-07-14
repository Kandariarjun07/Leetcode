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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> removalSet(nums.begin(),
                                      nums.end());
        while (head && removalSet.count(head->val)) {
            head = head->next;
        }
        ListNode* currentNode = head;
        while (currentNode && currentNode->next) {
            if (removalSet.count(currentNode->next->val)) {
                currentNode->next = currentNode->next->next;
            } else {
                currentNode = currentNode->next;
            }
        }
        return head;
    }
};