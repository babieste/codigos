#include <iostream>
using namespace std;

class No {
  private:
    No *esq, *dir;
    int chave;
    int qtde;

  public:
    No(int chave) {
      this->chave = chave;
      this->qtde = 1;
      this->esq = NULL;
      this->dir = NULL;
    }

    int getChave() {
      return chave;
    }
    
    int getQtde() {
    	return qtde;
	}

    No* getEsq() {
      return esq;
    }

    No* getDir() {
      return dir;
    }

    void setEsq(No *no) {
      esq = no;
    }

    void setDir(No *no) {
      dir = no;
    }
    
    void setQtde() {
    	qtde++;
	}
};

class Arvore {
  private:
    No *raiz;
    int quantidade;

  public:
    Arvore() {
      raiz = NULL;
    }

    No* getRaiz() {
      return raiz;
    }

    void insereAux(No *no, int chave) {
      // Se é menor, insere à esquerda
      if(chave == no->getChave()) no->setQtde();
      if(chave < no->getChave()) {
        if(no->getEsq() == NULL) {
          No *novo_no = new No(chave);
          no->setEsq(novo_no);
        } else {
          insereAux(no->getEsq(), chave);
        }
      }
      // Se é maior, insere à direita
      else if(chave > no->getChave()) {
        if(no->getDir() == NULL) {
          No *novo_no = new No(chave);
          no->setDir(novo_no);
        } else {
          insereAux(no->getDir(), chave);
        }
      }
    }

    void insere(int chave) {
      if(raiz == NULL) {
        raiz = new No(chave);
      } else {
        insereAux(raiz, chave);
      }
    }

    int localizaElem(int chave, No *raiz) {
      if(chave == raiz->getChave()) {
        return chave;
      }
      else if(chave < raiz->getChave()) {
        if(raiz->getEsq() != NULL) {
          No *esq = raiz->getEsq();
          localizaElem(chave, esq);
        } else {
          return -1;
        }
      } else {
        if(raiz->getDir() != NULL) {
          No *dir = raiz->getDir();
          localizaElem(chave, dir);
        } else {
          return -1;
        }
      }
    }

    void emOrdem(No *no) {
      if(no != NULL) {
        emOrdem(no->getEsq());
        cout << " " << no->getChave() << "- qtde: " << no->getQtde();
        emOrdem(no->getDir());
      }
    }

    void preOrdem(No *no) {
      if(no != NULL) {
        cout << " " << no->getChave();
        preOrdem(no->getEsq());
        preOrdem(no->getDir());
      }
    }

    void posOrdem(No *no) {
      if(no != NULL) {
        posOrdem(no->getEsq());
        posOrdem(no->getDir());
        cout << " " << no->getChave();
      }
    }

    void menorElem() {
      No *no = this->getRaiz();
      while (no->getEsq() != NULL) {
        no = no->getEsq();
      }
      cout << ("\nO menor elemento eh ") << no->getChave();
    }

    void maiorElem() {
      No *no = this->getRaiz();
      while(no->getDir() != NULL) {
        no = no->getDir();
      }
      cout << ("\nO maior elemento eh ") << no->getChave();
    }
    
    int count(No *no) {
    	if(no != NULL) return 1 + count(no->getEsq()) + count(no->getDir());
    	return 0;
	}
};

int main() {
  Arvore arv;
  int reproc = 1, chave;
  
  do {
    do {
      cout << ("chave a inserir (-1 para sair) = ");
      cin >> chave;
      
      if(chave != -1)
      	arv.insere(chave);
    } while (chave != -1);

    cout << "\nMostrando em ordem:";
    arv.emOrdem(arv.getRaiz());

    arv.menorElem();
    arv.maiorElem();
    cout << "\nA arvore possui " << arv.count(arv.getRaiz()) << "elementos";
    

    cout << ("\nExecutar novamente 1/0? ");
    cin >> reproc;
  } while (reproc == 1);
}
