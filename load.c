#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "load.h"

// 创建一个新节点
Node* createNode(const char* name, const char* value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Failed to allocate memory.\n");
        return NULL;
    }
    newNode->name = _strdup(name);
    newNode->value = _strdup(value);
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// 在链表末尾插入一个节点
void append(Node** headRef, const char* name, const char* value) {
    Node* newNode = createNode(name, value);

    if (*headRef == NULL) {
        *headRef = newNode;
    }
    else {
        Node* current = *headRef;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }
}

// 加载配置文件
void loadConfigFile(Node** headRef, const char* filename) {
    FILE* file = NULL;
    if (fopen_s(&file, filename, "r") != 0) {
        printf("Failed to open file: %s\n", filename);
        return;
    }

    char line[256];
    while (fgets(line, sizeof(line), file)) {
        // 忽略空行和注释行
        if (line[0] == '\n' || line[0] == '#') {
            continue;
        }

        // 查找等号位置
        char* equalSign = strchr(line, '=');
        if (equalSign == NULL) {
            printf("Invalid line format: %s", line);
            continue;
        }

        // 提取name和value
        *equalSign = '\0'; // 将等号替换为字符串结束符
        const char* name = line;
        const char* value = equalSign + 1;

        // 去除name和value中的空格
        char* nameEnd = equalSign - 1;
        while (nameEnd >= line && (*nameEnd == ' ' || *nameEnd == '\t')) {
            *nameEnd = '\0';
            nameEnd--;
        }
        while (*value == ' ' || *value == '\t') {
            value++;
        }

        // 插入节点到链表中
        append(headRef, name, value);
    }

    fclose(file);
}

// 释放链表内存
void freeList(Node* head) {
    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        free(temp->name);
        free(temp->value);
        free(temp);
    }
}
