#pragma once
#include <iostream>

using std::ostream;

template <typename K, typename V>
class KVPair {
public:
	K key;
	V value;

	KVPair() {}
	KVPair(K key) {
		this->key = key;
	}

	KVPair(K key, V value) {
		this->key = key;
		this->value = value;
	}

	void operator =(KVPair<K, V>& other) {
		this->key = other.key;
		this->value = other.value;
	}

	bool operator==(KVPair<K, V>& other) {
		return this->key == other.key;
	}

	bool operator!=(KVPair<K, V>& other) {
		return this->key != other.key;
	}

	bool operator<(const KVPair<K, V> &other) {
		return this->key < other.key;
	}


	bool operator<=(KVPair<K, V>&other){
		return this->key <= other.key;
	}

	bool operator>(KVPair<K, V>& other) {
		return this->key > other.key;
	}

	bool operator>=(KVPair<K, V>& other) {
		return this->key >= other.key;
	}
};

template <typename K, typename V>
ostream &operator <<(ostream &os,const KVPair<K, V> &pair) {
	os << "(" << pair.key << ", " << pair.value << ")";
	return os;
}