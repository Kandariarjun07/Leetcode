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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ans = {INT_MAX, INT_MIN};
        ListNode* cur = head;
        int prevCriticalIndex = -1, firstCriticalIndex = -1, prevNode = cur->val, id = 0;
        cur = cur->next;

        while(cur->next != nullptr){
            id++;
            int curNode = cur->val, nextNode = cur->next->val; 
            if((prevNode<curNode && curNode>nextNode) || (prevNode>curNode && curNode<nextNode)){
                if(firstCriticalIndex == -1){
                    firstCriticalIndex = id;
                    prevCriticalIndex = id;
                }else{
                    ans[0] = min(ans[0], id - prevCriticalIndex);
                    ans[1] = max(ans[0], id - firstCriticalIndex);
                    prevCriticalIndex = id;
                }
            }
            prevNode = curNode;
            cur = cur->next;
        }

        vector<int> defaultAns = {-1, -1};
        return (ans[0] == INT_MAX) ? defaultAns : ans;
    }
};