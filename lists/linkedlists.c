#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* next;
} node;

node* spawn_link(void)
{
    int data;

    printf("Enter the integer you would like to store in this list: \n");
    scanf("%d", &data);

    node* link = malloc(sizeof(node));
    link -> data = data;

    return link;
}

node* forge_list()
{
    int links;

    node* temp;
    node* head = malloc(sizeof(node));
    node* tail = malloc(sizeof(node));
    temp = head;
    tail = NULL;

    printf("How long would you like to make your list? \n");
    scanf("%d", &links);

    while(temp != NULL) {
        for(int i = 0; i < links; i++) {
            node* join = spawn_link();
            temp -> next = join;
            temp = temp -> next;
        }
        temp = tail;
    }

    return head;
}

void view_list(node* head)
{
    node* temp;

    temp = head;

    while(temp != NULL) {
        printf("Int: %d, at location: %p \n", temp -> data, temp);
        temp = temp -> next;
    }
}

// Doesn't free the deleted node
// Gotta figure out how to delete it while freeing the
// opened node
node* delete_link(node *head)
{
    int data;
    node* temp;

    temp = head;

    printf("Which int would you like to delete? \n");
    scanf("%d", &data);

    while(temp -> next != NULL) {
        if(temp -> next -> data == data) {
           temp -> next = temp -> next -> next;
        } else {
            temp = temp -> next;
        }
    }
    return head;
}

node* insert_link_after(node *head)
{
    int data;
    node* temp;

    temp = head;

    printf("After what int would you like to insert your new link? \n");
    scanf("%d", &data);

    while(temp -> next != NULL) {
        if(temp -> next -> data == data) {
           temp -> next = temp -> next -> next;
        } else {
            temp = temp -> next;
        }
    }
    return head;
}

int main(void)
{
    node* list = forge_list();

    view_list(list);

    delete_link(list);

    view_list(list);

    return 0;
}
