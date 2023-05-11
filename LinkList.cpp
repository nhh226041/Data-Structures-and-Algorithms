#include <bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node *next;
};
typedef struct Node* node;

node makeNode(int x){
    node tmp = new Node();
    tmp->data = x;
    tmp->next=nullptr;
    return tmp;
}

void insertFirst(node &a, int x){
    node tmp = makeNode(x);
    if(a==nullptr){
        a=tmp;
    }else{
        tmp->next = a;
        a = tmp;
    }
}

void print(node a){
    cout << "--------------------------------\n";
	while(a != NULL){
		cout << a->data << " ";
		a = a->next;
	}
	cout << endl;
	cout << "--------------------------------\n";
}

void insertLast(node &a, int x){
    node tmp = makeNode(x);
    if(a==nullptr){
        a=tmp;
    }else{
        node p = a;
        while(p->next!=nullptr){
            p=p->next;
        }
        p->next=tmp;
    }
}
int main(){
    node head = NULL;
    while(1){
        cout<<"--------MENU---------\n";
        cout<<"1. Insert first node\n";
        cout<<"2. Insert last node\n";
        cout<<"3. Print link lists\n";
        cout<<"0. Exit\n";
        cout<<"----------------------\n";
        cout<<"Your choice: ";
        int choice; cin>>choice;
        if(choice==1){
            int x;
            cout<<"Enter the value: "; cin>>x;
            insertFirst(head, x);
        }else if(choice == 3){
            print(head);
        }else if(choice == 2){
            int x;
            cout<<"Enter the value: "; cin>>x;
            insertLast(head, x);
        }else if(choice==0){
            return 0;
        }
    }
}