#ifndef CES12_ALUNOINDEXPOINTS_H
#define CES12_ALUNOINDEXPOINTS_H

#include <vector>
#include <map>
#include <IndexPointsAbstract.h>
#include <string>

enum Color {RED, BLACK};

struct Node
{
    double key;
    long idx;
    bool color;
    Node *left, *right, *parent;

    Node(double data, long idx) {
        this->key = data;
        this->idx = idx;
        this->color = BLACK;
    }
};

class redBlackTree{
public:
    Node *root;
    Node *nil;
    long size;

    redBlackTree() {
        nil = new Node(0,0);  // ver o retorno
        root = nil;
        size = 0;
    }
    static void leftRotate(redBlackTree *, Node *);
    static void rightRotate(redBlackTree *, Node *);
    static void insertFixUp(redBlackTree *, Node *);
    static void insertNode(redBlackTree *, Node *);
    void insert(std::pair<double, long>);
    long getSize();
    void inOrder(Node *);
};

class IndexPointsAluno : public IndexPointsAbstract {

public:

    IndexPointsAluno();

    long size() ;
        
    void add (double key, long idx ) ;
    
    //look for a range of values
    void find(std::vector<long> &res, double first, double last ) ;
    
    
private: 
    // ALUNO DEVE IMPLEMENTAR ALGO COM O MESMO COMPORTAMENTO DE MULTIMAP
//    std::multimap<double, long> _map;
    redBlackTree* _map;
};//class


#endif
