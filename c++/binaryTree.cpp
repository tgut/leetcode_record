    #include "iostream"
using namespace std;
typedef struct node{
    int val;
    struct node *left;
    struct node *right;
    node(int x):val(x),right(NULL),left(NULL){} 
    }NODE;

class binaryTree{
    public:
        void preorder(NODE* root){
            if(!root){
                cout<<"NULL"<<endl;
                return;
            }
            cout<<root->val<<" ";
            preorder(root->left);
            preorder(root->right);
                
        };
        void inorder(NODE* root){
            if(!root){
                cout<<"NULL"<<endl;
                return ;
            }
            inorder(root->left);
            cout<<root->val<<" ";
            inorder(root->right);
        };
        void posorder(NODE* root){
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
    binaryTree b;
    
    // NODE* node0 = new NODE(0);
    // node0->left = new  NODE(1);
    // node0->right = new  NODE(2);//error
    // node0->left->right = new  NODE(3);
    // node0->right->left = new  NODE(4);
    // node0->val = 0;
    // NODE* node1 = new NODE();
    // node1->val = 1;
    // NODE* node2 = new NODE();
    // node2->val = 2;
    // NODE* node3 = new NODE();
    // node3->val = 3;
    // NODE* node4 = new NODE();
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