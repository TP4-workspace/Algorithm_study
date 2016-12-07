#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
 
#define ALPHA_NUM 26
 
 
class Game {
	private:
		vector<string> result;
		vector<string> stringVector[ALPHA_NUM][ALPHA_NUM];
		int alphaGraph[ALPHA_NUM][ALPHA_NUM];
		int startChar;
		int endChar;
 
	public:
		Game() {
		}
 
		void initGame() {
			int i, j;
			for (i = 0; i < ALPHA_NUM; ++i) {
				for (j = 0; j < ALPHA_NUM; ++j) {
					alphaGraph[i][j] = 0;
					stringVector[i][j].clear();
				}
			}
			result.clear();
 
			startChar = -1;
			endChar = -1;
		}
 
		void addWord(string s) {
			char first = s.at(0);
			char end = s.at(s.size() -1 );
			alphaGraph[first-'a'][end-'a']++;
			stringVector[first-'a'][end-'a'].push_back(s);
		}
 
 
		int getInNum(int index) {
			int i;
			int sum = 0;
			for (i = 0; i < ALPHA_NUM; ++i) {
				sum += alphaGraph[i][index];
			}
			return sum;
		}
 
		int getOutNum(int index) {
			int i;
			int sum = 0;
			for (i = 0; i < ALPHA_NUM; ++i) {
				sum += alphaGraph[index][i];
			}
			return sum;
		}
 
		int getInOutDiff(int index) {
			return getOutNum(index) - getInNum(index);
		}
 
		// return -1 in impossible case
		int getStartEndChar() {
			int i;
			for (i = 0; i < ALPHA_NUM; ++i) {
				int diff = getInOutDiff(i);
				if (diff == 0) {
					continue;
				} else if (diff == -1 && endChar == -1) {
					endChar = i;
				} else if (diff == 1 && startChar == -1) {
					startChar = i;
				} else {
					return -1;
				}
			}
 
			if (startChar > -1 && endChar > -1) {
				return 1;
			} else if (startChar == -1 && endChar == -1) {
				
				for (i = 0; i < ALPHA_NUM; ++i) {
					if (getOutNum(i) > 0)
					startChar = i;
				}
				return 1;
			} else {
				return -1;
			}
		}
 
		void traverseGraph(int prev, int index) {
			int j;
			
			for (j = 0; j < ALPHA_NUM; ++j) {
				while (alphaGraph[index][j] != 0) {
					alphaGraph[index][j]--;
					traverseGraph(index, j);
				}
			}
 
			if (prev != -1) {
				string target = *(stringVector[prev][index].end()-1);
				result.push_back(target);
				stringVector[prev][index].pop_back();
			}
		}
 
		void traverseAll() {
			traverseGraph(-1, startChar);
		}
		
		void print() {
  			std::reverse(result.begin(), result.end());
  			for (auto it = result.begin(), ie = result.end(); it != ie; ++it) {
  				string word = *it;
  				cout << word << " ";
  			}
  			cout << endl;
		}
		
		void printError() {
			cout << "IMPOSSIBLE" << endl;
		}
};
 
 
int main() {
	Game game;
	int count;
	cin >> count;
	
	
	
	for (int i = 0; i < count; ++i) {
		game.initGame();
		
		int n;
		cin >> n;
		
		for (int j = 0; j < n; ++j) {
			string s;
			cin >> s;
			game.addWord(s);
		}
		
		int res = game.getStartEndChar();
		if (res == -1) {
			game.printError();
		} else {
			game.traverseAll();
			game.print();
		}
	}
	
	
	return 0;
}
