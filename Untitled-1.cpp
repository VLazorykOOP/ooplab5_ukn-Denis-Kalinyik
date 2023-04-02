#include <iostream>
#include <cstdlib> // для функції rand()
#include <queue>

using namespace std;

// Клас, що описує вузол бінарного дерева
class Node {
public:
    int key; // ключ вузла
    Node* left; // вказівник на ліве піддерево
    Node* right; // вказівник на праве піддерево

    // Конструктор за замовчуванням
    Node() : key(0), left(NULL), right(NULL) {
        cout << "Створено вузол з ключем " << key << endl;
    }

    // Конструктор з параметром ключа
    Node(int k) : key(k), left(NULL), right(NULL) {
        cout << "Створено вузол з ключем " << key << endl;
    }

    // Деструктор
    ~Node() {
        cout << "Вилучено вузол з ключем " << key << endl;
        delete left;
        delete right;
    }

    // Метод для вставки вузла з ключем k у дерево
    void insert(int k) {
        if (k < key) {
            if (left == NULL) {
                left = new Node(k);
            } else {
                left->insert(k);
            }
        } else if (k > key) {
            if (right == NULL) {
                right = new Node(k);
            } else {
                right->insert(k);
            }
        } else {
            cout << "Вузол з ключем " << k << " вже існує" << endl;
        }
    }

    // Метод для обходу дерева в порядку "завширшки"
    void traverseLevelOrder() {
        if (this == NULL) return;
        queue<Node*> q;
        q.push(this);
        while (!q.empty()) {
            Node* current = q.front();
            q.pop();
            cout << current->key << " ";
            if (current->left != NULL) q.push(current->left);
            if (current->right != NULL) q.push(current->right);
        }
        cout << endl;
    }

    // Метод для обходу дерева в порядку "зворотнього обходу"
    void traversePostOrder() {
        if (this == NULL) return;
        if (left != NULL) left->traversePostOrder();
        if (right != NULL) right->traversePostOrder();
        cout << key << " ";
    }

    // Метод для пошуку вузла з ключем k у дереві
    Node* search(int k) {
        if (k < key) {
            if (left == NULL) {
                return NULL;
            } else {
                return left->search(k);
            }
        } else
                if (k > key) {
            if (right == NULL) {
                return NULL;
            } else {
                return right->search(k);
            }
        } else {
            return this;
        }
    }
};

// Клас, що описує бінарне дерево
class BinaryTree {
public:
    Node* root; // кореневий вузол дерева

    // Конструктор за замовчуванням
    BinaryTree() : root(NULL) {}

    // Деструктор
    ~BinaryTree() {
        delete root;
    }

    // Метод для вставки вузла з ключем k у дерево
    void insert(int k) {
        if (root == NULL) {
            root = new Node(k);
        } else {
            root->insert(k);
        }
    }

    // Метод для обходу дерева в порядку "завширшки"
    void traverseLevelOrder() {
        if (root != NULL) {
            root->traverseLevelOrder();
        }
    }

    // Метод для обходу дерева в порядку "зворотнього обходу"
    void traversePostOrder() {
        if (root != NULL) {
            root->traversePostOrder();
        }
    }

    // Метод для пошуку вузла з ключем k у дереві
    Node* search(int k) {
        if (root == NULL) {
            return NULL;
        } else {
            return root->search(k);
        }
    }
};

int main() {
    srand(time(NULL)); // ініціалізуємо датчик випадкових чисел

    BinaryTree tree;

    // Вставляємо 10 випадкових чисел у дерево
    for (int i = 0; i < 10; i++) {
        int k = rand() % 100;
        cout << "Вставляємо вузол з ключем " << k << endl;
        tree.insert(k);
    }

    // Обходимо дерево в порядку "завширшки"
    cout << "Обхід дерева в порядку \"завширшки\": ";
    tree.traverseLevelOrder();

    // Обходимо дерево в порядку "зворотнього обходу"
    cout << "Обхід дерева в порядку \"зворотнього обходу\": ";
    tree.traversePostOrder();

    // Шукаємо вузол з ключем 42
    Node* node = tree.search(42);
    if (node != NULL) {
        cout << "Знайдено вузол з ключем " << node->key << endl;
    } else {
        cout << "Не знайдено вузла з ключем 42" << endl;
    }

    return 0;
}