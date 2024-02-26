#include<stdio.h>
#include<vector>
#include<iostream>
#include <haxibiao.h>
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
};

// 


int main( ){
vector<int>  nums1={1,2,5,7,8,0,0,0};
vector<int>  nums2={100,9,6,3,0};
Solution test1;
test1.merge(nums1,nums1.size(),nums2,nums2.size() );

// 哈希表测试
string s="dasdadas";
string t="dasdadas";
bool a = isIsomorphic(s,t);
cout<<"the answer is : "<<a<<endl;

return 0;
}