import classes.*;

class Main {
    public static void main(String[] args) {
        Empresa empresa = new Empresa();

        empresa.relatorio();
        empresa.aumentaAdicional(2.1);
        empresa.relatorio();
    }
}
