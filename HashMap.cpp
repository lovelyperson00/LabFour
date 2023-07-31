#include "hashMap.hpp"

hashMap::hashMap(bool hash1, bool coll1) {
}
void hashMap::addKeyValue(string k, string v) {
}
int hashMap::getIndex(string k) {
}

}
int hashMap::calcHash1(string k){
}
void hashMap::getClosestPrime() {
}
void HashMap::reHash() {
	if (numKeys >= (0.7*mapSize)){
		map->dblArray();
	}
}
int hashMap::coll2(int h, int i, string k) {
}
int hashMap::findKey(string k) {
//NOTE: THIS METHOD CANNOT LOOP from index 0 to end of hash array looking for the key.  That destroys any efficiency in run-time. 
}


void hashMap::printMap() {
	cout << "In printMap()" << endl;
	for (int i = 0; i < mapSize; i++) {
		//cout << "In loop" << endl;
		if (map[i] != NULL) {
			cout << map[i]->keyword << ": ";
			for (int j = 0; j < map[i]->currSize;j++) {
				cout << map[i]->values[j] << ", ";
			}
			cout << endl;
		}
	}
}


