#include <iostream>
#include <string>
using namespace std;

// Node structure for the BST
struct Node {
    string name;
    Node* left;
    Node* right;

    Node(string n) {
        name = n;
        left = right = NULL;
    }
};

// Function to insert a new contact (name) into the BST
Node* INSERT(Node* root, string name) {
    if (root == NULL) {
        return new Node(name); // Create new node if empty
    }

    if (name < root->name) {
        root->left = INSERT(root->left, name);
    } else if (name > root->name) {
        root->right = INSERT(root->right, name);
    }
    // If name is equal, do nothing (avoid duplicates)

    return root;
}

// Function to search for a contact
bool SEARCH(Node* root, string name) {
    if (root == NULL) {
        return false; // Not found
    }
    if (root->name == name) {
        return true; // Found
    }
    if (name < root->name) {
        return SEARCH(root->left, name);
    } else {
        return SEARCH(root->right, name);
    }
}

// Function to find the minimum node (for inorder successor)
Node* findMin(Node* root) {
    while (root && root->left != NULL) {
        root = root->left;
    }
    return root;
}

// Function to delete a contact from the BST
Node* DELETE(Node* root, string name) {
    if (root == NULL) return NULL;

    if (name < root->name) {
        root->left = DELETE(root->left, name);
    } else if (name > root->name) {
        root->right = DELETE(root->right, name);
    } else {
        // Node found
        if (root->left == NULL && root->right == NULL) {
            delete root; // No child
            return NULL;
        } else if (root->left == NULL) {
            Node* temp = root->right; // One child (right)
            delete root;
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left; // One child (left)
            delete root;
            return temp;
        } else {
            // Two children
            Node* successor = findMin(root->right);
            root->name = successor->name;
            root->right = DELETE(root->right, successor->name);
        }
    }
    return root;
}

// Function to display contacts in sorted order (Inorder Traversal)
void DISPLAY(Node* root) {
    if (root != NULL) {
        DISPLAY(root->left);
        cout << root->name << " ";
        DISPLAY(root->right);
    }
}

// Main function to test the Contact List
int main() {
    Node* root = NULL;
    int choice;
    string name;

    do {
        cout << "\n--- Contact List Menu ---\n";
        cout << "1. Insert Contact\n";
        cout << "2. Search Contact\n";
        cout << "3. Delete Contact\n";
        cout << "4. Display Contacts (Sorted)\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter name to insert: ";
                cin >> name;
                root = INSERT(root, name);
                break;

            case 2:
                cout << "Enter name to search: ";
                cin >> name;
                if (SEARCH(root, name))
                    cout << name << " found in contact list.\n";
                else
                    cout << name << " not found.\n";
                break;

            case 3:
                cout << "Enter name to delete: ";
                cin >> name;
                root = DELETE(root, name);
                cout << "Deleted " << name << " (if it existed).\n";
                break;

            case 4:
                cout << "Contacts in sorted order: ";
                DISPLAY(root);
                cout << endl;
                break;

            case 5:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 5);

    return 0;
}