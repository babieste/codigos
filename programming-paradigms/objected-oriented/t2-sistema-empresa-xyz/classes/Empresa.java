package classes;

public class Empresa {
    private BaseColaborador[] funcionarios;

    public Empresa(int qte_max_funcionarios) {
        this.funcionarios = new BaseColaborador[qte_max_funcionarios];
    }
}
