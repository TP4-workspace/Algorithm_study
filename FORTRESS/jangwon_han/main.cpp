/*
 *  Couldn't solved so copied idea from
 *  https://github.com/herzfactory/AlgospotRepository/blob/master/CPP/Fortress.cpp
 *
 */

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

class Node{
public:
    int height;
    int x;
    int y;
    int r;
    vector<Node*> childV;
};

class Tree{
public:
    bool isChild(Node* parent, Node* child){
        if(parent->r > child->r)
        {
            if(pow(parent->x - child->x, 2) + pow(parent->y - child->y, 2) <
                    pow(parent->r - child->r, 2)){
                return true;
            }
        }
        return false;
    }

    void buildTree(vector<Node*> &nodeV){
        for(int i=1; i<nodeV.size(); i++){
            buildNode(nodeV[0], nodeV[i]);
        }
    }

    int getMaxDistance(Node *node, int &maxDistance){
        vector<int> distanceV;
        for(int i=0; i<node->childV.size(); i++){
            distanceV.push_back(getMaxDistance(node->childV[i], maxDistance));
        }

        sort(distanceV.begin(), distanceV.end());

        if(distanceV.size() == 0) return 0;
        else if(distanceV.size() >= 2){
            int distance1 = *(distanceV.end()-1);
            int distance2 = *(distanceV.end()-2);
            maxDistance = max(maxDistance, distance1+distance2+2);
        }

        return *(distanceV.end()-1);
    }

private:
    void buildNode(Node* parentNode, Node* unknownNode){
        int siblingFlag = 1;

        for(int i=0; i<parentNode->childV.size(); i++){
            Node* childNode = parentNode->childV[i];
            if(isChild(childNode, unknownNode)){
                buildNode(childNode, unknownNode);
                siblingFlag = 0;
                break;
            }
            else if(isChild(unknownNode, childNode)){
                unknownNode->childV.push_back(childNode);
                parentNode->childV.erase(parentNode->childV.begin()+i);
                parentNode->childV.push_back(unknownNode);
                siblingFlag = 0;
                break;
            }
        }

        if(siblingFlag){
            parentNode->childV.push_back(unknownNode);
        }
    }
};

int main() {
    // your code goes here
    int caseCnt;
    int nodeCnt;

    cin >> caseCnt;
    for(int i=0; i<caseCnt; i++){
        cin >> nodeCnt;

        vector<Node*> nodeV;
        for(int j=0; j<nodeCnt; j++){
            Node* node = new Node();
            cin >> node->x;
            cin >> node->y;
            cin >> node->r;
            nodeV.push_back(node);
        }

        Tree tree;
        tree.buildTree(nodeV);

        int maxDistance = 0;
        maxDistance = max(tree.getMaxDistance(nodeV[0], maxDistance), maxDistance);
        cout << maxDistance << endl;
    }
    return 0;
}
