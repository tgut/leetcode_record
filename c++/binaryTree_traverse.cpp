#include "iostream"
using namespace std;
struct node{
    int val;
    struct node *left;
    struct node *right;
    node(int x):val(x),left(NULL),right(NULL){};
    };

class binaryTree{
    public:
        void preorder(node* root){
            if(!root){
                cout<<"NULL"<<endl;
                return;
            }
            cout<<root->val<<" ";
            preorder(root->left);
            preorder(root->right);
                
        };
        void inorder(node* root){
            if(!root){
                cout<<"NULL"<<endl;
                return ;
            }
            inorder(root->left);
            cout<<root->val<<" ";
            inorder(root->right);
        };
        void posorder(node* root){
            if(!root){
                cout<<"NULL"<<endl;
                return;
            }
            posorder(root->left);
            posorder(root->right);
            cout<<root->val<<" ";
        };
};

int main(){
    //binaryTree b;// = new binaryTree();
    node* node0 = new node(0);
    node0->left = new  node(1);
    cout<<"here0"<<endl;
    // node* node2 =
     new  node(2);//error
    cout<<"here1"<<endl;
    // node0->right = node2;    
    // node0->left->right = new  node(3);
    // node0->right->left = new  node(4);
    // node4->val = 4;
    // node0->left = node1;
    // node0->right =node2;
    // node1->left = NULL;
    // node1->right = node3;
    // node2->left = node4;
    // node2->right =NULL;
    // b.preorder(node0);
    return 0;
}