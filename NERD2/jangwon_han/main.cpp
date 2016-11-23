#include <iostream>
#include <list>
#include <map>
#include <stdio.h>
using namespace std;

class Solution{

public:
    map<int, int> trueNerds;
    int result;

    Solution() : result(0){

    }

    inline void evaluateNumberOfNerds(){
        int N;
        int p, q;

        scanf("%d",&N);
        for(int i=0; i<N; i++){
            scanf("%d %d",&p, &q);
            result += evaluateNumberOfNerds2(p,q);
            //cout << "result:" << result << endl;
        }
    }

    inline int evaluateNumberOfNerds2(int p, int q){

        if(trueNerds.size() > 0){
            auto it = trueNerds.lower_bound(p);
            if(it != trueNerds.end() && it->second > q)
            {
                return trueNerds.size();
            }

            if(it != trueNerds.begin()){
                it--;
                while(1)
                {
                    if(it->second > q){
                        break;
                    }
                    else if(it == trueNerds.begin()){
                        trueNerds.erase(it);
                        break;
                    }
                    else{
                        trueNerds.erase(it--);
                        continue;
                    }
                }
            }
        }

        trueNerds.insert(pair<int, int>(p, q));
        return trueNerds.size();
    }

    inline void printNumberOfNerds(){
        cout << result << endl;
    }
};

int main() {
    // your code goes here
    int C;
    cin >> C;

    for(int i=0; i<C; i++){
        Solution s;
        s.evaluateNumberOfNerds();
        s.printNumberOfNerds();
    }

    return 0;
}

