package br.com.barbara;

public class Circunferencia {
    Ponto centro;
    double raio;

    public Circunferencia(Ponto centro, double raio) {
        this.centro = centro;
        this.raio = raio;
    }

    public double getRaio() {
        return this.raio;
    }

    public Ponto getCentro() {
        return this.centro;
    }

    public boolean calcula(Ponto p) {
        double raio_ao_quadrado = Math.pow(this.raio, 2);
        double eq = Math.pow((p.getX() - this.centro.getX()), 2) + Math.pow((p.getY() - this.centro.getY()), 2);

        if(raio_ao_quadrado == eq) return true;
        return false;
    }
}