// ===============================
// File: linked_list.c
// ===============================

#include"linked_list.h"
#include<stdio.h>
#include<stdlib.h>


//create a empty linked list (retuen NULL)
node* list_create(){
    return NULL;
}

//insert a new node with "data" at the begging of list
void list_prepend(node** head_ref, int data){
    node* new_node = (node*)malloc(sizeof(node));
    if(!new_node){
        perror("Allocation failed!\n");//print error to "stderr"
        exit(EXIT_FAILURE);//exit program and has log to easier debug 
    }

    new_node->data = data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

//insert a new node with "data" at the end of list
void list_append(node** head_ref, int data){
    node* new_node = (node*)malloc(sizeof(node));
    if(!new_node){
        perror("Allocation failed!\n");//print error to "stderr"
        exit(EXIT_FAILURE);//exit program and has log to easier debug 
    }

    //assgin value and pointer for new_node
    new_node->data = data;
    new_node->next = NULL;

    //check if list empty
    if(*head_ref == NULL){
        *head_ref = new_node;
        return;
    }

    //reverst, create a node so as to find last node 
    node* last = *head_ref;
    while (last->next)
    {
        last = last->next;
    }

    //then assgin new_node for last node
    last->next = new_node;
}

//insert a new node with "data" after the given prep_node
//return True if success, false if after prep_node is NULL
bool list_insert_after(node* prep_node, int data){
    //prep_node = NULL is meaning can't insert node after prep_node
    if(prep_node == NULL){
        return false;
    }

    //allacate a new_node to insert
    node* new_node = (node*)malloc(sizeof(node));
    if(!new_node){
        perror("Allocation failed!\n");
        exit(EXIT_FAILURE);
    }

    //assgin new_node
    new_node->data = data;
    new_node->next = prep_node->next; //ensure that list not break
    prep_node->next = new_node;

    return true;
}

//insert a new node with "data" at "pos" 
//if pos >= length => appends at end. Retuen True on success.
bool list_insert_at(node** head_ref, int data, unsigned int pos){
    //if pos = 0 => insert at the begginning of list
    if(pos == 0){
        list_prepend(head_ref, data);
        return 1;
    }

    node* current = *head_ref;
    unsigned int idx = 0;
    //browser to pos need insert
    while(current && idx < pos - 1){
        current = current ->next;
        idx++;
    }

    //pos is out of range, append at end
    if(!current){
        list_append(head_ref, data);
        return 1;
    }

    //insert at pos
    return list_insert_after(current, data);
}

//delete the first node with value == key
//return True if delete success, False if not found
bool list_delete_by_Key(node** head_ref, int key){
    //check list empty
    if(list_is_empty(*head_ref)){
        printf("List empty! can't do this action.\n");
        return 0;
    }

    //create a current node and prepvious node
    node* current = *head_ref;
    node* prep = NULL;
    
    //traverse the list to find the node with data = key
    while (current)
    {
        if(current->data == key){
            //when find node with key, if node need delete not first node
            //update next node
            if(prep){
                prep->next = current->next;
            }
            //if node first, update first pointer
            else{
                *head_ref = current->next;
            }
            //free allocation to delete
            free(current);
            return 1;
        }
        //assign value after dalete node with key
        prep = current;
        current = current->next;
    }
    return 0;    
}

//delete the node at pos
//return True if delete success, Flase if pos out of range
bool list_delete_at(node** head_ref,unsigned int pos){
    //check lsit empty
    if(list_is_empty(*head_ref)){
        printf("List empty! can't do this action.\n");
        return 0;
    }

    //create node current and prep to traverse
    node* current = *head_ref;
    node* prep = NULL;
    
    //if pos = 0, delete head node
    if(pos == 0){
        *head_ref = current->next;
        free(current);
        return 1;
    } 

    //traverse the list find the node at pos
    int idx = 0;
    while (current && idx < pos)
    {
        prep = current;
        current = current->next;
        idx++;
    }

    //if pos is out of range of list
    if(!current){
        printf("Position is out of range.\n");
        return 0;
    }

    //unlink the node and free node
    prep->next = current->next;
    free(current);
    return 1;
}

//search for the first node with data == key
//Return pointer is node or NULL if not found
node* list_search(node* head, int key){
    //check lsit empty
    if(list_is_empty(head)){
        printf("List empty! can't do this action.\n");
        return NULL;
    }
    
    //traverse from head node
    node* current = head;
    while (current)
    {
        if(current->data == key){
            return current;        
        }else{
            current = current->next;
        }
    }

    //return null if not found node with key
    return NULL;
}

//Get the current length of list
unsigned int list_length(node*head){
    
    unsigned int len = 0;
    node* current = head;
    while (current)
    {   
        len++;
        current = current->next;
    }
    return len;    
}

//reverse list in-place
void list_reverse(node** head_ref){
    //create 3 node to reverse
    node* prep = NULL;
    node* current = *head_ref;
    node* next = NULL;

    //traverse and swap to reverse list
    while (current)
    {
        next = current->next; //save node next
        current->next = prep; //reverse link 
        prep = current; //move prep to current
        current = next; //move current to next node
    }
    //update pointer to reverse list 
    *head_ref = prep;     
}

//check list empty
bool list_is_empty(node* head){
    return head == NULL;
}

//print list content 
void list_print(node* head){
    node* current = head;
    printf("[");
    while (current)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("]\n");
}

//free list
void list_free(node** head_ref){
    node* current = *head_ref;
    node* next;
    while (current)
    {
        next = current->next;
        free(current);
        current = next;
    }
    *head_ref = NULL;
}

