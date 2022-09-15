#include <iostream>

using namespace std;

class Node {
    public:
        long key;
        Node* parent;
        Node* left;
        Node* right;
        Node(long key) : key(key), parent(NULL), left(NULL), right(NULL) {}
};

Node* find(Node* node, int key) {
    if (node->key == key) {
        return node;
    }

    if (key < node->key) {
        if (node->left == NULL) {
            return NULL;
        } else {
            return find(node->left, key);
        }
    } else {
        if (node->right == NULL) {
            return NULL;
        } else {
            return find(node->right, key);
        }
    }
}

Node* get_next_inorder_node(Node* right_node) {

    if (right_node->left != NULL) {
        return get_next_inorder_node(right_node->left);
    }

    return right_node;
}

Node* delete_node(Node* node, int key) {
    Node* target_node = find(node, key);

    if (target_node != NULL) {
        // 見つかったので削除処理を実施

        // 子を持たない場合
        if (target_node->left == NULL
                && target_node->right == NULL) {
            if (target_node->parent != NULL) {
                if (target_node->parent->left != NULL
                        && target_node->parent->left->key == target_node->key) {
                    target_node->parent->left = NULL;
                } else {
                    target_node->parent->right = NULL;
                }
            }
        }

        // 子をひとつだけ持つ場合
        if (target_node->left != NULL
                && target_node->right == NULL) {
            // 左に子がある

            if (target_node->parent != NULL) {

                // 親のどちらに自分がいるか判定
                if (target_node->parent->left != NULL
                        && target_node->parent->left->key == target_node->key) {
                    // 親の左に自分がいた
                    target_node->parent->left = target_node->left;
                } else if (target_node->parent->right != NULL) {
                    // 親の右に自分がいた
                    target_node->parent->right = target_node->left;
                }
            }

            target_node->left->parent = target_node->parent;

        } else if (target_node->left == NULL
                && target_node->right != NULL) {
            // 右に子がある

            if (target_node->parent != NULL) {

                // 親のどちらに自分がいるか判定
                if (target_node->parent->left != NULL
                        && target_node->parent->left->key == target_node->key) {
                    // 親の左に自分がいた
                    target_node->parent->left = target_node->right;
                } else {
                    // 親の右に自分がいた
                    target_node->parent->right = target_node->right;
                }
            }

            target_node->right->parent = target_node->parent;
        }

        // 子をふたつ持つ場合
        if (target_node->left != NULL
                && target_node->right != NULL) {

            Node* next = ::get_next_inorder_node(target_node->right);

            target_node->key = next->key;

            // next の要素を削除
            // next が子を持たない場合

            // 子を持たない場合
            if (next->left == NULL
                    && next->right == NULL) {

                if (next->parent != NULL) {
                    if (next->parent->left != NULL
                            && next->parent->left->key == next->key) {
                        next->parent->left = NULL;
                    } else {
                        next->parent->right = NULL;
                    }
                }
            }

            // 子をひとつだけ持つ場合
            if (next->left != NULL
                    && next->right == NULL) {
                // 左に子がある

                if (next->parent != NULL) {
                    if (next->parent->left != NULL
                            && next->parent->left->key == next->key) {
                        next->parent->left = next->left;
                    } else if (next->parent->right != NULL) {
                        next->parent->right = next->left;
                    }
                }

                next->left->parent = next->parent;

            } else if (next->left == NULL
                    && next->right != NULL) {
                // 右に子がある

                if (next->parent != NULL) {
                    if (next->parent->left != NULL
                            && next->parent->left->key == next->key) {
                        next->parent->left = next->right;
                    } else if (next->parent->right != NULL) {
                        next->parent->right = next->right;
                    }
                }

                next->right->parent = next->parent;
            }

        }

        return target_node;
    } else {
        // 削除したノードはなかった
        return NULL;
    }
}

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

        Node* delete_node(int key) {
            return ::delete_node(this->root_node, key);
        }

        Node* find(int key) {
            return ::find(this->root_node, key);
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
        } else if (operation == "find") {
            int key;
            cin >> key;

            if (bt.find(key) != NULL) {
                cout << "yes" << endl;
            } else {
                cout << "no" << endl;
            }
        } else if (operation == "delete") {
            int key;
            cin >> key;

            bt.delete_node(key);
        } else if (operation == "print") {
            print(bt);
        }

    }

    return 0;
}

