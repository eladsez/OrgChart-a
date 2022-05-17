#include "OrgChart.hpp"
#include "IterType.hpp"

namespace ariel {

    /// OrgChart class ///
    OrgChart::OrgChart() {
        root = nullptr;
    }

    OrgChart &OrgChart::add_root(std::string root_pos) {
        this->root = new Node(root_pos, NULL);
        return *this;
    }

    OrgChart &OrgChart::add_sub(std::string pos_dad, std::string pos_son) {

//        Node* son = new Node()
        return *this;
    }

    OrgChart::Iterator OrgChart::begin_level_order() { return Iterator(IterType::begin_level_order); }

    OrgChart::Iterator OrgChart::end_level_order() { return Iterator(IterType::end_level_order); }

    OrgChart::Iterator OrgChart::begin_reverse_order() { return Iterator(IterType::begin_reverse_order); }

    OrgChart::Iterator OrgChart::end_reverse_order() { return Iterator(IterType::end_reverse_order); }

    OrgChart::Iterator OrgChart::begin_preorder() { return Iterator(IterType::begin_preorder); }

    OrgChart::Iterator OrgChart::end_preorder() { return Iterator(IterType::end_preorder); }

    OrgChart::Iterator OrgChart::begin() { return Iterator(IterType::begin_level_order); }

    OrgChart::Iterator OrgChart::end() { return Iterator(IterType::end_level_order); }

    std::ostream &operator<<(std::ostream &out, const OrgChart &org) { return out; }

    /// Iterator class ///

    OrgChart::Iterator::Iterator(IterType type){
        this->type = type;
        switch (this->type) {
            case IterType::begin_level_order:
                this->curr = NULL;
            case IterType::begin_preorder:
                this->curr = NULL;
            case IterType::begin_reverse_order:
                this->curr = NULL; /// change
            case IterType::end_level_order:
                this->curr = NULL; /// change
            case IterType::end_preorder:
                this->curr = NULL; /// change
            case IterType::end_reverse_order:
                this->curr = NULL; /// change

        }
    }

    OrgChart::Iterator &OrgChart::Iterator::operator++() {



        return *this; }

    OrgChart::Iterator OrgChart::Iterator::operator++(int) { return *this; }

    OrgChart::Iterator &OrgChart::Iterator::operator--() { return *this; }

    OrgChart::Iterator OrgChart::Iterator::operator--(int) { return *this; }

    bool OrgChart::Iterator::operator==(const Iterator &other) const { return false; }

    bool OrgChart::Iterator::operator!=(const Iterator &other) const { return false; }

    std::string OrgChart::Iterator::operator*() { return " "; }

    std::string* OrgChart::Iterator::operator->(){return NULL;}

};
