#pragma once
#include<listnode.h>
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

using namespace std;

typedef int SLTDataType;

typedef struct SListNode
{
    SLTDataType data;
    struct SListNode *next;//存放下一个指针节点
}SListNode;

//打印列表
void SListPrint(SListNode *phead){
    SListNode *cur = phead; //一般头指针是不移动的，创建一个指针变量来移动
    while (cur)
    {
        printf("%d->",cur->data);
        cur = cur->next;
    }
    printf("null\n");
}

// 申请节点
SListNode *SListBuyNode(SLTDataType x){
    SListNode *newnode = new SListNode;
    if(newnode == NULL){ // 判断是否成功开辟了节点
        perror("new: ");
        exit(-1);
    }
    newnode->data=x;
    newnode->next = NULL;
    return newnode; //  返回节点地址
}

// 尾插
void SListPushBack(SListNode** pphead, SLTDataType x){
    assert(pphead);
    SListNode* newnode = SListBuyNode(x);
    if(*pphead == NULL)// 链表为空
    {
        *pphead = newnode;  // 直接将头节点置为需要插入的节点
    }
    else{
        SListNode* cur = *pphead;
        while (cur->next)
        {
            cur = cur->next;
        }
        cur->next = newnode; //将结尾点中存放的地址置为插入结点的地址
    }
}

// 头插
void SListHeadInsert(SListNode **pphead, SLTDataType x){
    SListNode *newnode = SListBuyNode(x);
    newnode->next = *pphead;
    *pphead = newnode;
}

// 尾删
void SListPopback(SListNode **pphead){
    assert(*pphead);
    SListNode *cur = new SListNode;
    SListNode *next = new SListNode;
    if((*pphead)->next == NULL){
        free(*pphead);
        *pphead = NULL;
    }

    while(next->next){
        cur = next;
        next = next->next;
    }
    delete next;
    next = NULL;
    cur->next = NULL;
}

// 头删
void SListPopFront(SListNode **pphead){
    assert(*pphead);
    SListNode *next = (*pphead)->next; // 记录第二个结点的地址
    free(*pphead);
    *pphead = next;
}

// 指定位置后面插入
void SListInsert(SListNode **pphead,SListNode *pos, SLTDataType x){
    assert(pphead && pos);
    SListNode *next = pos->next;
    SListNode *input = SListBuyNode(x);
    pos->next = input;
    input->next = next;    
}

// 在指定位置前面插入
void SListInsert_front(SListNode **pphead,SListNode *pos, SLTDataType x){
    assert(pphead&&pos);
    SListNode *input = SListBuyNode(x);
    SListNode *front = *pphead;
    if(*pphead==pos){
        input->next=pos;
        *pphead = input;
    }else{
        while(front->next != pos)
        {
            front = front->next;
        }
        front->next = input;
        input->next = pos->next;
    }    
}

// 指定位置删除
void SListErase(SListNode** pphead, SListNode* pos){
    assert(pphead&&pos);
    if(pos==*pphead){
        
    }

    if(){

    }
}

// 判断是否有环
bool IFcircle(SListNode **pphead){
    assert(pphead);
    SListNode *fast = *pphead;
    SListNode *slow = *pphead;
    while(fast){
        fast=fast->next;
        fast=fast->next;
        slow = slow->next;
        if(slow==fast){
            return true;
        }
    }
    return false;
}