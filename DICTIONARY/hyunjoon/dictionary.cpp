#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <cstdio>
using namespace std;

class Element {
	public:
		bool cycleChecked;
		int mark;
		int parentCount;
		int index;
		
		Element() {
			cycleChecked = false;
			mark = 0;
			parentCount = 0;
			index = 0;
		}
};

class Graph {
	private:
		Element Elems[26];
		bool Edges[26][26];
	
	public: 
		Graph() {
			for (int i = 0; i < 26; ++i) {
				Elems[i].index = i;
			}	
		}
		
		void addEdge(char a, char b) {
			Edges[a-'a'][b-'a'] = true;
		}
		
		void compareTwoWords(char* a, char* b) {
			int i = 0;
			while (1) {
				char ac = a[i];
				char bc = b[i];
				
				if (ac == '\0' || bc == '\0')
					break;
				
				if (ac == bc)
					continue;
					
				addEdge(ac, bc);
				break;
			}
			return;
		}
		
		bool computeIsThereCycleImpl(Element* elem, vector<Element*>* elemHistory) {
			if (elem->cycleChecked)
				return false;
				
			bool res = false;
			elemHistory->push_back(elem);
			for (auto it = elemHistory->begin(), ie = elemHistory->end(); it != ie; ++it) {
				Element* parentElem = *it;
				if (elem == parentElem)
					return true;
			}
			
			elem->cycleChecked = true;
			
			for (int i = 0; i < 26; ++i) {
				if (Edges[elem->index][i]) {
					Element* childElem = &Elems[i];
					res |= computeIsThereCycleImpl(childElem, elemHistory);
				}
			}
			elemHistory->pop_back();
			
			return res;
		}
		
		bool computeIsThereCycle() {
			bool res = false;
			vector<Element*> elems;
			for (int i = 0; i < 26; ++i) {
				elems.clear();
				res |= computeIsThereCycleImpl(&Elems[i], &elems);
			}
			return res;
		}
		
		void printElemImpl(Element* elem, queue<Element*>* elemQueue) {
			if (elem->mark < elem->parentCount) {
				elemQueue->push(elem);
			} else {
				printf("%c", elem->index+'a');
				for (int i = 0; i < 26; ++i) {
					if(Edges[elem->index][i]) 
						Elems[i].mark++;
				}
			}
			return;
		}
		
		void printElem() {
			queue<Element*> elemQueue;
			for (int i = 0; i < 26; ++i) {
				elemQueue.push(&Elems[i]);
			}
			for (int i = 0; i < 26; ++i) {
				printElemImpl(&Elems[i], &elemQueue);
			}
		}
};

int main() {
	// your code goes here
	return 0;
}
