#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>

class TreeNode {
private:
    int data;
    TreeNode* left;
    TreeNode* right;
    int bal;

public:
    TreeNode(int val, int valBal);
    int getData() const;
    TreeNode* getLeft() const;
    void setLeft(TreeNode* node);
    TreeNode* getRight() const;
    void setRight(TreeNode* node);
    int getBal() const;
    void setBal(int valBal);
    void printTree(const std::string& prefix = "", bool isLeft = true);
    ~TreeNode();
};

class BinaryTree {
private:
    TreeNode* root;
    TreeNode* insert(TreeNode* node, int val);
    void deleteTree(TreeNode* node);
    void root_left_right(TreeNode* node);
    void left_root_right(TreeNode* node);
    void left_right_root(TreeNode* node);
    int lenghtTree(TreeNode* node);
    int getHeight(TreeNode* node); // Novo método para calcular altura

public:
    BinaryTree();
    ~BinaryTree();
    TreeNode* getRoot();
    void insertVal(int val, int valBal = 0);
    void printPreOrder();
    void printInOrder();
    void printPostOrder();
    void printHierarchy();
    int getTreeSize();
};

#endif

