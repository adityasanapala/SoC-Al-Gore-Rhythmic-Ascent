#include<bits/stdc++.h>
using namespace std;

template <typename T>
struct my_node
{
    my_node* next;
    T value;
    my_node(T val,my_node* next):value(val) ,next(next){}
    my_node(T val):value(val){
        next = nullptr;
    }
    my_node(){next = nullptr;}
};

template <typename T>
struct node_list{
my_node<T>* head;
int size =0;

node_list(){
    head = new my_node<T>;
}

void add_node(my_node<T>* p){
    p->next = head->next;
    head -> next = p;
    size++;
}

bool search(T val){
    for(my_node<T>* tmp = head->next;tmp != nullptr; tmp = tmp->next) {if(tmp->value == val){
        return true;}}
    return false;
}

void delete_node_with_value(T val){
    if(!(this->search(val))){
        cout << "element not in the list";
    } else{
        my_node<T>* tmp = head;
        for(;;tmp = tmp->next){
            if(tmp->next->value == val) break;
        }
        my_node<T>* tmp1 = tmp->next->next;
        delete tmp->next;
        tmp->next = tmp1;
        size--;
    }}

~node_list () {
    my_node<T>* current = head->next;
    my_node<T>* deletor = head;
    while(1){
        delete(deletor);
        if(current==nullptr){
            break;
        } else{
            deletor = current;
            current = current->next;
        }
    }


}


};

 
/* For Trial only

int main(){
    int n; cin >> n;
    node_list<int> list;
    while(n != -1){
        my_node<int>* p = new my_node(n);
        list.add_node(p);
        cin >> n;
    }

    cout << list.size << "\n";
    cout << (list.search(2)?"true\n":"false\n");
    cout << (list.search(1)?"true\n":"false\n");
    list.delete_node_with_value(4);
    list.delete_node_with_value(70);
    cout << list.size << "\n";
    cout << (list.search(4)?"true\n":"false\n");
    my_node<int>* p= new my_node(4);
    list.add_node(p);
    cout << list.size << "\n";
    cout << (list.search(4)?"true\n":"false\n");
}

*/