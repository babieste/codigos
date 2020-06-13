package br.com.barbara;

public class Ponto {
    private int x, y;

    public Ponto(int x, int y) {
        this.x = x;
        this.y = y;
    }

    public int getX() {
        return this.x;
    }


    public int getY() {
        return this.y;
    }

    @Override
    public String toString()    {
        return "("+this.x+","+this.y+")";
    }

    public boolean equals(Ponto p) {
        if((this.x == p.x) && (this.y == p.y))
            return true;
        return false;
    }

    public double distancia(Ponto p) {
        return Math.sqrt(Math.pow((this.getX() - p.getX()), 2) + Math.pow((this.getY() - p.getY()), 2));
    }

}
