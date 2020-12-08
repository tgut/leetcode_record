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

 //l1 l2 and 写法。
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // if(       
            int temp_data = 0;
            ListNode *result = new  ListNode(0);
            ListNode * cur = result;

            while(l1 && l2){
                cur->next = new ListNode((temp_data + l1->val + l2->val)%10);
                cur=cur->next;
                temp_data = (temp_data + l1->val + l2->val)/10;
                l1 = l1->next;
                l2 = l2->next;
            }

            while(l1){
                cur->next = new ListNode((temp_data + l1->val )%10);
                cur=cur->next;
                temp_data = (temp_data + l1->val)/10;
                l1 = l1->next;
            }

             while(l2){
                cur->next = new ListNode((temp_data + l2->val )%10);
                cur=cur->next;
                temp_data = (temp_data + l2->val)/10;
                l2 = l2->next;
            }

            if(temp_data > 0)
                cur->next = new ListNode(temp_data);


            return result->next;
    }
};
