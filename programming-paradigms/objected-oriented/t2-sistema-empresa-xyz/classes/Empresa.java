package classes;

public class Empresa {
    private int quantidadeFuncionarios = 2;
    private BaseColaborador[] funcionarios;

    public Empresa() {
        this.funcionarios = new BaseColaborador[100];
        this.funcionarios[0] = new Estagiario("Barbara", 1, 1000, 4.50);
        this.funcionarios[1] = new Presidente("Mulher mainframe", 0, 32.600);
    }

    /**
     * Aumenta o adicional dos funcionarios da empresa.
     * @param novo_percentual
     */
    public void aumentaAdicional(double novo_percentual) {
        int i;
        for (i = 0; i < this.quantidadeFuncionarios; i++) {
            if (this.funcionarios[i] instanceof Funcionario) {
                ((Funcionario) this.funcionarios[i]).setAdicional(novo_percentual);
            }
        }
    }

    /**
     * Relatorio de todos os colaboradores da Empresa
     */
    public void relatorio() {
        int i;
        for (i = 0; i < this.quantidadeFuncionarios; i++) {
            System.out.println(this.funcionarios[i]);
        }
    }
}
