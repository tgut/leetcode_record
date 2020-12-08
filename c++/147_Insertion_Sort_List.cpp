// Sort a linked list using insertion sort.


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

 /*插入节点要记录插入位置前一个节点，删除就不用了
 所以用
pre,targe记录插入位置的两个节点，

temp存储，删除位置的下个节点；cur记录删除位置节点。
 */
class Solution {
public:
//test function
/*
    void print(ListNode *dummy_head){
        ListNode* cur = dummy_head;
        while(cur->next){

            cout << cur->next->val <<"->" ;
            cur = cur->next;
        }
        cout<<"NULL "<<endl;

    }*/
    ListNode* insertionSortList(ListNode* head) {

        ListNode* dummyHead = new ListNode(INT_MIN);

        dummyHead->next = head;

        // ListNode * pre = dummyHead;

        ListNode* cur = dummyHead;


        while(cur->next){

            if(cur->val > cur->next->val){
                ListNode * target = dummyHead->next;
                ListNode * pre = dummyHead;
                while(target->val <= cur->next->val){//stable sort，小于等于才继续遍历
                    target = target->next;
                    pre = pre->next;
                }
                ListNode* temp = cur->next;
                /*delete the cur->next node*/
                cur->next = cur->next->next;
                /*insert operation*/
                pre->next = temp;
                temp->next = target;
                // print(dummyHead);
                continue;
            }
            cur = cur->next;
            // print(dummyHead);
        }

        return dummyHead->next;
    }
};