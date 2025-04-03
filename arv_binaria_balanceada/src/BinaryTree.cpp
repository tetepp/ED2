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
        return new TreeNode(val, 0); // Balanceamento inicial = 0
    }

    if (val < node->getData()) {
        node->setLeft(insert(node->getLeft(), val));
    } else if (val > node->getData()) {
        node->setRight(insert(node->getRight(), val));
    }

    // Calcula o balanceamento AVL
    int balance = getHeight(node->getRight()) - getHeight(node->getLeft());
    node->setBal(balance);

    return node;
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
    std::cout << data << " (bal = " << bal << ")" << std::endl; // Inclui o balanceamento

    // Caso exista filho à esquerda, chama recursivamente para ele
    if (left) {
        left->printTree(prefix + (isLeft ? "    " : "│   "), true);
    }
}

void BinaryTree::printHierarchy() {
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