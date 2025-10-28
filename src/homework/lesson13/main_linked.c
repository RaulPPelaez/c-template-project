# include "linked_list.h"
# include <stdio.h>
# include <assert.h>
int main(){
    LinkedList* list = linked_list_create();
    Data data1 = {1};
    Data data2 = {2};
    Data data3 = {3};

    linked_list_insert(list, NULL, data1); // Insert 1 at the head
    linked_list_insert(list, list->head, data2); // Insert 2 after 1
    linked_list_insert(list, list->head, data3); // Insert 3 after 1
    // List is now 1 -> 3 -> 2
    linked_list_traverse(list,print_node);
    //linked_list_print(list);
    linked_list_delete(list, list->head->next); // Delete 3
    // List is now 1 -> 2

    linked_list_print(list);
    linked_list_free(&list); // Free the entire list

    assert(list == NULL); // list should be NULL after freeing
    printf("List freed successfully\n");

    
    return 0;
}