#include <iostream>
using namespace std;

class Node {
public:
    int score;
    Node* left;
    Node* right;
    int height;

    Node(int value) {
        score = value;
        left = right = NULL;
        height = 1;
    }
};

// Get height
int getHeight(Node* n) {
    return n ? n->height : 0;
}

// Balance factor
int getBalance(Node* n) {
    return n ? getHeight(n->left) - getHeight(n->right) : 0;
}

// Right rotation
Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = 1 + max(getHeight(y->left), getHeight(y->right));
    x->height = 1 + max(getHeight(x->left), getHeight(x->right));
    return x;
}

// Left rotation
Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = 1 + max(getHeight(x->left), getHeight(x->right));
    y->height = 1 + max(getHeight(y->left), getHeight(y->right));
    return y;
}

// AVL Insert
Node* insertScore(Node* root, int score) {
    if (!root) return new Node(score);

    if (score < root->score) root->left = insertScore(root->left, score);
    else if (score > root->score) root->right = insertScore(root->right, score);
    else return root; // duplicate scores not allowed

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    int balance = getBalance(root);

    // LL
    if (balance > 1 && score < root->left->score) return rightRotate(root);
    // RR
    if (balance < -1 && score > root->right->score) return leftRotate(root);
    // LR
    if (balance > 1 && score > root->left->score) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    // RL
    if (balance < -1 && score < root->right->score) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// Find minimum node
Node* minValueNode(Node* node) {
    Node* current = node;
    while (current && current->left) current = current->left;
    return current;
}

// AVL Delete
Node* removeScore(Node* root, int score) {
    if (!root) return root;

    if (score < root->score) root->left = removeScore(root->left, score);
    else if (score > root->score) root->right = removeScore(root->right, score);
    else {
        // node with one or zero children
        if (!root->left || !root->right) {
            Node* temp = root->left ? root->left : root->right;
            if (!temp) { temp = root; root = NULL; }
            else *root = *temp;
            delete temp;
        } else {
            Node* temp = minValueNode(root->right);
            root->score = temp->score;
            root->right = removeScore(root->right, temp->score);
        }
    }

    if (!root) return root;

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    int balance = getBalance(root);

    // LL
    if (balance > 1 && getBalance(root->left) >= 0) return rightRotate(root);
    // LR
    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    // RR
    if (balance < -1 && getBalance(root->right) <= 0) return leftRotate(root);
    // RL
    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// Reverse in-order traversal to print top scores
void printTopScores(Node* root) {
    if (!root) return;
    printTopScores(root->right);
    cout << root->score << " ";
    printTopScores(root->left);
}

int main() {
    Node* root = NULL;

    // Example operations
    root = insertScore(root, 50);
    root = insertScore(root, 30);
    root = insertScore(root, 70);
    root = insertScore(root, 60);
    root = insertScore(root, 80);

    cout << "Top Scores: ";
    printTopScores(root);
    cout << endl;

    cout << "Removing score 70..." << endl;
    root = removeScore(root, 70);

    cout << "Top Scores after removal: ";
    printTopScores(root);
    cout << endl;

    return 0;
}
