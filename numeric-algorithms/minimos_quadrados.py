import math

# m = numero de pontos
# x = valores de x
# y = valores de y
def mmq(m, x, y):
    Ex = 0 # somatoria de x
    Ey = 0 # somatoria de y
    Exy = 0 # somatoria de x*y
    Ex2 = 0 # somatoria de x^2

    a = [None, None] # valores a0 e a1

    for i in range(0, m):
        Ex += x[i]
        Ey += y[i]
        Exy += (x[i] * y[i])
        Ex2 += math.pow(x[i], 2)

    a[0] = ((Ex2 * Ey) - (Exy * Ex)) / ((m * Ex2) - math.pow(Ex, 2))

    a[1] = ((m * Exy) - (Ex * Ey)) / ((m * Ex2) - math.pow(Ex, 2))

    return a

# ----- EXEMPLO DE APLICACAO -----
# m = 6
# x = [1.0, 1.1, 1.3, 1.5, 1.9, 2.1]
# y = [1.84, 1.96, 2.21, 2.45, 2.94, 3.18]

# a = mmq(m, x, y)

# print('P(x) = (' + str(a[1]) + ')x + (' + str(a[0]) + ')')