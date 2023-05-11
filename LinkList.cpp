#include <iostream>
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

void insertMiddle(node &a, int x, int pos){
    node tmp = makeNode(x);
    if(a==nullptr){
        a=tmp;
    }else{
        node p = a;
        for(int i = 1; i < pos-1; i++){
            p=p->next;
        }
        node psau = p->next;
        tmp->next = psau;
        p->next=tmp;
    }
}

void insertBefore(node &a, node cur, int x){
    node tmp = makeNode(x);
    if(a==NULL){
        a=tmp;
    }else if(cur==a){
        insertFirst(a, x);
    }else{
        node p = a;
        while(p->next!=cur){
            p=p->next;
        }
        tmp->next=cur;
        p->next=tmp;
    }
}

void insertAfter(node &a, node cur, int x){
    node tmp = makeNode(x);
    if(a==NULL){
        a=tmp;
    }else if(cur==a){
        insertLast(a, x);
    }else{
        node p = cur->next;
        cur->next = tmp;
        tmp->next = p;
    }
}

int main(){
    node head = NULL;
    while(1){
        cout<<"--------MENU---------\n";
        cout<<"1. Insert first node\n";
        cout<<"2. Insert last node\n";
        cout<<"3. Insert middle node\n";
        cout<<"4. Print link lists\n";
        cout<<"0. Exit\n";
        cout<<"----------------------\n";
        cout<<"Your choice: ";
        int choice; cin>>choice;
        if(choice==1){
            int x;
            cout<<"Enter the value: "; cin>>x;
            insertFirst(head, x);
        }else if(choice == 4){
            print(head);
        }else if(choice == 2){
            int x;
            cout<<"Enter the value: "; cin>>x;
            insertLast(head, x);
        }else if(choice==0){
            return 0;
        }else if(choice==3){
            int x, pos;
            cout<<"Enter the value: "; cin>>x;
            cout<<"Enter the pos: "; cin>>pos;
            insertMiddle(head, x, pos);
        }
    }
}
