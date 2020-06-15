import classes.*;

import java.util.Locale;
import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        int menuChoice = 0;
        String input;
        Scanner s = new Scanner(System.in);
        s.useLocale(Locale.ENGLISH);

        Empresa empresa = new Empresa();

        do {
            do {
                System.out.println("\n--- MENU PRINCIPAL ---");
                System.out.println("1 - Adicionar Colaborador (Estagiario, Funcionario ou Presidente)");
                System.out.println("2 - Calcular pagamento dos Funcionarios");
                System.out.println("3 - Aumentar adicional de todos os Funcionarios");
                System.out.println("4 - Relatorio dos Colabores");
                System.out.println("5 - Sair do Programa");
                System.out.print("Escolha: ");

                input = s.nextLine();

                try {
                    menuChoice = Integer.parseInt(input);
                } catch (NumberFormatException e) {
                    System.out.println("Digite um valor de 1 a 5");
                    menuChoice = 0;
                }
            } while ((menuChoice < 1) || (menuChoice > 5));

            switch (menuChoice) {
                case 1: // Adicionar Colaborador
                    menuAdicionarColaborador(s, empresa);
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
        } while (menuChoice != 5);

        s.close();
    }

    public static void menuAdicionarColaborador(Scanner s, Empresa empresa) {
        int menuChoice = 0;

        do {
            System.out.println("\nQual o tipo de colaborador?");
            System.out.println("1 - Estagiario");
            System.out.println("2 - Funcionario");
            System.out.println("3 - Presidente ");
            System.out.print("Escolha: ");

            if (s.hasNextInt()) menuChoice = s.nextInt();
            else menuChoice = 0;

            s.nextLine();

        } while ((menuChoice < 1) || (menuChoice > 3));

        switch (menuChoice) {
            case 1: // Adicionar Estagiario
                menuAdicionarEstagiario(s, empresa);
                break;

            case 2: // Adicionar Funcionario
                menuAdicionaFuncionario(s, empresa);
                break;

            case 3: // Adicionar Presidente
            default:
                menuAdicionaPresidente(s, empresa);
                break;
        }
    }

    public static void menuAdicionarEstagiario(Scanner s, Empresa empresa) {
        String nome = "";
        int departamento = -1;
        double salario = -1;
        double valecoxinha = -1;

        String input;

        System.out.println("\n--- Adicionar Estagiario ---");
        System.out.print("Nome: ");
        nome = s.nextLine();

        do {
            System.out.print("Departamento: ");
            input = s.nextLine();
            try {
                departamento = Integer.parseInt(input);
            } catch (NumberFormatException e) {
                System.out.println("Digite um numero inteiro.");
                departamento = -1;
            }
        } while (departamento == -1);

        do {
            System.out.print("Salario (utilize ponto): ");
            input = s.nextLine();
            try {
                salario = Double.parseDouble(input);
            } catch (NumberFormatException e) {
                System.out.println("Digite um numero inteiro ou decimal com ponto.");
                salario = -1;
            }
        } while (salario == -1);

        do {
            System.out.print("Vale coxinha (utilize ponto): ");
            input = s.nextLine();
            try {
                valecoxinha = Double.parseDouble(input);
            } catch (NumberFormatException e) {
                System.out.println("Digite um numero inteiro ou decimal com ponto.");
                valecoxinha = -1;
            }
        } while (valecoxinha == -1);

        if (empresa.adicionaColaborador(nome, departamento, salario, valecoxinha) == 1) System.out.println("--- Estagiario adicionado com sucesso! ---");
        else System.out.println("--- Nao foi possivel adicionar novo Estagiario. Limite de funcionarios excedido. ---");
    }

    public static void menuAdicionaFuncionario(Scanner s, Empresa empresa) {
        String nome = "", input;
        int departamento = -1;
        double salario = -1, adicional = -1, previdencia = -1;

        System.out.println("\n---- Adicionar Funcionario ---");

        System.out.print("Nome: ");
        nome = s.nextLine();

        do {
            System.out.print("Departamento: ");
            input = s.nextLine();

            try {
                departamento = Integer.parseInt(input);
            } catch (NumberFormatException e) {
                System.out.println("Digite um numero inteiro.");
                departamento = -1;
            }
        } while (departamento == -1);

        do {
            System.out.print("Salario (utilize ponto): ");
            input = s.nextLine();
            try {
                salario = Double.parseDouble(input);
            } catch (NumberFormatException e) {
                System.out.println("Digite um numero inteiro ou decimal com ponto.");
                salario = -1;
            }
        } while (salario == -1);

        do {
            System.out.print("Adicional (utilize ponto): ");
            input = s.nextLine();
            try {
                adicional = Double.parseDouble(input);
            } catch (NumberFormatException e) {
                System.out.println("Digite um numero inteiro ou decimal com ponto.");
                adicional = -1;
            }
        } while (adicional == -1);

        do {
            System.out.print("Previdencia (utilize ponto): ");
            input = s.nextLine();
            try {
                previdencia = Double.parseDouble(input);
            } catch (NumberFormatException e) {
                System.out.println("Digite um numero inteiro ou decimal com ponto.");
                previdencia = -1;
            }
        } while (previdencia == -1);

        if (empresa.adicionaColaborador(nome, departamento, salario, adicional, previdencia) == 1) System.out.println("--- Funcionario adicionado com sucesso! ---");
        else System.out.println("--- Nao foi possivel adicionar novo Funcionario. Limite de funcionarios excedido. ---");
    }

    public static void menuAdicionaPresidente(Scanner s, Empresa empresa) {
        String nome = "", input;
        int departamento = -1;
        double salario = -1;

        System.out.println("\n---- Adicionar Presidente ---");

        System.out.print("Nome: ");
        nome = s.nextLine();

        do {
            System.out.print("Departamento: ");
            input = s.nextLine();

            try {
                departamento = Integer.parseInt(input);
            } catch (NumberFormatException e) {
                System.out.println("Digite um numero inteiro.");
                departamento = -1;
            }
        } while (departamento == -1);

        do {
            System.out.print("Salario (utilize ponto): ");
            input = s.nextLine();
            try {
                salario = Double.parseDouble(input);
            } catch (NumberFormatException e) {
                System.out.println("Digite um numero inteiro ou decimal com ponto.");
                salario = -1;
            }
        } while (salario == -1);

        if (empresa.adicionaColaborador(nome, departamento, salario) == 1) System.out.println("--- Presidente adicionado com sucesso! ---");
        else System.out.println("--- Nao foi possivel adicionar novo Presidente. Limite de funcionarios excedido. ---");
    }
}
