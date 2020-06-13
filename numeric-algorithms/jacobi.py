import math
import time

# n = número de equações e incógnitas
# A = matriz A
# b = vetor b
# k = linha da matriz a ser substituida
# p = linha da matriz a substituir
def trocaEquacao(n, A, b, k, p):
  for i in range(n):
    temp = A[k][i]
    A[k][i] = A[p][i]
    A[p][i] = temp

  temp = b[k]
  b[k] = b[p]
  b[p] = temp

# n = número de equações e incógnitas
# A = matriz A
# b = vetor b
def trocaPivoSeNulo(n, A, b):
  # Verifica se existe um A[i][i] nulo
  for i in range(n):
    if(A[i][i] == 0):
      # Se há um A[i][i] nulo, então procuramos o próximo A[j][i] não nulo
      # para substituir a linha A[i] inteira.
      if(i == n-1):
          # Se i == n-1, então estamos no final de A e não temos uma próxima
          # linha para substituir a linha A[i].
          return -1
      for j in range(i+1, n):
        if(A[j][i] != 0 and j < j+1):
          trocaEquacao(n, A, b, i, j)
          return

# n = número de equações e incógnitas
# A = elementos aij (1 <= i, j <= n) da matriz A
# b = elementos bi (1 <= i <= n) do vetor b
# XO = elementos xi (1 <= i <= n) de XO = x(0)
# TOL = tolerância
# N = número máximo de iterações
def jacobi(n, A, b, XO, TOL, N):
  x = [0]*n # Lista de soluções
  k = 1
  
  troca = trocaPivoSeNulo(n, A, b)
  if(troca == -1):
    return "Nao ha solucao para o sistema linear"
  while(k <= N):
    for i in range(n):
      somatoria = 0

      for j in range(n):
        if(j != i):
          somatoria = somatoria + (A[i][j] * XO[j])

      x[i] = ((-1*somatoria) + b[i])/A[i][i]

    if(math.fabs(max(x) - max(XO)) < TOL):
      return x

    k = k+1

    for i in range(n):
      XO[i] = x[i]
  return "Numero maximo de iteracoes excedido"


start_time = time.time()

# Exemplo de execução do método jacobi():
# A = [[2, 1],[1, -2]]
# b = [2, -2]
# n = 2
# XO = [0, 0]
# TOL = 0.1
# N = 5
# xJacobi = jacobi(n, A, b, XO, TOL, N)
# print(xJacobi)

# O código deve estar antes do cálculo do tempo de execução para funcionar corretamente.
# --- Insira o código abaixo desta linha ---



print("Tempo de execucao: %f segundos" % (time.time() - start_time))