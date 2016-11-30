#include <iostream>
#include <stdio.h>
#include <stack>
using namespace std;
 
class Solution{
 
private:
    stack<char> charStack; 
    
    inline void shift(char input){
    	charStack.push(input);
    }
    
    inline void reduce(){
    	while(charStack.size() >= 2){
    	
    	char c1 = charStack.top();
    	charStack.pop();
    	
	    	switch(c1){
	    		case ')':
	    		if(charStack.top() == '('){
	    			charStack.pop();
	    		}
	    		else{
	    			charStack.push(c1);
	    			return;
	    		}
	    		break;
	    		
	    		case '}':
	    		if(charStack.top() == '{'){
	    			charStack.pop();
	    		}
	    		else{
	    			charStack.push(c1);
	    			return;
	    		}
	    		break;
	    		
	    		case ']':
	    		if(charStack.top() == '['){
	    			charStack.pop();
	    		}
	    		else{
	    			charStack.push(c1);
	    			return;
	    		}
	    		break;
	    		
	    		default:
	    		    charStack.push(c1);
	    		    return;
	    		break;
	    	}
    	}
    }
public:
    inline bool isValid(){
    	char input;
    	charStack = stack<char>();
    	
    	while(1){
	    	scanf("%c", &input);
	    	if(input == '\n') break;
	    	
	    	shift(input);
	    	reduce();
    	}
    	
    	if(charStack.size() == 0){
    		return true;
    	}
    	return false;
    }
};
 
int main() {
    // your code goes here
    int C;
    scanf("%d", &C);

	char input = 0;
	while(input != '\n'){
    	scanf("%c", &input);
	}
 
    Solution s;
    for(int i=0; i<C; i++){
        if(s.isValid()){
        	printf("YES\n");
        }
        else
        {
        	printf("NO\n");
        }
    }
 
    return 0;
}
