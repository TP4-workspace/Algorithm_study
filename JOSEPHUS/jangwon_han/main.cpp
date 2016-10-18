#include <iostream>
#include <list>
using namespace std;

int main() {
    // your code goes here
    int caseCnt = 0;
    int N,K;
    cin >> caseCnt;

    for(int i=0; i<caseCnt; i++){
        cin >> N;
        cin >> K;

        list<int> list;
        for(int j=0; j<N; j++){
            list.push_back(j+1);
        }

        auto it = list.begin();
        while(list.size() > 2){
            list.erase(it++);
            if(it == list.end()) it = list.begin();
            for(int j=0; j<K-1; j++){
                it++;
                if(it == list.end()) it = list.begin();
            }
        }

        for(auto it=list.begin(); it!=list.end(); it++){
            cout << *it << " ";
        }
    }

    return 0;
}
