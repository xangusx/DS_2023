#include <bits/stdc++.h>
using namespace std;

class LinkedList;    

class ListNode{
    private:
        int data;
        ListNode *next;
        ListNode *pre;
    public:
        ListNode():data(0),next(NULL),pre(NULL){}
        ListNode(int a):data(a),next(NULL),pre(NULL){}
        ~ListNode(){}

    friend class LinkedList;
};

class LinkedList{

    private:
        ListNode *head;
        ListNode *tail;            
    
    public:
        LinkedList():head(NULL),tail(NULL){};
        void PrintList();           
        void Push_front(int x);     
        void Push_back(int x);      
        void Delete(ListNode *current);
        void Clear();
        ListNode* begin();
        ListNode* last();                       
};

void LinkedList::PrintList(){

    if (head == NULL) {                      
        // cout << "List is empty.\n";
        return;
    }
    ListNode *current = head;      
    while (current != NULL) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

void LinkedList::Push_front(int x){

    ListNode *newNode = new ListNode(x);
    if(head == NULL && tail == NULL){
        head = newNode;
        tail = newNode;
        return;
    }
    newNode->next = head;
    if(head != NULL)
        head->pre = newNode;       
    head = newNode;       
}

void LinkedList::Push_back(int x){

    ListNode *newNode = new ListNode(x);
    if(head == NULL && tail == NULL){
        head = newNode;
        tail = newNode;
        return;
    }
    newNode->pre = tail;
    if(tail != NULL)
        tail->next = newNode;
    tail = newNode;
}

void LinkedList::Delete(ListNode *current){

    ListNode *nextNode = current->next;
    ListNode *preNode = current->pre;
    if(preNode != NULL)
        preNode->next = current->next;
    else{
        current->pre = NULL;
        head = current->next;
        delete preNode;
        preNode = NULL;
    }
    if(nextNode != NULL)
        nextNode->pre = current->pre;
    else{
        current->next = NULL;
        tail = current->pre;
        delete nextNode;
        nextNode = NULL;
    }
    delete current;
    current = NULL;
}

void LinkedList::Clear(){

    while(head != NULL) {            // Traversal
        ListNode *current = head;
        head = current->next;
        delete current;
        current = NULL;
    }
    tail = NULL;
}

ListNode* LinkedList::begin(){
    return head;
}

ListNode* LinkedList::last(){
    return tail;
}

int main(){
    LinkedList li;

    li.Push_back(4);
    li.Push_back(5);
    li.Push_front(0);
    li.Push_front(0);
    li.Push_back(4);
    li.Push_back(5);
    li.PrintList();
    li.Clear();
    li.Push_front(0);
    li.Push_back(4);
    li.Push_back(5);
    li.PrintList();
    li.Delete(li.last());
    li.PrintList();
    li.Delete(li.begin());
    li.PrintList();
}