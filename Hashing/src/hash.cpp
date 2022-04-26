#include "hash.h"

// LOOK FOR THE COMMENTS IN THE .H 
// TO UNDERSTAND WHAT EACH FUNCTION MUST DO

Hash::Hash(int tablesize, int (*hf) (std::string) ) {

    this->_table.reserve(tablesize);
    for(int i = 0; i < tablesize; i++) {
        std::forward_list<std::string> list;
        this->_table.push_back(list);
    }
    this->_hash_func = hf;
}

int Hash::add(std::string str, int &collisions) { 
    
    int idx = this->hash(str);
    collisions = 0;
    bool in_list = false;
    for(std::string s : this->_table[idx]) {
        collisions++;
        if(str == s) {
            return 0;
        }
    }
    this->_table[idx].push_front(str);
    return 1;

}//add

int Hash::remove(std::string str, int &collisions) { 
    
    int idx = this->hash(str);
    collisions = 0;
    bool in_list = false;
    for(auto it = this->_table[idx].begin(); it != this->_table[idx].end(); it++) {
        collisions++;
        if(*it == str) {
            in_list = true;
            this->_table[idx].remove(str);
            return 1;
        }
    }
    return 0;

}//remove


int Hash::hash(std::string str) { 
    
    return this->_hash_func(str);

}//hash
    
int Hash::contains(std::string str, int &collisions) { 
    
    int idx = this->hash(str);
    collisions = 0;
    bool in_list = false;
    for(std::string s : this->_table[idx]) {
        collisions++;
        if(str == s) {
            return 1;
        }
    }
    return 0;
    
}//contains


int Hash::worst_case() {

    int largest = 0;

    for(int i = 0; i < this->_table.size(); i++) {
        int size = std::distance(this->_table[i].begin(), this->_table[i].end());
        if(size > largest) {
            largest = size;
        }
    }

    return largest;
    
}//worst_case

int Hash::size() {

    int total = 0;
    for(int i = 0; i < this->_table.size(); i++) {
        int size = std::distance(this->_table[i].begin(), this->_table[i].end());
        total += size;
    }

    return total;
    
}//size

