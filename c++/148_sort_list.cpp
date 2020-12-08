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


 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
class Solution {
public:
    //test function
    void print_dummyh(ListNode *dummy_head){
        ListNode* cur = dummy_head;
        while(cur->next){

            cout << cur->next->val <<"->" ;
            cur = cur->next;
        }
        cout<<"NULL "<<endl;

    }

     void print(ListNode *head){
        ListNode* cur = head;
        while(cur){

            cout << cur->val <<"->" ;
            cur = cur->next;
        }
        cout<<"NULL "<<endl;

    }
    ListNode * cut(ListNode* head, int n){
        ListNode* cur = head;
        ListNode *tmp; //用来保存最后一个节点地址。
        while(n-- && cur){//假设n > 0
            tmp = cur;
            cur = cur->next;
        }
        tmp->next = NULL;

        return cur;
    }

    ListNode * merge(ListNode *a,ListNode *b){
        if(!a || !b) //a,b任意一个为空，
            return(a?a:b);
        ListNode *data = new ListNode(0);//data是一个dummy head;
        ListNode *cur = data;

        while( a && b){
            cur->next = new ListNode(0);
            if(a->val >= b->val){
                cur->next->val = b->val;
                b = b->next;
            }else{
                cur->next->val = a->val;
                a = a->next;
            }

            cur = cur->next;
        }

        cur->next = a?a:b;

        return data->next;

    }
    ListNode* sortList(ListNode* head) {

        int size = 0;

        ListNode *cur = head;

        while(cur){
            cur = cur->next;
            size++;
        }

        for(int i = 1 ;i < size;i <<= 1){
            cout<<"i:"<<i<<endl;
            ListNode *tail = head;

            ListNode * first,*second;
            
            // first = tail;
            while(tail){
                first = tail;

                cout<<"initial first:";
                print(first);

                second = cut(first,i);

                cout<<"first:";
                print(first);

                tail = cut(second,i);

                cout<<"second:";
                print(second);

                cout<<"first+second:";
                first = merge(first,second);

                print(first);
                while(first){
                    first = first->next;
                }
            }
        }

    return head;

    }
};