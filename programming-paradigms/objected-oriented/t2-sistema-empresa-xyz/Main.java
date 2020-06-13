import classes.*;

class Main {
    public static void main(String[] args) {
        BaseColaborador estag = new Estagiario("Barbara", 1, 1000, 4.50);
        BaseColaborador presidente = new Presidente("Mulher mainframe", 0, 32.600);
        ((Estagiario) estag).setValeCoxinha(3.5);
        System.out.println(estag);
        System.out.println(presidente);
    }
}
