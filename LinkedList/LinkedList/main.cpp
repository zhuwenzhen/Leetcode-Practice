//
//  main.cpp
//  LinkedList
//
//  Created by Wenzhen Zhu on 3/31/17.
//  Copyright © 2017 Wenzhen Zhu. All rights reserved.
//

#include <iostream>
#include <stdlib.h>

using namespace std;

struct node{
    int data;
    node* next; // ref to next node
    node(int x): data(x), next(NULL){}
};

class LinkedList{
    node head, tail;
public:
    void insertFront(int val){
        node *head = NULL; // empty linkedlist
        node *temp; // temporary node
        temp = (node*) malloc(sizeof(node)); // allocate space for node
        temp->data = val;
        temp->next = head;
        head = temp;
    }
    
//    void insertFromBack(int val){
//        node *temp;
//        temp = (node*) malloc(sizeof(node));
//        temp = head;
//        while(temp->next != NULL){
//            temp = temp->next;
//        }
//        
//    }
    void deleteNode(node* node){
        *node = *node->next;
    }
    
    
    void remove(){
        
    }
    
    int search(){
        return 0;
    }
    
    node* reverseList(node* head){
        node* pre = NULL;
        while(head){
            node* next = head->next;
            head->next = pre;
            pre = head;
            head = next;
        }
        return pre;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
