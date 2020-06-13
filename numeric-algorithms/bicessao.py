# Bárbara Este Fernandez - 31937039
import math

# f = função
# a = começo do intervalo
# b = final do intervalo
# E = tolerância Epsilon
# N = número máximo de iterações
def bissecao(f, a, b, E, N):
    i = 0
    FA = f(a)

    while(i <= N):
        p = a + (b-a)/2
        FP = f(p)
        if(math.fabs(FP) < E):
            return p
        i = i+1
        if((FA*FP) > 0):
            a = p
            FA = FP
        else:
            b = p

    return "O metodo falhou apos "+ str(N) +" iteracoes."

def f(x):
    return x*math.cos(x) - 2*math.pow(x, 2) + 3*x - 1
a = 1.2
b = 1.3
E = 0.00001
N = 20

bss = bissecao(f, a, b, E, N)
print("x = "+ str(bss))