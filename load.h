#ifndef LOAD_H
#define LOAD_H

// 双向链表节点结构
typedef struct Node {
    char* name;
    char* value;
    struct Node* prev;
    struct Node* next;
} Node;

// 创建一个新节点
Node* createNode(const char* name, const char* value);

// 在链表末尾插入一个节点
void append(Node** headRef, const char* name, const char* value);

// 加载配置文件
void loadConfigFile(Node** headRef, const char* filename);

// 释放链表内存
void freeList(Node* head);

#endif /* LOAD_H */
