
template<typename T>
class TreeNode_xie
{
    public:
        T val;
        TreeNode_xie<T> *left;
        TreeNode_xie<T> *right;
        TreeNode_xie( T data){
            this->val = data;
            this->left = nullptr;
            this->right = nullptr;
        }
};
