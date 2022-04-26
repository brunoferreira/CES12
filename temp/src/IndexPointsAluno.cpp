#include <IndexPointsAluno.h>

RBTree::RBTree() {
    Node *node;
    this->set_node(node, BLACK, NULL, NULL, NULL, std::make_pair(0, 0));
    this->NIL = node;
    this->root = this->NIL;
}

Node *RBTree::new_node() {
    Node *node;
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


std::pair<double, long> *RBTree::lower_bound(double key) {
    Node *cur = this->root;
    std::pair<double, long> *smallest_bigger;
    while(key != cur->pair.first) {
        while(cur != this->NIL && key > cur->pair.first) {
            cur = cur->right;
        }
        while(cur != this->NIL && key < cur->pair.first) {
            smallest_bigger = &(cur->pair);
            cur = cur->left;
        }
        if(cur == this->NIL) {
            return smallest_bigger;
        }
    }
    return &(cur->pair);
}

std::pair<double, long> *RBTree::upper_bound(double key) {
    Node *cur = this->root;
    
    std::pair<double, long> *smallest_bigger;
    *(smallest_bigger) = std::make_pair(-1, 0);
    while(cur != this->NIL) {
        while(cur != this->NIL && key >= cur->pair.first) {
            cur = cur->right;
        }
        while(cur != this->NIL && key < cur->pair.first) {
            smallest_bigger = &(cur->pair);
            cur = cur->left;
        }
    }
    return smallest_bigger;
}

/// returns the number of elements in the index
long IndexPointsAluno::size() { return _map.size(); }

/// adds new element to the index. 
void IndexPointsAluno::add (double key, long idx ) { _map.insert(std::make_pair(key,idx)) ; }


void IndexPointsAluno::find(std::vector<long> &res, double first, double last ) {
    
    res.clear();

    // it is float, so it is not possible to compare with ==
    // the only thing that makes sense is too look for a range from
    // a min value to a max value. 
    // stl::multimap implements this using iterators 
    // you do not need to use iterators, but you need to fill the answer in O(k + logn)
    // where k is the number of elements in the range from first to last
    // in other words: NAO VALE FAZER INORDER COMPLETO E SELECIONAR O RANGE
    // PRECISA UM INORDER ESPERTO QUE ACHA O FIRST em O(log n) E CONTINUA ATE O LAST
    auto itlow = _map.lower_bound (first);  // itlow points to first
    auto itup = _map.upper_bound (last);   // itup points to next after last (not to last)

    // covers range [itlow,itup), which is the same as [itlow, last] or [first, last]
    for (auto it=itlow; it!=itup; ++it)
        //std::cout << (*it).first << " => " << (*it).second << '\n';
        res.push_back((*it).second);

        
}//find
