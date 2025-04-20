#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "linked_list.h"

int main(){
    node* head = list_create();

    list_append(&head, 10);
    list_prepend(&head, 5);
    list_insert_after(head, 7);        // insert 7 after 5
    list_insert_at(&head, 15, 3);      // insert 15 at pos 3 (end)

    printf("List contents: ");
    list_print(head);

    printf("Length: %u\n", list_length(head));

    printf("Deleting key 7...\n");
    list_delete_by_Key(&head, 7);
    list_print(head);

    printf("Reversing list...\n");
    list_reverse(&head);
    list_print(head);

    list_free(&head);

    return 0;

}




