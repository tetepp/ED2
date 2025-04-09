#include "../include/BinaryTree.h"

TreeNode::TreeNode(int val, int valBal) : data(val), left(nullptr), right(nullptr), bal(valBal) {}

int TreeNode::getData() const { return data; }
TreeNode* TreeNode::getLeft() const { return left; }
void TreeNode::setLeft(TreeNode* node) { left = node; }
TreeNode* TreeNode::getRight() const { return right; }
void TreeNode::setRight(TreeNode* node) { right = node; }
int TreeNode::getBal() const { return bal; }
void TreeNode::setBal(int valBal) { bal = valBal; }

TreeNode::~TreeNode() {}

BinaryTree::BinaryTree() : root(nullptr) {}

BinaryTree::~BinaryTree() {
    deleteTree(root);
}

TreeNode* BinaryTree::insert(TreeNode* node, int val) {
    if (node == nullptr) {
        return new TreeNode(val, 0); 
    }

    if (val < node->getData())
    {
        node->setLeft(insert(node->getLeft(), val));
    } else if (val > node->getData()) {
        node->setRight(insert(node->getRight(), val));
    }

    // Calcula o fator balanceamento
    node->setBal(getHeight(node->getRight()) - getHeight(node->getLeft()));

    if (node->getBal() >= 1) 
    {
        if (node->getLeft() != nullptr && node->getLeft()->getBal() == 1) {
            //ll(node); // LL
        } else if (node->getLeft() != nullptr && node->getLeft()->getBal() == -1) {
            //lr(node); // LR
        }
    } else if (node->getBal() <= -1) {
        if (node->getRight() != nullptr && node->getRight()->getBal() == -1) {
            //rr(node); // RR
        } else if (node->getRight() != nullptr && node->getRight()->getBal() == 1) {
            //rl(node); // RL
        }
    }

    return node;
}

////tirei as implementacoes das funcoes de rotação (n estava funcionando)
/*
/ Rotação LL (Left-Left)
void BinaryTree::ll(TreeNode* node) {
    if (node == nullptr || node->getLeft() == nullptr) return;

    TreeNode* pivot = node->getLeft();
    TreeNode* temp = pivot->getRight();

    // Realiza a rotação
    pivot->setRight(node);
    node->setLeft(temp);

    // Atualiza os fatores de balanceamento
    node->setBal(getHeight(node->getRight()) - getHeight(node->getLeft()));
    pivot->setBal(getHeight(pivot->getRight()) - getHeight(pivot->getLeft()));

    // Atualiza a raiz se necessário
    if (node == root) {
        root = pivot;
    } else {
        // Atualiza o pai do nó rotacionado
        TreeNode* parent = findParent(root, node);
        if (parent != nullptr) {
            if (parent->getLeft() == node) {
                parent->setLeft(pivot);
            } else {
                parent->setRight(pivot);
            }
        }
    }
}

// Rotação RR (Right-Right)
void BinaryTree::rr(TreeNode* node) {
    if (node == nullptr || node->getRight() == nullptr) return;

    TreeNode* pivot = node->getRight();
    TreeNode* temp = pivot->getLeft();

    // Realiza a rotação
    pivot->setLeft(node);
    node->setRight(temp);

    // Atualiza os fatores de balanceamento
    node->setBal(getHeight(node->getRight()) - getHeight(node->getLeft()));
    pivot->setBal(getHeight(pivot->getRight()) - getHeight(pivot->getLeft()));

    // Atualiza a raiz se necessário
    if (node == root) {
        root = pivot;
    } else {
        // Atualiza o pai do nó rotacionado
        TreeNode* parent = findParent(root, node);
        if (parent != nullptr) {
            if (parent->getLeft() == node) {
                parent->setLeft(pivot);
            } else {
                parent->setRight(pivot);
            }
        }
    }
}

// Rotação LR (Left-Right)
void BinaryTree::lr(TreeNode* node) {
    if (node == nullptr || node->getLeft() == nullptr) return;
    
    // Primeiro rotaciona à esquerda o filho à esquerda
    rr(node->getLeft());
    
    // Depois rotaciona à direita o nó desbalanceado
    ll(node);
}

// Rotação RL (Right-Left)
void BinaryTree::rl(TreeNode* node) {
    if (node == nullptr || node->getRight() == nullptr) return;
    
    // Primeiro rotaciona à direita o filho à direita
    ll(node->getRight());
    
    // Depois rotaciona à esquerda o nó desbalanceado
    rr(node);
}

*/

TreeNode* BinaryTree::findParent(TreeNode* current, TreeNode* child) {
    if (current == nullptr || current == child) {
        return nullptr;
    }
    if ((current->getLeft() == child) || (current->getRight() == child)) {
        return current;
    }
    TreeNode* leftSearch = findParent(current->getLeft(), child);
    if (leftSearch != nullptr) {
        return leftSearch;
    }
    return findParent(current->getRight(), child);
}

void BinaryTree::insertVal(int val, int valBal) {
    root = insert(root, val);
}

void BinaryTree::deleteTree(TreeNode* node) {
    if (node != nullptr) {
        deleteTree(node->getLeft());
        deleteTree(node->getRight());
        delete node;
    }
}

void BinaryTree::root_left_right(TreeNode* node) {
    if (node != nullptr) {
        std::cout << node->getData() << " (bal = " << node->getBal() << ") ";
        root_left_right(node->getLeft());
        root_left_right(node->getRight());
    }
}

void BinaryTree::left_root_right(TreeNode* node) {
    if (node != nullptr) {
        left_root_right(node->getLeft());
        std::cout << node->getData() << " (bal = " << node->getBal() << ") ";
        left_root_right(node->getRight());
    }
}

void BinaryTree::left_right_root(TreeNode* node) {
    if (node != nullptr) {
        left_right_root(node->getLeft());
        left_right_root(node->getRight());
        std::cout << node->getData() << " (bal = " << node->getBal() << ") ";
    }
}

int BinaryTree::lenghtTree(TreeNode* node) {
    if (node != nullptr) {
        return 1 + lenghtTree(node->getLeft()) + lenghtTree(node->getRight());
    }
    return 0;
}

TreeNode* BinaryTree::getRoot() {
    return root;
}

void BinaryTree::printPreOrder() {
    root_left_right(root);
    std::cout << std::endl;
}

void BinaryTree::printInOrder() {
    left_root_right(root);
    std::cout << std::endl;
}

void BinaryTree::printPostOrder() {
    left_right_root(root);
    std::cout << std::endl;
}

int BinaryTree::getTreeSize() {
    return lenghtTree(root);
}

void TreeNode::printTree(const std::string& prefix, bool isLeft) {
    // Caso exista filho à direita, chama recursivamente para ele
    if (right) {
        right->printTree(prefix + (isLeft ? "│   " : "    "), false);
    }

    // Exibe o prefixo (indentação) e o tipo de aresta (└── ou ┌──)
    std::cout << prefix;
    std::cout << (isLeft ? "└── " : "┌── ");
    std::cout << data << " (bal = " << bal << ")" << std::endl;

    // Caso exista filho à esquerda, chama recursivamente para ele
    if (left) {
        left->printTree(prefix + (isLeft ? "    " : "│   "), true);
    }
}

void BinaryTree::print() {
    if (root) {
        root->printTree("", true); 
    } else {
        std::cout << "Árvore vazia!" << std::endl;
    }
}

int BinaryTree::getHeight(TreeNode* node) {
    if (node == nullptr) return 0;
    return 1 + std::max(getHeight(node->getLeft()), getHeight(node->getRight()));
}
