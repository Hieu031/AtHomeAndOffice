// ===============================
// File: linked_list.h
// ===============================

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include<stdbool.h>

//Init a strcut to store a node with "data" and "pointer node"
typedef struct node {
    int data;
    struct node* next;
} node;

//create a empty linked list (retuen NULL)
node* list_create();

//insert a new node with "data" at the begging of list
void list_prepend(node** head_ref, int data);

//insert a new node with "data" at the end of list
void list_append(node** head_ref, int data);

//insert a new node with "data" after the given prep_node
//return True if success, false if after prep_node is NULL
bool list_insert_after(node* prep_node, int data);

//insert a new node with "data" at "pos" 
//if pos >= length => appends at end. Retuen True on success.
bool list_insert_at(node** head_ref, int data, unsigned int pos);

//delete the first node with value == key
//return True if delete success, False if not found
bool list_delete_by_Key(node** head_ref, int key);

//delete the node at pos
//return True if delete success, Flase if pos out of range
bool list_delete_at(node** head_ref, unsigned int pos);

//search for the first node with data == key
//Return pointer is node or NULL if not found
node* list_search(node* head, int key);

//Get the current length of list
unsigned int list_length(node* head);

//reverse list in-place
void list_reverse(node** head_ref);

//check list empty
bool list_is_empty(node* head);

//print list content 
void list_print(node* head);

//free list
void list_free(node** head_ref);

#endif // LINKED_LIST_H