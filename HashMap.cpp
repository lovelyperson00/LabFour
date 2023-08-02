#include "HashMap.hpp"
#include "HashNode.hpp"

HashMap::hashMap(bool hash1, bool coll1) {
	for (int i = 0; i < mapSize; i++){
		map[i] = NULL;
	}
}
void HashMap::addKeyValue(string k, string v) {
	int index = getIndex(k);
	if (map[index] == NULL) {
		map[index] = new hashNode(k,v);
		numKeys++;
	}
	else if (map[index]->keyword == k) {
		map[index]->addValue(v);
	}
	else {
		collisions++;
		int i = 0; 
		while (map[index] != NULL && map[index]->keyword != k) {
			index = coll1(index, i++, k) ;
			} if (map[index] != NULL && map[index]-> keyword == k) {
			map[index]->addValue(v);
		}
		else {
			map[index] = new hashNode(k,v);
			numKeys++;
		}
	}
	float loadFactor = (float)numKeys / mapSize;
	if (loadFactor > 0.7) {
		reHash();
	}
}

int HashMap::getIndex(string k) {
	int index;
	if (hash1){
		index = calcHash1(k);
	} else {
		index = calcHash2(k);
	}
	int i = 0;
	while (map[index]) != NULL && map[index]->keyword != k {
		index = coll1(index, i++, k);
	}
	return index;
}

int HashMap::calcHash2(string k){
	int hash2 = 0;
	int prime = 31;
	for (size_t i=0; i<k.length(); i++){
		hash2 += (k[i]* pow(prime, i)) % mapSize;
		hash2 %= mapSize;
	}
	return hash2;
}

int HashMap::calcHash1(string k){
	hasharr[mapsize];
	for (int i = 0; i < mapSize; i++){
		int hash1 = 0;
		keylength = k.length();
		for (int j = 0; j < keylength; j++){
			hash1 = (hash1*7 + ((int)k[keylength-j-1])) % mapSize;
		}
	}
	return hash1;
}

void HashMap::getClosestPrime() {
	int primeNums[26] = [1,2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97];
	
}

void HashMap::reHash() {
	if (numKeys >= (0.7*mapSize)){
		map = map->dblArray();
	}
}

int HashMap::coll1(int h, int i, string k) {
	return (h + i) % mapSize;
}

int HashMap::coll2(int h, int i, string k) {
	h1 = calchash1(k);
	h2 = 1 + (k%(mapSize.getClosestPrime()));
	p = h1 + i*h2;
	return p;
}

int HashMap::findKey(string k) {
//NOTE: THIS METHOD CANNOT LOOP from index 0 to end of hash array looking for the key.  That destroys any efficiency in run-time. 
}


void HashMap::printMap() {
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


