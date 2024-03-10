
#include <vector>

using namespace std;

void traversal(TreeNode_xie<int> *cur, vector<int>& vec){
    if(cur == nullptr){return;}
    vec.push_back(cur->val);
    traversal(cur->left,vec);
    traversal(cur->right,vec);
}


vector<int> preorderTraversal(TreeNode_xie<int> *root){
    vector<int> result;
    traversal(root, result);
    return result;    
}
