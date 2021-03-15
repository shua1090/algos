#pragma once

#include <string>

struct Bucket {
	std::string key;
	int value;
	Bucket* next;
	Bucket();
	Bucket(const std::string& key, int value);
	~Bucket();
};

class HashMap {
private:
	int mBucketCount;
	Bucket* mBuckets;
	
	int hash(const std::string& key) const;

public:
	HashMap();
	HashMap(int bucketCount);
	~HashMap();
	void put(const std::string& key, int value);
	const int& get(const std::string& key) const;
	inline const int& operator[](const std::string& key) const {
		return get(key);
	}
};

