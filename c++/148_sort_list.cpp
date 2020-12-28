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

//wrong answer
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


//correct one
//https://leetcode-cn.com/problems/sort-list/solution/148-pai-xu-lian-biao-bottom-to-up-o1-kong-jian-by-/
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
        if(head == NULL)
            return NULL;
        ListNode* cur = head;
        ListNode *tmp; //用来保存最后一个节点地址。
        while(n-- && cur){//假设n > 0
            tmp = cur;
            cur = cur->next;
        }
        tmp->next = nullptr;
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

        ListNode* dummy_head = new ListNode(0);//虚拟头节点是为了，保存链表的头位置：dummy_head->next;
        
        dummy_head->next = head;

        ListNode *cur = head;

        while(cur){
            cur = cur->next;
            size++;
        }

        for(int i = 1 ;i < size;i <<= 1){
            cout<<"i:"<<i<<endl;
            ListNode *tail = dummy_head;
            cur =dummy_head->next;;
            ListNode * first,*second;
            while(cur){
                first = cur;
                second = cut(first,i);
                cur = cut(second,i);

                tail->next = merge(first,second);

                while(tail->next){//把每个merge的链表连起来
                    tail = tail->next;
                }
            }

        }

    return dummy_head->next;

    }
};