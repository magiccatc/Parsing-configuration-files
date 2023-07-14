#include <stdlib.h>
#include "unload.h"

// ж��˫������
void unload(Node** headRef) {
    Node* current = *headRef;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp->name);
        free(temp->value);
        free(temp);
    }
    *headRef = NULL;
}
