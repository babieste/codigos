package classes;

public class Empresa {
    private int quantidadeColaboradores = 0;
    private BaseColaborador[] colaboradores;

    public Empresa() {
        this.colaboradores = new BaseColaborador[100];
    }

    public int adicionaColaborador(String nome, int departamento, double salario) {
        if ((this.quantidadeColaboradores + 1) <= 100) {
            this.quantidadeColaboradores += 1;
            this.colaboradores[this.quantidadeColaboradores] = new Presidente(nome, departamento, salario);
            return 1;
        }
        return 0;
    }

    public int adicionaColaborador(String nome, int departamento, double salario, double valecoxinha) {
        if ((this.quantidadeColaboradores + 1) <= 100) {
            this.quantidadeColaboradores += 1;
            this.colaboradores[this.quantidadeColaboradores] = new Estagiario(nome, departamento, salario, valecoxinha);
            return 1;
        }
        return 0;
    }

    public int adicionaColaborador(String nome, int departamento, double salario, double adicional, double previdencia) {
        if ((this.quantidadeColaboradores + 1) <= 100) {
            this.quantidadeColaboradores += 1;
            this.colaboradores[this.quantidadeColaboradores] = new Funcionario(nome, departamento, salario, adicional, previdencia);
            return 1;
        }
        return 0;
    }

    /**
     * Aumenta o adicional dos colaboradores da empresa.
     * @param novo_percentual
     */
    public void aumentaAdicional(double novo_percentual) {
        int i;
        for (i = 0; i <= this.quantidadeColaboradores; i++) {
            if (this.colaboradores[i-1] instanceof Funcionario) {
                ((Funcionario) this.colaboradores[i-1]).setAdicional(novo_percentual);
            }
        }
    }

    /**
     * Relatorio de todos os colaboradores da Empresa
     */
    public void relatorio() {
        int i;
        if (this.quantidadeColaboradores == 0) System.out.println("Nao ha colaboradores!");
        else {
            for (i = 0; i <= this.quantidadeColaboradores; i++) {
                System.out.println(this.colaboradores[i-1]);
            }
        }
    }
}
