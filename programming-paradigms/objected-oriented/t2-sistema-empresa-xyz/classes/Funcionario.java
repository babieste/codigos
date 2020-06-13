package classes;

public class Funcionario extends BaseColaborador {
    private double previdencia = 0.05, adicional;

    public Funcionario(String nome, int departamento, double salario, double adicional) {
        super(nome, departamento, salario);
        this.adicional = adicional;
    }

    @Override
    public String toString() {
        return "Funcionario: " + this.getNome() + ", ID: " + this.getID() + ", departamento: " + this.getDepartamento() + ", salario: " + this.getSalario() + ", previdencia: "+ this.previdencia + ", adicional: " + this.getAdicional();
    }

    public void setAdicional(double novo_percentual) {
        this.adicional = this.adicional * (1 + novo_percentual);
    }

    public double getAdicional() {
        return this.adicional;
    }

    public double getPrevidencia() {
        return this.previdencia;
    }

    public double getPagamento() {
        return this.getSalario() * ((1 - this.previdencia) + this.adicional);
    }
}
