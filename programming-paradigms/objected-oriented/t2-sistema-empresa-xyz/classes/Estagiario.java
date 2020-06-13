package classes;

public class Estagiario extends BaseColaborador {
    private double valecoxinha;

    /**
     * Retorna um novo estagiario.
     * @param nome
     * @param departamento
     * @param salario
     * @param valecoxinha
     */
    public Estagiario(String nome, int departamento, double salario, double valecoxinha) {
        super(nome, departamento, salario);
        this.valecoxinha = valecoxinha;
    }

    @Override
    public String toString() {
        return "Estagiario: " + this.getNome() + ", ID: " + this.getID() + ", departamento: " + this.getDepartamento() + ", salario: " + this.getSalario() + ", vale_coxinha: " + this.valecoxinha;
    }

    /**
     * Atualiza o valor do vale coxinha.
     * @param valecoxinha
     */
    public void setValeCoxinha(double valecoxinha) {
        this.valecoxinha = valecoxinha;
    }

    /**
     * Retorna o pagamento do estagiario.
     * @return salario + valecoxinha
     */
    public double getPagamento() {
        return this.getSalario() + this.valecoxinha;
    }
}