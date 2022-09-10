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

// Node の情報表示
std::ostream& operator<<(std::ostream &strm, const Node& node) {

    string parent_str;
    if (node.parent != NULL) {
        parent_str = "parent = " + to_string(node.parent->id);
    } else {
        parent_str = "parent = -1";
    }

    string sibling_str = "";
    if (node.sibling != NULL) {
        sibling_str = "sibling = " + to_string(node.sibling->id);
    } else {
        sibling_str = "sibling = -1";
    }

    int degree_count = 0;
    if (node.left != NULL) degree_count++;
    if (node.right != NULL) degree_count++;
    string degree_str = "degree = " + to_string(degree_count);

    int depth = 0;
    auto current = &node;
    while (current->parent != NULL) {
        current = current->parent;
        depth++;
    }
    string depth_str = "depth = " + to_string(depth);

    string height_str = "height = " + to_string(get_height(node));

    string type_str;
    if (node.parent == NULL) {
        type_str = "root";
    } else if (node.left == NULL && node.right == NULL) {
        type_str = "leaf";
    } else {
        type_str = "internal node";
    }

    return strm << "node " << node.id << ": " << parent_str << ", " << sibling_str << ", " << degree_str << ", " << depth_str << ", " << height_str << ", " << type_str;
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

    // 標準出力
    for (auto n : node_infos) {
        cout << *(n.second) << endl;
    }

    return 0;
}

