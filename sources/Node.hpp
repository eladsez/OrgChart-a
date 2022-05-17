#ifndef ORGCHART_A_NODE_H
#define ORGCHART_A_NODE_H

#include <iostream>
#include <vector>
#include <string>

namespace ariel {

    class Node {
    private:
        std::string position;
        Node *dad;
        std::vector<Node *> sons;

    public:
        Node(std::string pos, Node *dad);

        void addSon(Node *son);

        void replaceDad(Node *dad);

        ~Node();
    };
}


#endif //ORGCHART_A_NODE_H
