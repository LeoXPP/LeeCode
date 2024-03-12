#include<vector>
#include<string>
#include<stdio.h>
#include<stack>
using namespace std;

class my_stack {
public:
    int calculate(int x, int y, char operator_) {
        int z;
        switch (operator_) {
        case '+':
            z = x + y;
            break;
        case '-':
            z = x - y;
            break;
        case '*':
            z = x * y;
            break;
        case '/':
            z = x / y;
            break;
        default:
            break;
        }
        return z;
    }

    int evalRPN(vector<char>& tokens) {
        stack<int> nums;
        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i] == '+' || tokens[i] == '-' ||
                tokens[i] == '*' || tokens[i] == '/') {
                int a = nums.top();
                nums.pop();
                int b = nums.top();
                nums.pop();
               nums.push(calculate(a,b,tokens[i]));
            } else {
                nums.push(tokens[i] - '0');
            }
        }
        return nums.top();
    }
    // 239 滑动窗口最大值
    class My_queue{
    public:
        deque<int> dq1;
        void push(int val){
            while(!dq1.empty() && dq1.back()<val){
                dq1.pop_back();
            }
            dq1.push_back(val);
        }
        void pop(int val){
            if(!dq1.empty() && dq1.front() == val){
                dq1.pop_front();
            }
        }
        int get_max(){
            return dq1.front();
        }
    };

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        My_queue que1;
        for(int i=0; i<k;i++){
            que1.push(nums[i]);
        }
        result.push_back(que1.get_max());
        for(int i = k; i<nums.size(); i++){
            que1.push(nums[i]);
            que1.pop(nums[i-k]);
            result.push_back(que1.get_max());
        }
        return result;
    }
};