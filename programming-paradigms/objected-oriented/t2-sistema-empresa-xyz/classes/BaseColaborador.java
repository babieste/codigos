package classes;

public class BaseColaborador {
    private static int iterator = 0;
    private int ID;
    private String nome;
    private int departamento;
    private double salario;

    /**
     * Base para a criacao de um colaborador da empresa
     * @param nome
     * @param departamento
     * @param salario
     */
    public BaseColaborador(String nome, int departamento, double salario) {
        iterator = iterator + 1;
        this.ID = iterator;
        this.nome = nome;
        this.departamento = departamento;
        this.salario = salario;
    }

    public int getID() {
        return this.ID;
    }

    public String getNome() {
        return this.nome;
    }

    public int getDepartamento() {
        return this.departamento;
    }

    public double getSalario() {
        return this.salario;
    }
}
