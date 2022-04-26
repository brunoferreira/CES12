#include <IndexPointsAluno.h>

RBTree::RBTree() {
    Node *node;
    this->NIL = node;
    this->root = this->NIL;
}

Node *RBTree::new_node() {
    Node *node = (Node*) std::malloc(sizeof(Node));
    node->color = BLACK;
    node->p = this->NIL;
    node->left = this->NIL;
    node->right = this->NIL;
    return node;
}

void RBTree::set_node(Node *node, Color color, Node *p, Node *left, Node *right, std::pair<double, long> pair) {
    node->color = color;
    node->p = p;
    node->left = left;
    node->right = right;
    node->pair = pair;
}

long RBTree::size() {
    return this->recursive_size(this->root);
}

long RBTree::recursive_size(Node *node) {
    long lsize = node->left == this->NIL ? 0 : this->recursive_size(node->left);
    long rsize = node->right == this->NIL ? 0 : this->recursive_size(node->right);
    return 1 + lsize + rsize;
}

void RBTree::insert(std::pair<double, long> pair) {
    Node *z = this->new_node();
    z->pair = pair;
    Node *y = this->NIL;
    Node *x = this->root;
    
    while(x != this->NIL) {
        y = x;
        if(z->pair.first < x->pair.first) {
            x = x->left;
        } else {
            x = x->right;
        }
    }
    z->p = y;
    if(y == this->NIL) {
        this->root = z;
    } else if(z->pair.first < y->pair.first) {
        y->left = z;
    } else {
        y->right = z;
    }
 
    z->left = this->NIL;
    z->right = this->NIL;
    z->color = RED;
    this->insert_fixup(z);
}

void RBTree::left_rotate(Node *x) {
    Node *y = x->right;
    x->right = y->left;
    if(y->left != this->NIL) {
        y->left->p = x;
    }
    y->p = x->p;
    if(x->p == this->NIL) {
        this->root = y;
    } else if(x == x->p->left) {
        x->p->left= y;
    } else {
        x->p->right = y;
    }
    y->left = x;
    x->p = y;
}

void RBTree::right_rotate(Node *x) {
    Node *y = x->left;
    x->left = y->right;
    if(y->right != this->NIL) {
        y->right->p = x;
    }
    y->p = x->p;
    if(x->p == this->NIL) {
        this->root = y;
    } else if(x == x->p->right) {
        x->p->right= y;
    } else {
        x->p->left = y;
    }
    y->right = x;
    x->p = y;
}

void RBTree::insert_fixup(Node *z) {
    while(z->p->color == RED) {
        if(z->p == z->p->p->left) {
            Node *y = z->p->p->right;
            if(y->color == RED) {
                z->p->color = BLACK;
                y->color = BLACK;
                z->p->p->color = RED;
                z = z->p->p;
            } else {
                if(z == z->p->right) {
                    z = z->p;
                    this->left_rotate(z);
                }
                z->p->color = BLACK;
                z->p->p->color = RED;
                this->right_rotate(z->p->p);
            }
        } else {
            Node *y = z->p->p->left;
            if(y->color == RED) {
                z->p->color = BLACK;
                y->color = BLACK;
                z->p->p->color = RED;
                z = z->p->p;
            } else {
                if(z == z->p->left) {
                    z = z->p;
                    this->right_rotate(z);
                }
                z->p->color = BLACK;
                z->p->p->color = RED;
                this->left_rotate(z->p->p);
            }
        }
    }

    this->root->color = BLACK;
}

void RBTree::smart_inorder(std::vector<long> &res, Node *node, double first, double last) {
    if(node->pair.first > first && node->left != this->NIL) {
        this->smart_inorder(res, node->left, first, last);
    }

    if(node->pair.first >= first && node->pair.first < last) {
        res.push_back(node->pair.second);
    }

    if(node->right != this->NIL && (node->pair.first < first || node->pair.first < last)) {
        this->smart_inorder(res, node->right, first, last);
    }
}

/// returns the number of elements in the index
long IndexPointsAluno::size() { return _map.size(); }

/// adds new element to the index. 
void IndexPointsAluno::add (double key, long idx ) { _map.insert(std::make_pair(key,idx)) ; }

void IndexPointsAluno::find(std::vector<long> &res, double first, double last ) {
    res.clear();
    this->_map.smart_inorder(res, this->_map.root, first, last); 
}//find