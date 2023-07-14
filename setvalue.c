#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "setvalue.h"

// 设置name和value，并将节点插入双向链表中
void setValue(Node** headRef, const char* name, const char* value) {
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
