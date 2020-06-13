# Bárbara Este Fernandez - 31937039
import math

# f: função
# d: derivada de f
# p0: aproximação inicial de p
# epsilon: tolerância
# N: número máximo de iterações
def newton(f, d, p0, epsilon, N):
    i = 1
    while(i <= N):
        p = p0 - (f(p0)/d(p0))
        if (math.fabs(f(p)) < epsilon):
            return p, i
        i = i + 1
        p0 = p
    return "O método falhou após " + str(N) + " iterações."

# --- Exemplo de chamada para o método ---
# def f(x):
#     return math.pow(math.e, x)-(3*math.pow(x, 2))
#     # return math.pow(x, 3)+(4*math.pow(x, 2))-10

# def d(x):
#     return math.pow(math.e, x)-(6*x)
#     # return (3*math.pow(x, 2))+(8*x)

# p0 = 5
# epsilon = 0.00001
# N = 25
# resultado = newton(f, d, p0, epsilon, N)
# print(resultado)