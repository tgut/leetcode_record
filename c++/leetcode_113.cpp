#include "iostream"
#include "vector"
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>>result;
    vector<int>path;
    void traverse(TreeNode* root,int count){
        cout<<"traverse begin"<<endl;
        if(!root->left && !root->right && count == 0)
        {
            result.push_back(path);
            return;
        }
        if(!root->left && !root->right)
        {
            return;
        }
        if(root->left)
        {
            path.push_back(root->left->val);
            cout<<"root->left->val" << root->left->val <<endl;
            count -=root->left->val;
            traverse(root->left,count);
            count +=root->left->val;
            path.pop_back();
        }

        if(root->right)
        {
            path.push_back(root->right->val);
            count -=root->right->val;
            cout<<"root->right->val:" << root->right->val << endl;
            traverse(root->right,count);
            count +=root->right->val;
            path.pop_back();
        }
        return;
    }

    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        result.clear();
        path.clear();
        if( root == NULL)
            return result;
        path.push_back(root->val);
        traverse(root,sum - root->val);
        return result;    
    }
};

int main(){
    TreeNode *test = new TreeNode(5);
    test->left = new TreeNode(4);
    test->right = new TreeNode(8);
    test->left->left = new TreeNode(11);
    test->left->right = new TreeNode(0);

    test->left->left->left = new TreeNode(7);
    test->left->left->right = new TreeNode(2);

    test->right->left = new TreeNode(13);
    test->right->right = new TreeNode(4);

    test->right->right->left = new TreeNode(5);
    test->right->right->right = new TreeNode(1);
    cout<<"begin"<<endl;
    Solution a; 
    a.pathSum(test,22);
    cout<<"end"<<endl;


     for(int i= 0;i< a.result.size();i++)
     {
        cout<< "line "<<i<<endl;
        for(int j=0;j<a.result[0].size();j++)
            cout << "["<< i <<"]["<<j<<"]:"<<a.result[i][j]<< " " ;
        cout<<endl;    
    }   
}
