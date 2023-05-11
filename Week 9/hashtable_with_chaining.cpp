#include <iostream>
#include "linkedlist.cpp"
using namespace std;

struct HashTable{
    int MAX_LENGTH = 4;
    int MAX_CHAIN_LENGTH = 2;
    LinkedList * password = new LinkedList[MAX_LENGTH];

    bool isFull(){
        for (int i = 0; i < MAX_LENGTH; i++)
            if(password[i].head == nullptr)
                return false;
        return true;
    }

    int hashfunc(string user_name){
        int sum = 0;
        for(auto ch:user_name)
            sum += int(ch);
        int hash = sum % MAX_LENGTH;
        return hash;
    }

    bool is_slot_empty(int hash){
        return password[hash].head == nullptr;
    }

    void insert(string user_name,string user_password){
        auto hash = hashfunc(user_name);

        if(password[hash].length<MAX_CHAIN_LENGTH)
            password[hash].insert(user_name.data(),user_password.data());

        else
            cout<<"Linked List reached MAX CAP!\n";
    }

    void print_hashtable(){
        for(int i=0;i<MAX_LENGTH;i++){
            cout<<"["<<i<<"]-->";
            password[i].print_list();
        }
    }

    void hash_lookup(string user_name){

        auto hash = hashfunc(user_name);

        // set mapped linklist head as entry
        auto entry = password[hash].head;

        // traverse through mapped linked list
        while (entry != nullptr) {
            auto name = entry->user_name;

            // if element match with the given user_name
            if (name == user_name) {
                cout << "Password :" << entry->password << endl;
                break;
            }
            //  select next entry
            entry = entry->link;
        }

        // if matching array entry is null
        if (entry == nullptr)
            cout << "Invalid userName" << endl;
    }
};

int main(){
    HashTable * hashtbl = new HashTable;
    cout<<boolalpha<<hashtbl->isFull()<<"\n\n";
    int command=0;
    string user_name;
    string password;

    cout<<"\tMenu\nAdd User -> (1)\nLookUp Password -> (2)\nShow table -> (3)\nExit -> (-1)\n\n";

    while (command!=-1){
        /* code */
        cout << "\nType command:";
        cin >> command;
        switch (command){
        case 1:
            /* insert the new item*/
            cout << "Enter user name:";
            cin >> user_name;
            cout << "Enter password to be saved:";
            cin >> password;
            hashtbl->insert(user_name,password);
            break;
        case 2:
            /* hash lookup password*/
            cout << "Enter user name to look up password:";
            cin >> user_name;
            hashtbl->hash_lookup(user_name);
            break;
        case 3:
            hashtbl->print_hashtable();
            break;
        case -1:

            hashtbl->print_hashtable();
            cout << "Exiting...\n";
            break;
        
        }
    }

    return 0;
}
