#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "setvalue.h"

// ����name��value�������ڵ����˫��������
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
