#include <iostream>

using namespace std;

class Node {
    public:
        long key;
        Node* parent;
        Node* left;
        Node* right;
        Node(long key) : key(key) {}
};

class BinaryTree {
    public:
        Node* root_node = NULL;
        void insert(Node* node) {

            // 初期位置設定
            Node* target_parent = NULL;
            Node* target_node = root_node;

            // 初期位置から key を比較していき、
            // 挿入位置を探す
            while (target_node != NULL) {
                target_parent = target_node;
                if (node->key < target_node->key) {
                    // 左のノードへ移動
                    target_node = target_node->left;
                } else {
                    // 右のノードへ移動
                    target_node = target_node->right;
                }
            }

            // 親ノード設定
            node->parent = target_parent;

            // 親の右にぶら下げるか左にぶら下げるか判定
            if (target_parent == NULL) {
                // ツリーが空の場合
                root_node = node;
            } else if (node->key < target_parent->key) {
                target_parent->left = node;
            } else {
                target_parent->right = node;
            }
        }
};

string get_inorder_string(Node* node) {
    string str = "";

    if (node->left != NULL) {
        str += get_inorder_string(node->left);
    }

    if (str != "") {
        str += " ";
    }
    str += to_string(node->key);

    if (node->right != NULL) {
        str += " " + get_inorder_string(node->right);
    }

    return str;
}

string get_inorder_string(BinaryTree bt) {
    return get_inorder_string(bt.root_node);
}

string get_preorder_string(Node* node) {
    string str = to_string(node->key);

    if (node->left != NULL) {
        str += " " + get_preorder_string(node->left);
    }

    if (node->right != NULL) {
        str += " " + get_preorder_string(node->right);
    }

    return str;
}

string get_preorder_string(BinaryTree bt) {
    return get_preorder_string(bt.root_node);
}

string print_preorder(BinaryTree bt) {
    return get_preorder_string(bt);
}

void print(BinaryTree bt) {
    cout << " " << get_inorder_string(bt) << endl;
    cout << " " << get_preorder_string(bt) << endl;
}

int main(int argc, char* argv[]) {

    // 命令の数 N を取得
    unsigned int n;
    cin >> n;

    // BinaryTree 作成
    BinaryTree bt;

    for (int i = 0; i < n; i++) {
        string operation;
        cin >> operation;

        if (operation == "insert") {
            int key;
            cin >> key;

            bt.insert(new Node(key));
        } else if (operation == "print") {
            print(bt);
        }
    }

    return 0;
}

