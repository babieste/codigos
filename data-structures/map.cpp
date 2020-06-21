#include <iostream>
#include <string.h>
#define MAX_LENGTH 100

using namespace std;

struct Carro {
	char modelo[MAX_LENGTH], cor[MAX_LENGTH];
	int ano;
};

struct MapItem {
	char key[MAX_LENGTH];
	Carro value;
	MapItem *next;
};

class Map {
	private:
		MapItem *first;
		
	public:
		Map(MapItem newItem) {
			this->first = &newItem;
			this->first->next = NULL;
		}
		
		void printMap() {
			MapItem *current = this->first;
			while (current != NULL) {
				cout << ("\n[CHAVE] Placa: ") << current->key;
				cout << ("\n\tModelo: ") << current->value.modelo;
				cout << ("\n\tCor: ") << current->value.cor;
				cout << ("\n\tAno: ") << current->value.ano;
				
				current = current->next;
			}
		}
		
		MapItem *search(char searchValue[]) {
			MapItem *current = this->first;
			while (current != NULL) {
				if (strcmp(current->key, searchValue) == 0) {
					return current;
				} else {
					current = current->next;
				}
			}
			return NULL;
		}

		int insert(MapItem newItem) {
			MapItem *current = this->first;
			
			if (current == NULL) {
				current = &newItem;
				current->next = NULL;
				return 1;
			} else {
				while (current != NULL) {
					if (strcmp(current->key, newItem.key) == 0) {
						cout << ("\nCarro com placa \"") << newItem.key << ("\" ja existe!");
						return 0;
					}
					current = current->next;
				}

			current = &newItem;
			current->next = NULL;
			return 1;
			}
		}
};

int main () {
	
	char searchValue[MAX_LENGTH] = "ABC1010";
	MapItem mp1, mp2;
	Carro c;
	
	strcpy(c.modelo, "Sedan");
	strcpy(c.cor, "Cinza");
	c.ano = 1990;

 	strcpy(mp1.key, "ABC1010");
 	mp1.value = c;

	Map m(mp1);
	
	strcpy(mp2.key, "DEF2020");
	mp2.value = c;
	m.insert(mp2);
	
	m.printMap();

	MapItem *search = m.search(searchValue);
	
	if (search != NULL) {
		cout << ("\n\nCarro encontrado!");
		cout << ("\n[CHAVE] Placa: ") << search->key;
		cout << ("\n\tModelo: ") << search->value.modelo;
		cout << ("\n\tCor: ") << search->value.cor;
		cout << ("\n\tAno: ") << search->value.ano;
//		printf("\nCarro encontrado!\nPlaca: %s\nAno: %d\nModelo: %s\nCor: %s", search->key, search->value.ano, search->value.modelo, search->value.cor);
	} else {
		printf("\nCarro nao encontrado!");
	}
	
	return 0;
}
