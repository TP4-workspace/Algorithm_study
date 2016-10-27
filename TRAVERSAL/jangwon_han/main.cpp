#include <iostream>
#include <vector>
using namespace std;

class Node{
public:
    Node(int val) : val(val), left(NULL), right(NULL) {};
    int val;
    Node *left;
    Node *right;
};

class Solution{

public:

    void printNode(Node* node){

        if(node->left) printNode(node->left);
        if(node->right) printNode(node->right);
        cout << node->val << " ";;

        return;
    }

    Node* buildNode(vector<int> &preorderVec, vector<int> &inorderVec,
                    int preorderStartIndex, int inorderStartIndex, int size){

        if(size <= 0) return NULL;

        Node* root = new Node(preorderVec[preorderStartIndex]);
        int inorderRootIndex = inorderStartIndex;
        for(int i=inorderStartIndex; i<size+inorderStartIndex; i++){
            if(inorderVec[i] == root->val){
                inorderRootIndex = i;
                break;
            }
        }

        int leftSize = inorderRootIndex-inorderStartIndex;
        int rightSize = (size-leftSize)-1;

        root->left = buildNode(preorderVec,
                               inorderVec,
                               preorderStartIndex+1, inorderStartIndex, leftSize);
        root->right = buildNode(preorderVec,
                                inorderVec,
                                preorderStartIndex+1+leftSize, inorderRootIndex+1, rightSize);

        return root;
    }
};

int main() {
    // your code goes here
    int caseCnt;
    int input;
    int nodeCnt;

    Solution s;
    cin >> caseCnt;
    for(int i=0; i<caseCnt; i++){

        cin >> nodeCnt;

        vector<int> preorderVec;
        vector<int> inorderVec;
        for(int j=0; j<nodeCnt; j++){
            cin >> input;
            preorderVec.push_back(input);
        }

        for(int j=0; j<nodeCnt; j++){
            cin >> input;
            inorderVec.push_back(input);
        }

        s.printNode(s.buildNode(preorderVec, inorderVec, 0, 0, nodeCnt));
        cout << endl;
    }

    return 0;
}

