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
        int get_data(ListNode *current);                  
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

    while(head != NULL) {            
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

int LinkedList::get_data(ListNode *current){
    if(current != NULL)
        return current->data;
    else
        return -1;
}

int main(){
    int q; cin>>q;
    while(q--){
        int n,k;
        cin>>n>>k;
        LinkedList li;
        vector<ListNode*> pos(n);
        li.Clear();

        for(int i=0; i<n; i++){
            li.Push_back(i+1);
            pos[i] = li.last();
        }
        // for(auto i:pos)
        //     cout << *i << " ";
        //     cout << endl;

        int num = 0;
        while(k--){
            cin>>num;
            
        }
    }
}