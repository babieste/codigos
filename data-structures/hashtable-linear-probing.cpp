#include <iostream>
#include <math.h>
#define MAX_LENGTH 100
using namespace std;

class HashTable {
	private:
		int hash_size;
		double hash_table[];
		int key(double value) {
			return round(fmod(value, this->hash_size));
		}

	public:
		HashTable(int size) {
			int i;
			this->hash_size = size;
			for (i = 0; i < size; i++) {
				this->hash_table[i] = -1;
			}
		}
		
		int insert(double value) {
			int probe;
			int key = this->key(value);

			printf("\nCalculated key for %.2f is %d", value, key);

			if (key > this->hash_size) {
				printf("\nKey %d is not within hash_table size!", key);
				return 0;
			} else {
				if (this->hash_table[key] == -1) {
					printf("\nInserting %.2f in hash_table[%d]!", value, key);
					this->hash_table[key] = value;
					return 1;
				} else {
					// If hash_table[key] is not empty, then linear probing is applied
					// For this, firstly verify if key is the last index of the hash_table,
					// otherwise the hash_table needs to be verified since its beginning
					printf("\nhash_table[%d] is occupied! Applying linear probing...");
					if (key == (this->hash_size-1)) {
						probe = 0;
					} else {
						probe = key + 1;
					}
					
					while ((probe != -1) || (probe != key)) {
						printf("\nTrying hash_table[%d]...", probe);
						printf("\t hash_table[%d] = %.2f", probe, this->hash_table[probe]);
						if (this->hash_table[probe] == -1) {
							printf("\t Successfull! Value %f inserted in hash_table[%d]", value, probe);
							this->hash_table[probe] = value;
							return 1;
						} else {
							printf("\t Not successfull! Applying linear probing again...");
							if (probe == (this->hash_size-1)) {
								probe = 0;
							} else {
								probe++;
							}
						}
					}
					
					printf("\nCouldn\'t find available key to insert value.");
					return 0;
				}
			}
		}
};

int main() {
	HashTable ht(13);
	double values[4] = {12, 14.5, 12, 32.7};
	int i;
	
	for(i = 0; i < 4; i++) {
		ht.insert(values[i]);
	}

}
