// Bárbara Este Fernandez - 31937039

#include <iostream>
#define MAX_LENGTH 100
using namespace std;

class No {
	private:
		No *esq, *dir;
		int valor, profEsq, profDir;
		
	public:
		No(int valor) {
			this->valor = valor;
			this->esq = this->dir = NULL;
			this->profEsq = this->profDir = 0;
		}
		
		int getValor() {
			return valor;
		}
		
		No *getEsq() {
			return esq;
		}
		
		No *getDir() {
			return dir;
		}
		
		int getProfEsq() {
			return profEsq;
		}
		
		int getProfDir() {
			return profDir;
		}
		
		void setEsq(No *no) {
			this->esq = no;
		}
		
		void setDir(No *no) {
			this->dir = no;
		}
		
		void incrementaProfEsq() {
			this->profEsq++;
		}
		
		void incrementaProfDir() {
			this->profDir++;
		}
		
		int desequilibrio() {
			return this->profDir - this->profEsq;
		}
};

class Arvore {
	private:
		No *raiz;
		No *vetorDeInsercao[MAX_LENGTH];
		int ponteiroDeInsercao;

		void insereNoVetor(No *no) {
			vetorDeInsercao[ponteiroDeInsercao] = no;
			ponteiroDeInsercao++;
		}

		No *rotacaoAEsquerda(No *no) {
			No *subarvoreDireita = no->getDir();
			no->setDir(subarvoreDireita->getEsq());
			subarvoreDireita->setEsq(no);
			return subarvoreDireita;
		}

		No *rotacaoADireita(No *no) {
			No *subarvoreEsquerda = no->getEsq();
			no->setEsq(subarvoreEsquerda->getDir());
			subarvoreEsquerda->setDir(no);
			return subarvoreEsquerda;
		}

		void insereAux(No *no, int valor) {
			if(valor <= no->getValor()) {
				if(no->getEsq() == NULL) {
					No *novo_no = new No(valor);
					no->setEsq(novo_no);
					insereNoVetor(novo_no);
					no->incrementaProfEsq();
				} else {
					no->incrementaProfEsq();
					insereAux(no->getEsq(), valor);
				}
			} else {
				if(no->getDir() == NULL) {
					No *novo_no = new No(valor);
					no->setDir(novo_no);
					insereNoVetor(novo_no);
					no->incrementaProfDir();
				} else {
					no->incrementaProfDir();
					insereAux(no->getDir(), valor);
				}
			}
		}

	public:
		Arvore() {
			raiz = NULL;
			ponteiroDeInsercao = 0;
		}
		
		No *getRaiz() {
			return this->raiz;
		}
		
		void insere(int valor) {
			if(raiz == NULL) {
				raiz = new No(valor);
				insereNoVetor(raiz);
			} else {
				insereAux(raiz, valor);
			}
		}
		
		void emOrdem(No *no) {
			if(no != NULL) {
				emOrdem(no->getEsq());
				cout << no->getValor() << endl;
				emOrdem(no->getDir());
			}
		}
		
		void mostraVetorDeInsercao() {
			int i;
			for(i = 0; i < ponteiroDeInsercao; i++) {
				cout << ("\n\n");
				cout << "[" << i << "]: No " << vetorDeInsercao[i]->getValor();
				cout << "\nProfundidade esq: " << vetorDeInsercao[i]->getProfEsq();
				cout << "\nProfundidade dir: " << vetorDeInsercao[i]->getProfDir();
				cout << "\nDesequilibro: " << vetorDeInsercao[i]->desequilibrio();
			}
		}
		
};

int main() {
	Arvore arv;
	int reproc = 0;

	do {
		cout << ("\nValor a ser inserido (-1 para sair): ");
		cin >> reproc;
		if(reproc != -1)
			arv.insere(reproc);
	} while(reproc != -1);
	cout << "\n\nArvore:\n";
	arv.emOrdem(arv.getRaiz());

	cout << "\nVetor de insercao:";
	arv.mostraVetorDeInsercao();
	
	return 0;
}
