#include <stdio.h>
#include "load.h"
#include "getValue.h"
#include "setValue.h"
#include "delItem.h"
#include "unload.h"

// ´òÓ¡Á´±í
void printList(Node* head) {
    printf("List:\n");
    while (head != NULL) {
        printf("Name: %s, Value: %s\n", head->name, head->value);
        head = head->next;
    }
}

int main() {
    Node* head = NULL;
    loadConfigFile(&head, "config.txt");
    printList(head);

    const char* value = getValue(head, "key1");
    if (value != NULL) {
        printf("Value for key1: %s\n", value);
    }
    else {
        printf("Key1 not found.\n");
    }

    setValue(&head, "newKey", "newValue");
    printf("After setting newKey:\n");
    printList(head);

    delItem(&head, "key2");
    printf("After deleting key2:\n");
    printList(head);

    unload(&head);
    printf("After unloading:\n");
    printList(head);

    return 0;
}
