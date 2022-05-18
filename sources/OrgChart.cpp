#include "OrgChart.hpp"
#include "IterType.hpp"
#include <queue>

using namespace std;

namespace ariel {

    /// OrgChart class ///
    OrgChart::OrgChart() {
        root = nullptr;
    }

    OrgChart &OrgChart::add_root(std::string root_pos) {
//        this->root = new Node(root_pos, NULL);
        return *this;
    }

    OrgChart &OrgChart::add_sub(std::string pos_dad, std::string pos_son) {
//        for (Iterator iter = begin_level_order(); iter != end_level_order(); ++iter) {
//            if (*iter == pos_dad) {
//                Node *son = new Node(pos_son, iter.get_curr());
//                iter.get_curr()->addSon(son);
//            }
//        }
        return *this;
    }

    OrgChart::Iterator OrgChart::begin_level_order() { return Iterator(IterType::begin_level_order, root); }

    OrgChart::Iterator OrgChart::end_level_order() { return Iterator(IterType::end_level_order, root); }

    OrgChart::Iterator OrgChart::begin_reverse_order() { return Iterator(IterType::begin_reverse_order, root); }

    OrgChart::Iterator OrgChart::reverse_order() { return Iterator(IterType::end_reverse_order, root); }

    OrgChart::Iterator OrgChart::begin_preorder() { return Iterator(IterType::begin_preorder, root); }

    OrgChart::Iterator OrgChart::end_preorder() { return Iterator(IterType::end_preorder, root); }

    OrgChart::Iterator OrgChart::begin() { return Iterator(IterType::begin_level_order, root); }

    OrgChart::Iterator OrgChart::end() { return Iterator(IterType::end_level_order, root); }

    OrgChart::~OrgChart() {}

    std::ostream &operator<<(std::ostream &out, const OrgChart &org) { return out; }

    /// Iterator class ///

    void OrgChart::Iterator::init_level_order(Node *root) {
        std::queue < Node * > queue = std::queue<Node *>();
        queue.push(root);
        Node *temp_curr;
        while (!queue.empty()) {
            temp_curr = queue.front();
            ordered.push_back(queue.front());
            for (Node *node: temp_curr->get_sons()) {
                queue.push(node);
            }
            queue.pop();
        }
    }

    OrgChart::Iterator::Iterator(IterType type, Node *root) {
//        this->ordered = std::vector<Node *>();
//        this->type = type;
//        switch (this->type) {
//
//            case IterType::begin_level_order:
//                init_level_order(root);
//                curr = 0;
//            case IterType::end_level_order:
//                init_level_order(root);
//                curr = ordered.size();
//
//            case IterType::begin_preorder:
//                this->curr = 0;
//            case IterType::begin_reverse_order:
//                this->curr = 0; /// change
//            case IterType::end_preorder:
//                this->curr = 0; /// change
//            case IterType::end_reverse_order:
//                this->curr = 0; /// change
//        }
    }

    Node *OrgChart::Iterator::get_curr() {
        return ordered[curr];
    }

    OrgChart::Iterator &OrgChart::Iterator::operator++() {
//        switch (this->type) {
//
//            case IterType::begin_level_order:
//                ++curr;
//            case IterType::end_level_order:
//                --curr;
//
//            case IterType::begin_preorder:
//                this->curr = 0;
//            case IterType::begin_reverse_order:
//                this->curr = 0; /// change
//            case IterType::end_preorder:
//                this->curr = 0; /// change
//            case IterType::end_reverse_order:
//                this->curr = 0; /// change
//        }
        return *this;
    }

    OrgChart::Iterator OrgChart::Iterator::operator++(int) { return *this; }

    OrgChart::Iterator &OrgChart::Iterator::operator--() {
//        switch (this->type) {
//
//            case IterType::begin_level_order:
//                --curr;
//            case IterType::end_level_order:
//                ++curr;
//
//            case IterType::begin_preorder:
//                this->curr = 0; /// change
//            case IterType::begin_reverse_order:
//                this->curr = 0; /// change
//            case IterType::end_preorder:
//                this->curr = 0; /// change
//            case IterType::end_reverse_order:
//                this->curr = 0; /// change
//        }
        return *this;
    }

    OrgChart::Iterator OrgChart::Iterator::operator--(int) { return *this; }

    bool OrgChart::Iterator::operator==(const Iterator &other) const {
//        return this->ordered[curr]->get_pos() == other.ordered[curr]->get_pos();
        return false;
    }

    bool OrgChart::Iterator::operator!=(const Iterator &other) const {
//        return !(*this == other);
        return false;
    }

    std::string OrgChart::Iterator::operator*() { return " "; }

    std::string *OrgChart::Iterator::operator->() { return NULL; }

};
