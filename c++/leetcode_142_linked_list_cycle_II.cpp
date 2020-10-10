#include "iostream"
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL )
            return NULL;
        ListNode *pre,*next;
        /*pre use step 1,next use step 2*/
        pre = next = head;
        while(next && next->next){
            /*firstly move the positon,then compare the pointer.*/
            pre = pre->next;
            next = next->next->next;
            /*if pre and next met first,then let pre starts from head,next continue.
             * the step is 1.
            */
            if(pre == next){
                pre = head;
                while(pre !=next){
                    next= next->next;
                    pre = pre->next;
                }
                return pre;
            }
        }
        return NULL;
    }
};

int main(){
    Solution s;
    ListNode *node0 = new ListNode(3);
    ListNode *node1 = new ListNode(2);
    node0->next = node1;
    ListNode *node2 = new ListNode(0);
    node1->next = node2;
    ListNode *node3 = new ListNode(4);
    node2->next = node3;
    node3->next = node1;
    // ListNode* result = s.detectCycle(node0);
    // cout << result->val << endl;
    return 0;
}