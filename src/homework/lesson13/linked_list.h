// linked_list.h

# pragma once
#include <stdlib.h>
#include <stdio.h>

    typedef struct{
        int value;
    } Data;


    typedef struct Node {
        Data data;
        struct Node* next;
    } Node;

    typedef struct {

        Node* head;

    } LinkedList;

    /**
    *@brief Create a new empty linked list
    *@return A pointer to the newly created linked list
    */
    LinkedList* linked_list_create() {
        LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));
        list->head = NULL;
        return list;
    }
    /**
    *@brief Insert a new node after the given node
    *@param list The linked list to insert the node into
    *@param prev_node The node after which to insert the new node. If NULL, insert at the head.
    *@param data The data to store in the new node
    *@return 0 on success, -1 on failure
    */
    int linked_list_insert(LinkedList* list, Node* prev_node, Data data) {
        Node* new_node = (Node*)malloc(sizeof(Node));
        if (!new_node) {
            return -1; // Memory allocation failed
        }
        new_node->data = data;
        Node* next = prev_node ? prev_node->next : list->head;
        new_node->next = next;
        if (prev_node) {
            prev_node->next = new_node;
        } else {
            list->head = new_node;
        }
        return 0;
    }

    /**
    *@brief Print the values in the linked list
    *@param list The linked list to print
    */
    void linked_list_print(LinkedList* list) {
        Node* current = list->head;
        while (current) {
            printf("%d -> ", current->data.value);
            current = current->next;
        }
        printf("NULL\n");
    }
    /**
    *@brief Delete a node from the linked list
    *@param list The linked list to delete the node from
    *@param target The node to delete
    *@return 0 on success, -1 on failure
    */
    int linked_list_delete(LinkedList* list, Node* target) {
        if (!list->head || !target) {
            return -1; // List is empty or target is NULL
        }
        if (list->head == target) {
            list->head = target->next;
            free(target);
            return 0;
        }
        Node* current = list->head;
        while (current->next && current->next != target) {
            current = current->next;
        }
        if (!current->next) {
            return -1; // Target not found
        }
        current->next = target->next;
        free(target);
        return 0;
        }
    /**
    *@brief Free the entire linked list
    *@param list A pointer to the linked list to free. After freeing, the pointer is set to NULL.
    */
    void linked_list_free(LinkedList** list) {
        if (!list || !*list) {
            return; // List is already NULL
        }
        Node* current = (*list)->head;
        while (current) {
            Node* next = current->next;
            free(current);
            current = next;
        }
        free(*list);
        *list = NULL;
    }

    void print_node(Data* data){
        if (data==NULL){
            printf("NULL\n");
            return;
        }
        printf("%d -> ", data->value);
    }

    typedef* LinkedListOP(Data* data);

        /**
    *@brief Traverse the linked list and apply the given operation to each node
    *@param list The linked list to traverse
    *@param op The operation to apply to each node,
    * a function that takes a Data* as input and returns void
    */
    void linked_list_traverse(LinkedList* list, LinkedListOP* op) {
        if (!list || !op) {
            return;
        }
        Node* current = list->head;
        while (current) {
            op(&current->data);
            current = current->next;
        }
        op(&current->data);
    }