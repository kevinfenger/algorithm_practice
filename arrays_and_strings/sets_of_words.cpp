#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
using namespace std;

vector<vector<string> > sets;
vector<string> cs;

void print(int k) {

	if(k == sets.size()) {
		for(auto &x : cs) {
			cout << x << " ";
		}
		cout << endl;
	}
	else {

		for(int i = 0; i < sets[k].size(); i++) {
			cs.push_back(sets[k][i]);
			print(k+1);
			cs.pop_back();
		}


	}

}


int main () {
    sets = {{"quick", "slow"}, {"brown", "red"}, {"fox", "dog"}};
    print(0);
    return 0;
}
