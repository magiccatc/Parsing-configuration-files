#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "load.h"

// ����һ���½ڵ�
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

// ������ĩβ����һ���ڵ�
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

// ���������ļ�
void loadConfigFile(Node** headRef, const char* filename) {
    FILE* file = NULL;
    if (fopen_s(&file, filename, "r") != 0) {
        printf("Failed to open file: %s\n", filename);
        return;
    }

    char line[256];
    while (fgets(line, sizeof(line), file)) {
        // ���Կ��к�ע����
        if (line[0] == '\n' || line[0] == '#') {
            continue;
        }

        // ���ҵȺ�λ��
        char* equalSign = strchr(line, '=');
        if (equalSign == NULL) {
            printf("Invalid line format: %s", line);
            continue;
        }

        // ��ȡname��value
        *equalSign = '\0'; // ���Ⱥ��滻Ϊ�ַ���������
        const char* name = line;
        const char* value = equalSign + 1;

        // ȥ��name��value�еĿո�
        char* nameEnd = equalSign - 1;
        while (nameEnd >= line && (*nameEnd == ' ' || *nameEnd == '\t')) {
            *nameEnd = '\0';
            nameEnd--;
        }
        while (*value == ' ' || *value == '\t') {
            value++;
        }

        // ����ڵ㵽������
        append(headRef, name, value);
    }

    fclose(file);
}

// �ͷ������ڴ�
void freeList(Node* head) {
    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        free(temp->name);
        free(temp->value);
        free(temp);
    }
}
