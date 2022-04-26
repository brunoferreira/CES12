#ifndef CES12_ALUNOINDEXPOINTS_H
#define CES12_ALUNOINDEXPOINTS_H

#include <vector>
#include <map>
#include <IndexPointsAbstract.h>

enum Color { RED, BLACK };

typedef struct Node {
    Color color;
    Node *p;
    Node *left;
    Node *right;
    std::pair<double, long> pair;
} Node;

class RBTree {

public:

    RBTree();

    Node *NIL;
    Node *root;

    Node *new_node();
    void set_node(Node* node, Color color, Node *p, Node *left, Node *right, std::pair<double, long> pair);

    long size();
    long recursive_size(Node *node);
    void insert(std::pair<double, long> pair);
    void left_rotate(Node *x);
    void right_rotate(Node *x);
    void insert_fixup(Node *z);
    std::pair<double, long> *lower_bound(double key);
    std::pair<double, long> *upper_bound(double key);

};


class IndexPointsAluno : public IndexPointsAbstract {
    
public:
    
    long size() ;
        
    void add (double key, long idx ) ;
    
    //look for a range of values
    void find(std::vector<long> &res, double first, double last ) ;
    
    
private: 
    // ALUNO DEVE IMPLEMENTAR ALGO COM O MESMO COMPORTAMENTO DE MULTIMAP
    RBTree _map;
    
};//class


#endif
