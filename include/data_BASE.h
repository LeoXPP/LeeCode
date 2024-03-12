
template<typename T>
class TreeNode_xie
{
    public:
        T val;
        TreeNode_xie *left;
        TreeNode_xie *right;
        TreeNode_xie(){val = 0; left = nullptr ; right = nullptr;}
        TreeNode_xie(T data){val = data; left = nullptr; right = nullptr;}
};
