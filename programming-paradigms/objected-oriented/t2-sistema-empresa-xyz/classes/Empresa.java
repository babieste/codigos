package classes;

public class Empresa {
    private int quantidadeColaboradores = 0;
    private BaseColaborador[] colaboradores;

    /**
     * Cria uma nova instancia de Empresa, com um vetor para ate 100 colaboradores.
     */
    public Empresa() {
        this.colaboradores = new BaseColaborador[100];
    }

    /**
     *
     * @param nome
     * @param departamento
     * @param salario
     * @return
     */
    public int adicionaColaborador(String nome, int departamento, double salario) {
        if ((this.quantidadeColaboradores + 1) <= 100) {
            this.quantidadeColaboradores += 1;
            this.colaboradores[this.quantidadeColaboradores-1] = new Presidente(nome, departamento, salario);
            return 1;
        }
        return 0;
    }

    /**
     *
     * @param nome
     * @param departamento
     * @param salario
     * @param valecoxinha
     * @return
     */
    public int adicionaColaborador(String nome, int departamento, double salario, double valecoxinha) {
        if ((this.quantidadeColaboradores + 1) <= 100) {
            this.quantidadeColaboradores += 1;
            this.colaboradores[this.quantidadeColaboradores-1] = new Estagiario(nome, departamento, salario, valecoxinha);
            return 1;
        }
        return 0;
    }

    /**
     *
     * @param nome
     * @param departamento
     * @param salario
     * @param adicional
     * @param previdencia
     * @return
     */
    public int adicionaColaborador(String nome, int departamento, double salario, double adicional, double previdencia) {
        if ((this.quantidadeColaboradores + 1) <= 100) {
            this.quantidadeColaboradores += 1;
            this.colaboradores[this.quantidadeColaboradores-1] = new Funcionario(nome, departamento, salario, adicional, previdencia);
            return 1;
        }
        return 0;
    }

    /**
     * Aumenta o adicional dos colaboradores da empresa que tem direito a adicional (Funcionarios e Presidentes).
     * @param novo_percentual
     */
    public void aumentaAdicional(double novo_percentual) {
        int i;
        for (i = 1; i <= this.quantidadeColaboradores; i++) {
            if (this.colaboradores[i-1] instanceof Funcionario) {
                ((Funcionario) this.colaboradores[i-1]).setAdicional(novo_percentual);
            }
        }
    }

    /**
     * Faz o relatorio de todos os colaboradores da Empresa.
     * Imprime um colaborador por linha.
     */
    public void relatorio() {
        int i;
        if (this.quantidadeColaboradores == 0) System.out.println("Nao ha colaboradores!");
        else {
            for (i = 1; i <= this.quantidadeColaboradores; i++) {
                System.out.println(this.colaboradores[i-1]);
            }
        }
    }

    /**
     * Calcula o pagamento de todos os Colaboradores da Empresa.
     */
    public double calcularPagamento(int idColaborador) {
        if (this.colaboradores[idColaborador] instanceof Estagiario) return ((Estagiario) this.colaboradores[idColaborador]).getPagamento();
        else return ((Funcionario) this.colaboradores[idColaborador]).getPagamento();
    }

    /**
     * Retorna a quantidade de colaboradores na Empresa.
     */
    public int quantidadeColaboradores() {
        return this.quantidadeColaboradores;
    }

    public int quantidadeFuncionarios() {
        int i, quantidade = 0;
        for (i = 1; i <= this.quantidadeColaboradores; i++) {
            if (this.colaboradores[i-1] instanceof Funcionario)
                quantidade++;
        }

        return quantidade;
    }
}
