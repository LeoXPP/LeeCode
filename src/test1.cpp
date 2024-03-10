#include<stdio.h>
#include<vector>
#include<iostream>
#include "haxibiao.h"
#include "data_BASE.h"
#include "tree_node_ans.hpp"
using namespace std;

class Solution
{
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = nums1.size() - 1;
        n--;
        m--;
        while(n>=0){
            while(m>=0&&nums1[m]>nums2[n]){
                swap(nums1[i--],nums1[m--]);
            }
            swap(nums1[i--],nums2[n--]);
        }

    }
    int maxProfit(vector<int>& prices) {
        int sum_up = 0;
        for(int i = 1; i<prices.size(); i++){
            sum_up += max(0, prices[i] - prices[i-1]);
        }
        return sum_up;
    }
};


static bool treenode_mode = true;
static bool haxi_map_mode = false;

int main( ){
vector<int>  nums1={1,2,5,7,8,0,0,0};
vector<int>  nums2={100,9,6,3,0,10};
vector<int>  nums3={1,2,3,4,5};
string s="dasdadas";
string t="dasdadas";
TreeNode_xie<int> *root = new TreeNode_xie<int>(1);
root->left = new TreeNode_xie<int>(2);
root->right = new TreeNode_xie<int>(3);
root->left->left = new TreeNode_xie<int>(4);
root->left->right = new TreeNode_xie<int>(5);
root->right->left = new TreeNode_xie<int>(6);
root->right->right = new TreeNode_xie<int>(7);


// 哈希表测试
if(haxi_map_mode){
    Solution test1;
    test1.merge(nums1,nums1.size(),nums2,nums2.size());
    bool a = isIsomorphic(s,t);
    cout<<"the answer is : "<<a<<endl;
    int b = test1.maxProfit(nums3);
    cout<<"the bestprofit is : "<<b<<endl;
}

//二叉树测试
if(treenode_mode){
    vector<int> result = preorderTraversal(root);
    for(int i =0; i<result.size();i++){
        cout<<"result["<<i<<"]"<<" = "<< result[i]<<endl;
    }
}


return 0;
}