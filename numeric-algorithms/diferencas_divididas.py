# n = tamanho da entrada
# x = vetor de x
# F = matriz com f(x) na primeira coluna
def diferencasDivididas(n, x, F):
    for i in range(1, n):
        for j in range(1, i+1):
            F[i][j] = (F[i][j-1] - F[i-1][j-1])/(x[i] - x[i-j])

# px = valor de x para ser encontrado p(x)
# n = tamanho da entrada
# x = vetor de x
# F = matriz de diferencas divididas
def polinomioDiferencasDivididas(px, n, x, F):
    somatoria = 0

    for i in range (1, n):
        multiplicatoria = 1

        for j in range(0, i):
            multiplicatoria *= (px - x[j])
        
        somatoria += F[i][i]*multiplicatoria

    return F[0][0] + somatoria

n = 6
x = [ -2, -1, 0, 1, 2, 3]
F = [[1, 0, 0, 0, 0, 0],
    [4, 0, 0, 0, 0, 0],
    [11, 0, 0, 0, 0, 0],
    [16, 0, 0, 0, 0, 0],
    [13, 0, 0, 0, 0, 0],
    [-4, 0, 0, 0, 0, 0]]

diferencasDivididas(n, x, F)

for i in range(0, n):
    print('F[' + str(i) + '][' + str(i) + '] = ' + str(F[i][i]))

p0 = polinomioDiferencasDivididas(0, 6, x, F)
p1 = polinomioDiferencasDivididas(1, 6, x, F)

print('P6(0) = ' + str(p0))
print('P6(1) = ' + str(p1))