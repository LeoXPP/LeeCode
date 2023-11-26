// 这个头文件里存放的是Leecode里面哈希表题目答案

#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;
// 同构字符串

bool isIsomorphic(string s, string t) {
    unordered_map<char,char>s2t;
    unordered_map<char,char>t2s;
    int i;
    char x,y;
    for(i=0; i<s.size(); i++){
        x=s[i];
        y=t[i];
        if((s2t.count(x)&&s2t[x]!=y)||(t2s.count(y)&&t2s[y]!=x)){
            return false;
        }
        s2t[x]=y;
        t2s[y]=x;
    }
    return true;
}
