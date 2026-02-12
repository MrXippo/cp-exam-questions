// NB. Read the Assignment Description before working on this file.

/*
In this file, you find a correctly working implementation of a binary search tree (BST) that stores key-value pairs,
with keys being of type int and values are std::string.
Your task is to add functionality for two of its interface functions, as follows:

count()
Implement this function such that it returns the number of key-value pairs stored in the BST.

largestKey()
Implement this function such that it returns the largest key stored in the BST,
or throws the prescribed exception if the BST is empty.

You get two identical copies of this file, one for each of the two functions to be implemented.
For each of the two files, there is no need to implement the other function as well.
(This keeps your code separated; a mistake in one of them will not harm the other function.)

IN THIS FILE, PLEASE IMPLEMENT largestKey()

*/

#include <stdexcept>
#include <string>
#include <algorithm>
#include <vector>

class BST{
    public:
        BST() : root(nullptr) {}
        ~BST() { delete root; }

        void insert(int newKey, std::string newValue)
        // inserts the combination of newKey and newValue into the BST
        // if newKey already exists in the BST, replace its old value by newValue
        //
        {
            insertKeyValue(root, newKey, newValue);
        }

        std::string getValue(const int& searchKey)
        // throws std::out_of_range("BST") if searchKey is not found in the BST
        {
            return getValueFromNode( root, searchKey );
        }

        int largestKey()
        // TO BE IMPLEMENTED:
        // returns the largest key stored in the BST
        // throw std::out_of_range("BST") if BST is empty
        {
            
        }

    private:
        class Node{
            public:
                int key;
                std::string value;
                Node* left;
                Node* right;
                Node(int k, std::string v) : left(nullptr), right(nullptr), key(k), value(v) {};
                ~Node() { delete left; delete right; }
        };
        Node* root;

        void insertKeyValue(Node*& root, int newKey, std::string newValue)
        {
            if ( root == nullptr ){
                root = new Node(newKey, newValue);
                return;
            }
            if ( newKey == root->key ){
                root->value = newValue;
                return;
            }
            if ( newKey < root->key ){
                insertKeyValue(root->left, newKey, newValue);
                return;
            }
            if ( newKey > root->key ){
                insertKeyValue(root->right, newKey, newValue);
                return;
            }
        }

        std::string getValueFromNode(Node*& root, const int& searchKey)
        {
            if ( root == nullptr ) throw std::out_of_range("BST");
            if ( root->key == searchKey ) return root->value;
            if ( searchKey < root->key ){
                return getValueFromNode(root->left, searchKey);
            }else{
                return getValueFromNode(root->right, searchKey);
            }
        }      	
};
