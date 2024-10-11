#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

struct Node {
    public:
        int id;
        Node* parent;
        vector<Node*> *children;
        Node(int id)
            : id(id),
              parent(NULL),
              children(new vector<Node*>()) {
        }
        bool operator<(const Node& node) {
            return this->id < node.id;
        }
};

// Node の情報表示
std::ostream& operator<<(std::ostream &strm, const Node& node) {

    string parent_str;
    if (node.parent != NULL) {
        parent_str = "parent = " + to_string(node.parent->id);
    } else {
        parent_str = "parent = -1";
    }

    int depth = 0;
    auto current = &node;
    while (current->parent != NULL) {
        current = current->parent;
        depth++;
    }
    string depth_str = "depth = " + to_string(depth);

    string type_str;
    if (node.parent == NULL) {
        type_str = "root";
    } else if (node.children->size() == 0) {
        type_str = "leaf";
    } else {
        type_str = "internal node";
    }

    string children_str = "[";

    if (node.children->size() > 0) {
        auto it = node.children->begin();
        children_str += to_string((*it)->id);
        it = next(it);
        for (; it != node.children->end(); it = next(it)) {
            children_str += ", " + to_string((*it)->id);
        }
    }
    children_str += "]";


    return strm << "node " << node.id << ": " << parent_str << ", " << depth_str << ", " << type_str << ", " << children_str;
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

        // 子ノードの数取得
        int k;
        cin >> k;

        // 子ノード情報取得
        for (int j = 0; j < k; j++) {
            int c;
            cin >> c;
            auto current_child_it = node_infos.find(c);
            pair<int, Node*> current_child;
            if (current_child_it == node_infos.end()) {
                // 値が存在しなかった
                current_child = make_pair(c, new Node(c));
                node_infos.insert(current_child);
            } else {
                current_child = *current_child_it;
            }

            current_child.second->parent = current.second;
            current.second->children->push_back(current_child.second);
        }
    }

    // 標準出力
    for (auto n : node_infos) {
        cout << *(n.second) << endl;
    }

    return 0;
}

