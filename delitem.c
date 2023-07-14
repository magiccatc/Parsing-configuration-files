#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "delItem.h"

// ɾ��ָ��name�Ľڵ�
void delItem(Node** headRef, const char* name) {
    Node* current = *headRef;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            if (current->prev == NULL) {
                // ɾ��ͷ�ڵ�
                *headRef = current->next;
                if (*headRef != NULL) {
                    (*headRef)->prev = NULL;
                }
            }
            else {
                // ɾ���м��β�ڵ�
                current->prev->next = current->next;
                if (current->next != NULL) {
                    current->next->prev = current->prev;
                }
            }

            free(current->name);
            free(current->value);
            free(current);
            break;
        }
        current = current->next;
    }
}
