#include<bits/stdc++.h>
using namespace std;
#define M 1000 // This is table size
typedef long long ll;

// hash function
int my_hash_func(long long key){
//------------------------division method hash function-------------------------------    
    //return key%M;
//----------------------multiplication method hash function---------------------------------
    double a = (sqrt(5) - 1)/2;
    double b = key*a;
    b = b - ll(b);
    return M*b;

}

// node used for linked list
struct my_hash_node{
    long long key;
    string value;
    my_hash_node* next;
    my_hash_node(long long key, string value): key(key), value(value), next(nullptr){}
};

//hash table
struct my_hash_table{
    my_hash_node* arr[M];

//constructor -> initialize all pointers to null
my_hash_table(){
    for(int i=0;i<M;i++){
        arr[i] = nullptr;
    }
}

// add
void add_pair(my_hash_node* p){
    int a = my_hash_func(p->key);
    if(arr[a]==nullptr){ arr[a] = p;}
    else{
        p->next = arr[a];
        arr[a] = p;
    }
}

my_hash_node* search(long long mkey){
    my_hash_node* tmp = arr[my_hash_func(mkey)];
    while(tmp != nullptr){
        if(tmp->key == mkey) return tmp;
        tmp = tmp->next;
    }
    return tmp;
}

string give_value(long long mkey){
    my_hash_node* t1= this->search(mkey);
    if(t1 != nullptr) return t1->value;
    else return "This Number does not exist";
}


void delete_phone_number(long long mkey){
    my_hash_node* t1 = search(mkey);
    if(t1 == nullptr){/*cout << "Key not present in hash table";*/}
    else{
        my_hash_node* tmp = arr[my_hash_func(mkey)];
        if (tmp->key == mkey){
            arr[my_hash_func(mkey)] = tmp->next;
            delete tmp;
        } else{
        while(tmp->next != nullptr){
            if(tmp->next == t1) break;
        }
        tmp->next = t1->next;
        delete t1;

    }
    }
}

};

int main()
{
    long long phone;
    string name;
    my_hash_table phonebook;
    cin >> phone;
    while(phone != -1){
        cin >> name;
        my_hash_node* p = new my_hash_node(phone,name);
        phonebook.add_pair(p);
        cin >> phone;
    }



}