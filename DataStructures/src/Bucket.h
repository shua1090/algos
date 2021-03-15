#pragma once

template <class K, class V>
struct Bucket {
	K key;
	V value;
	Bucket<K, V>* next;

	Bucket()
		: value(value), next(nullptr) {}
	Bucket(const K& key, const V& value)
		: key(key), value(value), next(nullptr) {}
	~Bucket() {
		delete next;
	}
};