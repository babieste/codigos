-- Verifica se os 3 valores por input foram um triangulo de Pitagoras ou nao
verifyPitagoras a b c =
    if a^2 + b^2 == c^2 || a^2 + c^2 == b^2 || b^2 + c^2 == a^2
    then "Eh uma tripla de Pitagoras"
    else "Nao eh uma tripla de Pitagoras"

fn1 x y = x + y

fn2 x = x^2

-- Multiplicação russa
multiRussa a b = multiRussaAux a b [(a, b)]

-- Soma os valores de b da tupla (a, b) em que a é ímpar
multiRussaSoma a b s = sum [b | (a, b) <- s, mod a 2 /= 0]

multiRussaAux a b s =
    if a == 1
    then multiRussaSoma a b s
    else multiRussaAux a' b' ((a', b') : s)
    where
        a' = a `div` 2
        b' = b * 2
-- Fim Multiplicação Russa

-- Retorna a duracao de um jogo dada a hora inicial e de termino
duracaoJogo inicio fim =
    if fim > inicio then fim - inicio
    else 24 - (inicio - fim)

-- Retorna a quantidade de pares dentro de uma lista
contadorPares [] = 0 -- Condição de parada: quando a lista for vazia, retornamos 0
contadorPares (elemento:restoLista) =
    if mod elemento 2 == 0 then 1 + contadorPares restoLista
    else 0 + contadorPares restoLista

-- Retorna uma nova lista dos elementos pertencentes a lista que são menores ou iguais a m
elementosMenores lista m = [x | x <- lista, x <= m]
