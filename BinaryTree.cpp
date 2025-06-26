#include <iostream>
using namespace std;

class Node 
{
public:
int info;
    Node*leftchild;
    Node*rightchild;

    //constructor for the node class
    Node()
    {
        leftchild = nullptr; // initialize left child to null
        rightchild= nullptr; // initialize right child to null
    }
};

class BinaryTree
{
public:
    Node*ROOT;

   BinaryTree()
    {
        ROOT = nullptr; //initialize ROOT to null
    }

    void search(int element, Node *&parent, Node *&currentNode)
    {
        // this function searches the current node 
        // specified node as well as the current node of its parent
        currentNode = ROOT;
        parent = nullptr;
        while ((currentNode != nullptr) && (currentNode->info != element))
        {
            parent = currentNode;
            if (element < currentNode->info)
                currentNode = currentNode->leftchild; 
            else
            currentNode = currentNode->rightchild;
        }
    }

   void insert()
    {
        int x;
        cout << "masukkan nilai:";
        cin >> x;

        //step 1 allcoate memory for thge new node
        Node*newNode = new Node;

        //step 2 assign value to the data
        newNode->info = x;

        //step 3 make the left and right child of the new node null
        newNode->leftchild = nullptr; 
        newNode->rightchild= nullptr; 

        // step 4 locate the node which will be the parent of the new node
        Node*parent = nullptr;
        Node*currentNode = nullptr;
        search(x, parent, currentNode);

        //step 5 if parent is NULL
        if (parent == nullptr)
        {
            //5a Mark the new node as ROOT
            ROOT = newNode;

            //5b exit
            return;
        }

        //step 6 if the value in the data field of the new node is less than that of parent
        if (x < parent->info)
        {
            //6a make the left child of the parent point to the new node
            parent->leftchild = newNode;

            //6b exit
            return;
        }

        //step 7 if the value in the data field of the new node is greater than that of parent
        else if (x > parent->info)
        {
            //7a make the right child of the parent point to the new node
            parent->rightchild = newNode;

            //7b exit 
            return;
        }
    }

    bool isEmpty()
    {
        //checks if the tree is empty
        return ROOT ==nullptr;
    }

    void inorder(Node *ptr)
    {
        if(isEmpty())
        {
            cout << "tree is empty" << endl;
            return;
        }
        if (ptr == nullptr)
        return;

        inorder(ptr->leftchild);
        cout << ptr->info << "";//parent
        inorder(ptr->rightchild);
    }
    void preorder(Node *ptr)
    {
        if (isEmpty())
        {
            cout << "tree is empty" << endl;
            return;
        }
        if (ptr == nullptr)
        return;

        cout << ptr->info << "";//parent
        preorder(ptr->leftchild);
        preorder(ptr->rightchild);
    }
    void postorder(Node *ptr)
    {
        if (isEmpty())
        {
            cout << "tree is empty" << endl;
            return;
        }
        if (ptr == nullptr)
        return;

        postorder(ptr->leftchild);
        postorder(ptr->rightchild);
        cout << ptr->info << "";//parent
    }
};    

int main()
{
    BinaryTree x;
    while (true)
    {
        cout << "\nMenu" << endl;
        cout << "1. Implement insert operation" << endl;
        cout << "2. Perform inorder traversal" << endl;
        cout << "3. Perform preorder traversal" << endl;
        cout << "4. Perform postorder traversal" << endl;
        cout << "5. Exit" << endl;
        cout << "\nEnter your choice (1-5) : ";

        char ch;
        cin >> ch;
        cout << endl;

        switch (ch)
        {
        case '1':
        {
            x.insert();
            break;
        }
        case '2':
        {
            x.inorder(x.ROOT);
            break;
        }
        case '3':
        {

            x.preorder(x.ROOT);
            break;
        }
        case '4':
        {

            x.postorder(x.ROOT);
            break;
        }
        case '5':
            return 0;
        default:
        {
            cout << "Invalid option" << endl;
            break;
        }
        }
    }
}