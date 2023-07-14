#ifndef LOAD_H
#define LOAD_H

// ˫������ڵ�ṹ
typedef struct Node {
    char* name;
    char* value;
    struct Node* prev;
    struct Node* next;
} Node;

// ����һ���½ڵ�
Node* createNode(const char* name, const char* value);

// ������ĩβ����һ���ڵ�
void append(Node** headRef, const char* name, const char* value);

// ���������ļ�
void loadConfigFile(Node** headRef, const char* filename);

// �ͷ������ڴ�
void freeList(Node* head);

#endif /* LOAD_H */
