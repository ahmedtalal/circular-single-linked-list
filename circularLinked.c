#include "circularLinked.h"
#include <stddef.h>

node *head ;

void createNode(){
    head = NULL ;
}

int isEmpty(){
    if(head == NULL) {
        return 0 ;
    }
    return 1;
}

void firstInsert(int value){
    node *ptr = (node *)malloc(sizeof(node)) ;
    ptr->data = value ;
    node *temp ;

    if(isEmpty() == 0){
        head = ptr;
        ptr->next = head ;
    }else {
        temp = head ;
        while(temp->next != head){
            temp = temp->next ;
        }
       ptr->next = head ;
       temp->next = ptr ;
       head = ptr ;
    }
    printf("item is inserted in the first \n") ;
}

void lastInsert(int value){
    node *ptr = (node *)malloc(sizeof(node)) ;
    ptr->data = value ;
    node *temp ;
    if(isEmpty() == 0){
        head = ptr;
        ptr->next = head ;
    }else {
        temp = head ;
        while(temp->next != head){
            temp = temp->next ;
        }
        temp->next = ptr ;
        ptr->next = head ;
        temp = ptr ;
    }
    printf("item is inserted in the last \n") ;
}

void firstDelete(){
    node *temp ;
    if(isEmpty() == 0){
        printf("the circular linked list is empty \n") ;
    }else if(head->next == head){
        head = NULL;
        printf("the first deleted item is %d \n" , head->data) ;
        free(head) ;
    }else {
        temp = head ;
        while(temp->next != head){
            temp = temp->next ;
        }
        temp->next = head->next ;
        printf("the first deleted item is %d \n" , head->data) ;
        free(head) ;
        head = temp->next ;
    }
}
void lastDelete(){
    node *temp , *temp1 ;
    if(isEmpty() == 0){
        printf("the circular linked list is empty \n") ;
    }else if(head->next == head){
        head = NULL;
        printf("the last deleted item is %d \n" , head->data) ;
        free(head) ;
    }else {
        temp = head ;
        while(temp->next != head){
            temp1 = temp ;
            temp = temp->next ;
        }
        printf("the first deleted item is %d \n" , temp->data) ;
        free(temp) ;
        temp1->next = head ;
    }
}

void searchItemValue(int position){
    node *temp = head ;
    if(isEmpty() == 0){
        printf("the circular linked list is empty \n") ;
    }else if(position <= 0){
        printf("the position must be greater than or equal 1 \n") ;
    }else {
        for(int i = 1 ; i<position ;i++){
                temp = temp->next ;
        }
        printf("\n the item %d is found in position %d \n" , temp->data , position) ;

    }
}
void display(){
    node *temp ;
    if(isEmpty() == 0){
        printf("the circular linked list is empty \n") ;
    }else {
        temp = head ;
        while(temp->next != head){
            printf("%d \t" , temp->data) ;
            temp = temp->next ;
        }
        printf("%d \t" , temp->data) ;
    }
}
