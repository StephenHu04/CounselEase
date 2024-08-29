#pragma once

#include "Dictionary.hpp"
#include "Hasher.hpp"

template<typename Key, typename Val>
class HashTableOpen: public Dictionary<Key, Val> {
protected:
    // an element in a dictionary, contains a key and a value
    struct Record {
        Key k;
        Val v;

        Record() :
                k(Key()), v(Val()) {
        }
        Record(Key x, Val y) :
                k(x), v(y) {
        }
    };

    // a node for the (head of a) linked list at each slot of the hash table
    struct Node {
        Record r;
        Node *next;

        Node(Record record = Record(), Node *node = nullptr) :
                r(record), next(node) {
        }
    };

    // the size of the hash table (total number of slots)
    int M;

    // the underlying (dynamic) array of (dynamic) linked lists
    Node **ht;
    // (Note that ht could have been of type LinkedList<Record>*,
    // but it can be more efficient to use just a Node pointer as a linked list)

    // a method for turning a key into an integer
    // (calls the appropriate Hasher::hash(const Key&) overloaded method)
    int hash(const Key&) const;

public:
    // default constructor
    HashTableOpen(int = 100);

    // destructor
    virtual ~HashTableOpen();

    // remove all records in the dictionary, resetting to the initial state
    virtual void clear() override;

    // retrieve the record that matches the argument key
    // if multiple records match, return an arbitrary one
    virtual Val find(const Key&) const override;

    // add the record as a key-value pair to the dictionary
    virtual void insert(const Key&, const Val&) override;

    // remove the record that matches the argument key from the dictionary
    // if multiple records match, remove an arbitrary one
    virtual void remove(const Key&) override;

    // return the number of records in the dictionary
    virtual int size() const override;
};

//Time complexity would be O(n), n being the size of the array
template<typename Key, typename Val>
HashTableOpen<Key, Val>::HashTableOpen(int maxSize) {
    M = maxSize;
    ht = new Node*[M];
    //goes through the array and sets everything to nullptr
    for (int i = 0; i < M; i++) {
        ht[i] = nullptr;
    }
}

//Time complexity would be O(1) since it can be done in constant time
template<typename Key, typename Val>
HashTableOpen<Key, Val>::~HashTableOpen() {
    clear();
    delete[] ht;
}

//Time complexity would be O(n^2) worst case because it would loop through depending on the length on the array
//then again if there is more than one thing in the linked list, so it would be n*n
template<typename Key, typename Val>
void HashTableOpen<Key, Val>::clear() {
    for (int i = 0; i < M; i++) {
    	 //goes through each node in the linked list to delete it
        while (ht[i] != nullptr) {
            Node *temp = ht[i];
            ht[i] = ht[i]->next;
            delete temp;
        }
    }
}

//Time complexity would be O(n), n being the length of the linked-list
template<typename Key, typename Val>
Val HashTableOpen<Key, Val>::find(const Key &k) const {
    int index = hash(k) % M;
    //goes through each node in the link-list and returns a value if the key matches
    for (Node *curr = ht[index]; curr != nullptr; curr = curr->next) {
        if (curr->r.k == k) {
            return curr->r.v;
        }
    }
    throw std::string("\t*ERROR*::Unidentified Student ID");
}

//Time complexity would be O(1) since it can be done in constant time
template<typename Key, typename Val>
void HashTableOpen<Key, Val>::insert(const Key &k, const Val &v) {
    int index = hash(k) % M;
    ht[index] = new Node(Record(k, v), ht[index]);
}

//Time complexity would be O(n), n being the length of the linked-list
//because it could be at the end of the list
template<typename Key, typename Val>
void HashTableOpen<Key, Val>::remove(const Key &k) {
    int index = hash(k) % M;
    Node *curr = ht[index];
    Node *prev = nullptr;
    //takes node out from linked list
    while (curr != nullptr) {
        if (curr->r.k == k) {
            if (prev != nullptr) {
                prev->next = curr->next;
            } else {
                ht[index] = curr->next;
            }
            delete curr;
            return;
        }
        prev = curr;
        curr = curr->next;
    }
    throw std::string("\t*ERROR*::Unidentified Student ID");
}


//Time complexity would be O(n^2) worst case because it would loop through depending on the length on the array
//then again if there is more than one thing in the linked list, so it would be n*n
template<typename Key, typename Val>
int HashTableOpen<Key, Val>::size() const {
    int count = 0;
    //counts how many items in the dictionary
    for (int i = 0; i < M; i++) {
        for (Node *curr = ht[i]; curr != nullptr; curr = curr->next) {
            count++;
        }
    }
    return count;
}

//Time complexity would be O(1) since it can be done in constant time
template<typename Key, typename Val>
int HashTableOpen<Key, Val>::hash(const Key& k) const {
    return Hasher::hash(k);
}

