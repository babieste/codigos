# Entrada: n = número de equações e incógnitas, A = matriz extendida
def gauss(n, A):
  x = [0]*n # Cria lista de soluções
  n = n-1 # As listas iniciam-se em zero, portanto diminuímos o tamanho em 1
  for i in range(n, -1, -1):
    if(i == n):
      x[i] = A[n][n+1]/A[n][n]
    elif(i == n-1):
      x[i] = (A[i][n+1] - A[i][n]*x[n])/A[i][i]
    else:
      somatoria = 0
      j = i+1
      for j in range(j, n + 1):
        somatoria = somatoria + (A[i][j]*x[j])
      x[i] = (A[i][n+1] - somatoria)/A[i][i]
  return x

A = [[1, -1, 2, -1, -8], [0, 2, -1, 1, 6], [0, 0, -1, -1, -4], [0, 0, 0, 2, 4]]
xA = gauss(4, A)
print(xA)