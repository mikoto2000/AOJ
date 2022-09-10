#include <iostream>
#include <map>
#include <vector>

using namespace std;

struct Node {
    public:
        int id;
        Node* parent;
        Node* sibling;
        Node* left;
        Node* right;
        Node(int id)
            : id(id),
              parent(NULL),
              sibling(NULL),
              left(NULL),
              right(NULL) {
        }
        bool operator<(const Node& node) {
            return this->id < node.id;
        }
};

int get_height(const Node node) {
    if (node.left == NULL && node.right == NULL) {
        return 0;
    }

    int height1 = 0;
    if (node.left != NULL) {
        height1 = get_height(*(node.left)) + 1;
    }
    int height2 = 0;
    if (node.right != NULL) {
        height2 = get_height(*(node.right)) + 1;
    }

    return max(height1, height2);
}

string walk_preorder(Node* node) {
    string str = to_string(node->id);

    if (node->left != NULL) {
        str += " " + walk_preorder(node->left);
    }
    if (node->right != NULL) {
        str += " " + walk_preorder(node->right);
    }
    return  str;
}

string walk_inorder(Node* node) {
    string str = "";

    if (node->left != NULL) {
        str += walk_inorder(node->left);
    }

    if (str.size() > 0) {
        str += " ";
    }

    str += to_string(node->id);

    if (node->right != NULL) {
        if (str.size() > 0) {
            str += " ";
        }
        str += walk_inorder(node->right);
    }

    return  str;
}

string walk_postorder(Node* node) {
    string str = "";

    if (node->left != NULL) {
        str += walk_postorder(node->left);
    }

    if (node->right != NULL) {
        if (str.size() > 0) {
            str += " ";
        }
        str += walk_postorder(node->right);
    }

    if (str.size() > 0) {
        str += " ";
    }

    str += to_string(node->id);

    return  str;
}

int main(int argc, char* argv[]) {

    // 節点の数 N を取得
    unsigned int n;
    cin >> n;

    // 全ノード分オブジェクトを作ってしまう
    map<int, Node*> node_infos;
    for (int i = 0; i < n; i++) {
        // id 取得
        int id;
        cin >> id;

        // id の存在確認
        auto current_it = node_infos.find(id);
        pair<int, Node*> current;
        if (current_it == node_infos.end()) {
            // 値が存在しなかった
            current = make_pair(id, new Node(id));
            node_infos.insert(current);
        } else {
            current = *current_it;
        }

        // 子ノードの取得
        int left, right;
        cin >> left >> right;

        if (left != -1) {
            auto current_child_it = node_infos.find(left);
            pair<int, Node*> current_child;
            if (current_child_it == node_infos.end()) {
                // 値が存在しなかった
                current_child = make_pair(left, new Node(left));
                node_infos.insert(current_child);
            } else {
                current_child = *current_child_it;
            }

            current_child.second->parent = current.second;
            current.second->left = current_child.second;
        }

        if (right != -1) {
            auto current_child_it = node_infos.find(right);
            pair<int, Node*> current_child;
            if (current_child_it == node_infos.end()) {
                // 値が存在しなかった
                current_child = make_pair(right, new Node(right));
                node_infos.insert(current_child);
            } else {
                current_child = *current_child_it;
            }

            current_child.second->parent = current.second;
            current.second->right = current_child.second;
        }

        if (current.second->left != NULL) {
            current.second->left->sibling = current.second->right;
        }
        if (current.second->right != NULL) {
            current.second->right->sibling = current.second->left;
        }
    }

    // ルートノード取得
    Node* root_node = node_infos.begin()->second;
    while(root_node->parent != NULL) {
        root_node = root_node->parent;
    }

    cout << "Preorder" << endl;
    cout << " " <<walk_preorder(root_node) << endl;
    cout << "Inorder" << endl;
    cout << " " <<walk_inorder(root_node) << endl;
    cout << "Postorder" << endl;
    cout << " " <<walk_postorder(root_node) << endl;

    return 0;
}


