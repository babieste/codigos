package classes;

public class Presidente extends Funcionario {
    private double adicional_whisky = 0.9, adicional_helicoptero = 0.7;

    /**
     * Construtor para Presidente
     * @param nome
     * @param departamento
     * @param salario
     */
    public Presidente( String nome, int departamento, double salario) {
        super(nome, departamento, salario, 3.8);
        this.adicional_whisky = 0.9;
        this.adicional_helicoptero = 0.7;
    }

    @Override
    public String toString() {
        return "Presidente: "+ this.getNome() + ", ID: "+ this.getID() + ", departamento: " + this.getDepartamento() + ", salario: " + this.getSalario() + ", previdencia: " + this.getPrevidencia() + ", adicional: " + this.getAdicional() + ", adicional_helicoptero: " + this.adicional_helicoptero + ", adicional_whisky: " + this.adicional_whisky;
    }

    public void setAdicional(double novo_percentual) {
        this.adicional_whisky = 0.9 * (1 + novo_percentual);
        this.adicional_helicoptero = 0.7 * (1 + novo_percentual);
        super.setAdicional(novo_percentual);
    }

    public double getPagamento() {
        return this.getSalario() * ((1 - this.getPrevidencia()) + this.getAdicional() + this.adicional_whisky + this.adicional_helicoptero);
    }
}