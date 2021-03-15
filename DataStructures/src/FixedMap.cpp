#include "FixedMap.h"
#include <string>

Bucket::Bucket() 
	: value(0), next(nullptr) {}

// BUCKETS
Bucket::Bucket(const std::string& key, int value)
	: key(key), value(value), next(nullptr) {}

Bucket::~Bucket() {
	delete next;
}

// HASHMAP
HashMap::HashMap() {
	mBucketCount = 10;
	mBuckets = new Bucket[mBucketCount];
}


HashMap::HashMap(int bucketCount) {
	if (bucketCount == 0) bucketCount++;
	mBucketCount = bucketCount;
	mBuckets = new Bucket[mBucketCount];
}

void HashMap::put(const std::string& key, int value) {
	int index = hash(key);
	Bucket* b = &mBuckets[index];
	while (true) {
		if (b->next == nullptr) break;
		b = b->next;
	}
	b->key = key;
	b->value = value;
	b->next = new Bucket();
}

const int& HashMap::get(const std::string& key) const {
	int index = hash(key);
	Bucket* b = &mBuckets[index];
	while (true) {
		if (b->key == key)      return b->value;
		if (b->next == nullptr) return 0; // <=< fail case how to handle?
		b = b->next;
	}
}


HashMap::~HashMap() {
	delete[] mBuckets;
}

// PRIVATE
int HashMap::hash(const std::string& key) const {
	if (key.length() == 0) return 0;
	return static_cast<int>(key[0]) % mBucketCount;
}