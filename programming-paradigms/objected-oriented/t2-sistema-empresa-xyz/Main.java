import classes.*;

import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        int menuChoice = 0;
        Scanner s = new Scanner(System.in);
        Empresa empresa = new Empresa();

        do {
            System.out.println("1 - Adicionar Colaborador (Estagiario, Funcionario ou Presidente)");
            System.out.println("2 - Calcular pagamento dos Funcionarios");
            System.out.println("3 - Aumentar adicional de todos os Funcionarios");
            System.out.println("4 - Relatorio dos Colabores");
            System.out.println("5 - Sair do Programa");
            System.out.print("Escolha: ");

            if (s.hasNextInt()) menuChoice = s.nextInt();
            else menuChoice = 0;

        } while ((menuChoice < 1) || (menuChoice > 5));

        switch (menuChoice) {
            case 1: // Adicionar Colaborador
                // menuAdicionarColaborador();
                break;
            case 2: // Calcular pagamento dos Funcionarios
                break;

            case 3: // Aumentar adicional dos Funcionarios
                break;

            case 4: // Relatorio
            default:
                break;
        }

        s.close();
    }
}
