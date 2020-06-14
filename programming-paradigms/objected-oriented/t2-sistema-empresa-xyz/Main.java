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
                menuAdicionarColaborador(s);
                break;

            case 2: // Calcular pagamento dos Funcionarios
                break;

            case 3: // Aumentar adicional dos Funcionarios
                break;

            case 4: // Relatorio
                break;

            case 5: // Sair do programa
            default:
                break;
        }

        s.close();
    }

    public static void menuAdicionarColaborador(Scanner s) {
        int menuChoice = 0;

        do {
            System.out.println("Qual o tipo de colaborador?");
            System.out.println("1 - Estagiario");
            System.out.println("2 - Funcionario");
            System.out.println("3 - Presidente ");
            System.out.print("Escolha: ");

            if (s.hasNextInt()) menuChoice = s.nextInt();
            else menuChoice = 0;
        } while ((menuChoice < 1) || (menuChoice > 3));

        switch (menuChoice) {
            case 1: // Adicionar Estagiario
                menuAdicionarEstagiario(s);
                break;

            case 2: // Adicionar Funcionario
                break;

            case 3: // Adicionar Presidente
            default:
                break;
        }
    }

    public static void menuAdicionarEstagiario(Scanner s) {
        String nome;
        int departamento;
        double salario, valecoxinha;

        if(s.hasNext()) s.nextLine();

        System.out.println("--- Adicionar Estagiario ---");
        System.out.print("Nome: ");
        nome = s.nextLine();

        System.out.print("Departamento: ");
        departamento = s.nextInt();

        System.out.print("Salario: ");
        salario = s.nextDouble();

        System.out.print("Vale coxinha: ");
        valecoxinha = s.nextDouble();

        System.out.println("Estagiario: " + nome + ", departamento: " + departamento + ", salario: " + salario + ", vale coxinha: " + valecoxinha);
    }
}
