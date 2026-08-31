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
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* nxt = head -> next;
        vector<int> vec;
        int count = 0;
        vector<int> ans;
        while(nxt){
            count++;
            if(prev){
                if((curr->val > prev->val && curr->val > nxt->val) || (curr->val < prev->val && curr->val < nxt->val)){
                    vec.push_back(count);
                }
            }
            prev = curr;
            curr = nxt;
            nxt = nxt -> next;
        }
        int n = vec.size();

        if (n < 2) {
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        }

        int min_diff = INT_MAX;
        for (int i = 0; i < n - 1; ++i) {
            int diff = vec[i + 1] - vec[i];
            if (diff < min_diff) {
                min_diff = diff;
            }
        }
        int max_diff = vec[n - 1] - vec[0];
        ans.push_back(min_diff);
        ans.push_back(max_diff);
        return ans;
    }
};