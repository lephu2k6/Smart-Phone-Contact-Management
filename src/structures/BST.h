    #ifndef BST_H
    #define BST_H

    #include "../models/Contact.h"
    using namespace std;

    class BST {
    private:
        struct Node {
            Contact data; // dữ liệu của liên hệ 
            Node* left; // Con trỏ đến nút con bên trái
            Node* right; // Con trỏ đến nút con bên phải
        };
        Node* root; // Con trỏ đến nút gốc của cây BST

        Node* insert(Node* node, const Contact &c);

        Node* remove(Node* node, const string &name);

        Node* findMin(Node* node);

        Contact* search(Node* node, const string &name); 
        void inorder(Node* node);

    public:
        BST(); // Constructer
        ~BST(); // Destructer
        
        void clear(Node* node);
        void insert(const Contact &c);
        void remove(const string &name);
        Contact* search(const string &name);
        void printInorder();

        void updateName(const string &oldName, const string &newName);
    };

    #endif
