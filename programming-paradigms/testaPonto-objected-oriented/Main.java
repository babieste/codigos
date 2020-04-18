//Bárbara Este Fernandez - 31937039
import br.com.barbara.*;

class Main {
  public static void main(String[] args) {
    Ponto p1 = new Ponto(0,0);
    Ponto p2 = new Ponto(1,0);
    Ponto p3 = new Ponto(3, 4);
    Ponto p4 = new Ponto(5, 5);
    Ponto3D p5 = new Ponto3D(1, 2, 3);
    Ponto3D p6 = new Ponto3D(4, 5, 6);
    Circunferencia circ = new Circunferencia(p1, 1);
    ListaPonto lp = new ListaPonto(10);

    if(circ.calcula(p2)) {
        System.out.println("O ponto "+ p2 +" pertence a circunferencia de raio "+circ.getRaio()+" e centro "+ circ.getCentro()+".");
    } else {
        System.out.println("O ponto "+ p2 +" nao pertence a circunferencia de raio "+circ.getRaio()+" e centro "+ circ.getCentro()+".");
    }

    if(p1.equals(p2)) {
        System.out.println("Os pontos "+p1+" e "+p2+" sao iguais.");
    } else {
        System.out.println("Os pontos "+p1+" e "+p2+" nao sao iguais.");
    }

    System.out.println("Distancia entre "+ p1 +" e "+ p2 +": "+ p1.distancia(p2) +".");
    
    System.out.println("Distancia entre "+ p5 +" e "+ p6 +": "+ p5.distancia(p6) +".");

    if(p5.equals(p6)) {
        System.out.println("Os pontos "+ p5 +" e "+ p6 +" sao iguais.");
    } else {
        System.out.println("Os pontos "+ p5 +" e "+ p6 +" nao sao iguais.");
    }

    lp.adiciona(p1);
    lp.adiciona(p2);
    lp.adiciona(p3, 5);
    lp.adiciona(p4, 0);

    System.out.println("Lista de pontos: "+ lp +".");
    System.out.println("Quantidade de pontos na lista: "+ lp.quantidade() +".");

    System.out.println("Busca "+ p1 +": "+ lp.busca(p1) +".");
    System.out.println("Busca "+ p4 +": "+ lp.busca(p4) +".");

    System.out.println("Remocao do ponto no indice 0: "+ lp.remove(0) +".");
    System.out.println("Lista apos remocao: "+ lp +".");
  }

 
}