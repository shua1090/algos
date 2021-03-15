#pragma once

#include <string>
#include "Bucket.h"

template <typename K>
struct DefaultHash {
	unsigned long operator()(const K& key) const {
		return reinterpret_cast<unsigned long>(key);
	}
};

template <class K, class V, class Hash = DefaultHash<K>>
class HashMap {
private:
	int mBucketCount;
	Bucket<K, V>* mBuckets;
	Hash mHash;
	V ERROR;

public:
	HashMap(int bucketCount=10) {
		mBucketCount = bucketCount;
		mBuckets = new Bucket<K, V>[mBucketCount];
		ERROR = 0;
	}

	~HashMap() {
		delete[] mBuckets;
	}

	void insert(const K& key, const V& value) {
		int index = mHash(key, mBucketCount);
		Bucket<K, V>* b = &mBuckets[index];
		while (true) {
			if (b->next == nullptr) break;
			b = b->next;
		}
		b->key = key;
		b->value = value;
		b->next = new Bucket<K, V>();
	}

	const V& get(const K& key) const {
		int index = mHash(key, mBucketCount);
		Bucket<K, V>* b = &mBuckets[index];
		while (true) {
			if (b->key == key)      return b->value;
			if (b->next == nullptr) return ERROR; // <=< fail case how to handle?
			b = b->next;
		}
	}

	void set(const K& key, const V& value) {
		int index = mHash(key, mBucketCount);
		Bucket<K, V>* b = &mBuckets[index];
		while (true) {
			if (b->key == key) {
				b->value = value;
				break;
			}
			if (b->next == nullptr) {
				insert(key, value);
				break;
			}
			b = b->next;
		}
	}

	const V& operator[](const K& key) const {
		return get(key);
	}
	V& operator[](const K& key) {
		int index = mHash(key, mBucketCount);
		Bucket<K, V>* b = &mBuckets[index];
		while (true) {
			if (b->key == key)      return b->value;
			if (b->next == nullptr) return ERROR; // <=< fail case how to handle?
			b = b->next;
		}
	}
};
