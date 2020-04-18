package br.com.barbara;

public class ListaPonto {
    private Ponto pontos[];
    private int qtd;
    private int tam;

    public ListaPonto(int N) {
        this.pontos = new Ponto[N];
        this.qtd = 0;
        this.tam = N;
    }

    @Override
    public String toString() {
        String s = "[";
        for(int i = 0; i < this.qtd; i++) {
            s = s + this.pontos[i];
            if(i != this.qtd-1)
                s = s + ", ";
        }
        s = s + "]";
        return s;
    }

    public void adiciona(Ponto p) {
        this.pontos[this.qtd] = p;
        this.qtd++;
    }

    public void adiciona(Ponto p, int i) {
        if(i <= this.qtd) {
            //Se não está inserindo no final do vetor, então temos que
            //deslocar todos os elementos uma posição à direita
            if(i < this.qtd) {
                for(int j = this.pontos.length-2; j >= i; j--)
                    this.pontos[j+1] = this.pontos[j];
            }
            this.pontos[i] = p;
            this.qtd++;
        } else {
            System.out.println("O ponto só pode ser adicionado no final do vetor ou em alguma posição existente.");
        }
    }

    public int busca(Ponto p) {
        for(int i = 0; i < this.pontos.length; i++) {
            if((this.pontos[i] != null) && p.equals(this.pontos[i])) return i;
        }
        return -1;
    }

    public boolean remove(int i) {
        if(this.pontos[i] == null) return false;
        else {
            // Ponto p = this.pontos[i];
            for(int j = i; j < this.pontos.length; j++) {
                this.pontos[i] = this.pontos[i+1];
            }
            this.qtd--;
            return true;
        }
    }

    public int quantidade() {
        return this.qtd;
    }
}