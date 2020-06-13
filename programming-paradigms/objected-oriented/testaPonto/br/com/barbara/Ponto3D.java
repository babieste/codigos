package br.com.barbara;

public class Ponto3D extends Ponto {
    private int z;

    public Ponto3D(int x, int y, int z) {
        super(x, y);
        this.z = z;
    }

    public int getZ() {
        return this.z;
    }

    @Override
    public String toString() {
        return "("+ super.getX() +", "+ super.getY() +", "+ this.z +")";
    }

    public boolean equals(Ponto3D p) {
        if((super.getX() == p.getX()) && (super.getY() == p.getY()) && (this.z == p.getZ()))
            return true;
        return false;
    }

    public double distancia(Ponto3D p) {
        return Math.sqrt(Math.pow((this.getX() - p.getX()), 2) + Math.pow((this.getY() - p.getY()), 2) + Math.pow((this.getZ() - p.getZ()), 2));
    }
}
