#include "BinaryTree.h"

int main() {
    BinaryTree tree;

    tree.insertVal(5);
    tree.insertVal(3);
    tree.insertVal(4);
    tree.insertVal(10);
    tree.insertVal(9);

    std::cout << "\n\n" << std::endl;
    std::cout << "Arvore AVL" << std::endl;
    tree.printHierarchy();

    return 0;
}