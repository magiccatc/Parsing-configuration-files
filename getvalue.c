#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "getvalue.h"

// ͨ��name����value
const char* getValue(Node* head, const char* name) {
    while (head != NULL) {
        if (strcmp(head->name, name) == 0) {
            return head->value;
        }
        head = head->next;
    }
    return NULL;
}
