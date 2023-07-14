#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "delItem.h"

// 删除指定name的节点
void delItem(Node** headRef, const char* name) {
    Node* current = *headRef;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            if (current->prev == NULL) {
                // 删除头节点
                *headRef = current->next;
                if (*headRef != NULL) {
                    (*headRef)->prev = NULL;
                }
            }
            else {
                // 删除中间或尾节点
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
