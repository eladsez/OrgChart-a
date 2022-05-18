#ifndef ORGCHART_A_ORGCHART_H
#define ORGCHART_A_ORGCHART_H

#include <string>
#include <vector>
#include <iostream>
#include "Node.hpp"
#include "IterType.hpp"

namespace ariel {

    class OrgChart {

    private:
        Node* root;

    public:
        class Iterator;

        OrgChart();

        OrgChart &add_root(std::string root_pos);

        OrgChart &add_sub(std::string pos_dad, std::string pos_son);

        Iterator begin_level_order();

        Iterator end_level_order();

        Iterator begin_reverse_order();

        Iterator reverse_order();

        Iterator begin_preorder();

        Iterator end_preorder();

        OrgChart::Iterator begin();

        OrgChart::Iterator end();

        ~OrgChart();

        friend std::ostream &operator<<(std::ostream &out, const OrgChart &org);

        class Iterator {
        private:
            IterType type;
            std::vector<Node *> ordered;
            size_t curr;

            void init_level_order(Node *root);

        public:

            Iterator(IterType type, Node *root);

            Node *get_curr();

            bool operator==(const Iterator &other) const;

            bool operator!=(const Iterator &other) const;

            Iterator &operator++(); // prefix adding

            Iterator operator++(int); // postfix adding

            Iterator &operator--(); // prefix sub

            Iterator operator--(int); // postfix sub

            std::string operator*();

            std::string *operator->();

        };

    };

}
#endif //ORGCHART_A_ORGCHART_H
