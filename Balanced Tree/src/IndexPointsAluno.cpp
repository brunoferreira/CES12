#include <iostream>
#include <IndexPointsAluno.h>

IndexPointsAluno::IndexPointsAluno() {
    this->_map = new redBlackTree();
}

/// returns the number of elements in the index
long IndexPointsAluno::size() { return _map->getSize(); }

/// adds new element to the index. 
void IndexPointsAluno::add (double key, long idx ) { _map->insert(std::make_pair(key,idx)) ; }


void IndexPointsAluno::find(std::vector<long> &res, double first, double last ) {
    
    
//  // it is float, so it is not possible to compare with ==
//  // the only thing that makes sense is too look for a range from
//  // a min value to a max value.
//  // stl::multimap implements this using iterators
//  // you do not need to use iterators, but you need to fill the answer in O(k + logn)
//  // where k is the number of elements in the range from first to last
//  // in other words: NAO VALE FAZER INORDER COMPLETO E SELECIONAR O RANGE
//  // PRECISA UM INORDER ESPERTO QUE ACHA O FIRST em O(log n) E CONTINUA ATE O LAST
//  auto itlow = _map->lower_bound (first);  // itlow points to first
//  auto itup = _map->upper_bound (last);   // itup points to next after last (not to last)
//
//  // covers range [itlow,itup), which is the same as [itlow, last] or [first, last]
//  for (auto it=itlow; it!=itup; ++it)
//    //std::cout << (*it).first << " => " << (*it).second << '\n';
//    res.push_back((*it).second);

        
}//find

void redBlackTree::leftRotate(redBlackTree *T, Node *x) {

    Node *y = x->right;
    x->right = y->left;

    if (y->left != T->nil) {
    
        y->left->parent = x;
    
    }

    y->parent = x->parent;

    if (x->parent == T->nil)
        T->root = y;

    else if (x == x->parent->left)
        x->parent->left = y;

    else
        x->parent->right = y;

    y->left = x;
    x->parent = y;

}

void redBlackTree::rightRotate(redBlackTree *T, Node *y) {

    Node *x = y->left;
    y->left = x->right;

    if (x->right != T->nil)
        x->right->parent = y;

    y->parent = x->parent;

    if (y->parent == T->nil)
        T->root = x;

    else if (y == y->parent->left)
        y->parent->left = x;

    else
        y->parent->right = x;

    x->right = y;
    y->parent = x;
}

void redBlackTree::insertFixUp(redBlackTree *T, Node *z) {

    while (z->parent->color == RED) {
        
        if (z->parent == z->parent->left) {
            Node *y = z->parent->parent->right;

            if (y->color == RED) {

                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;

            } else {
                
                if (z == z->parent->right) {
                
                    z = z->parent;
                    leftRotate(T, z);

                }

                z->parent->color = BLACK;
                z->parent->parent->color = RED;

                rightRotate(T, z->parent->parent);
            }
        } else {

            Node *y = z->parent->parent->left;

            if (y->color == RED) {

                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;

            } else {
                if (z == z->parent->left) {
                    z = z->parent;
                    rightRotate(T, z);
                }
                z->parent->color = BLACK;
                z->parent->parent->color = RED;

                leftRotate(T, z->parent->parent);
            }
        }
    }

    T->root->color = BLACK;
}

// Function to insert a new node with given data
void redBlackTree::insertNode(redBlackTree *T, Node *z) {

    Node *y = T->nil;

    Node *x = T->root;

    while (x != T->nil) {
        y = x;

        if (z->key < x->key)
            x = x->left;
        else
            x = x->right;
    }

    z->parent = y;

    if (y == T->nil)
        T->root = z;
    else if (z->key < y->key)
        y->left = z;
    else
        y->right = z;

    z->left = T->nil;
    z->right = T->nil;
    z->color = RED;

    insertFixUp(T,z);

}

void redBlackTree::insert(std::pair<double, long> pair) {
    Node *node = new Node(pair.first, pair.second);
    insertNode(this, node);
    this->size++;
}

void redBlackTree::inOrder(Node *root) {

    if (root == this->nil)
        return;

    inOrder(root->left);
    inOrder(root->right);
}

long redBlackTree::getSize() {
    return this->size;
}