-- Calcula a sequencia de Fibonacci
fibonacci x =
    if x == 0 then 0
    else if x == 1 then 1
    else fibonacci (x-1) + fibonacci (x-2)

-- Multiplicacao de a e b por somatória
multi a b =
    if b == 1 then a
    else a + multi a (b-1)

-- Potenciação de a e b através de multiplicações
pow a b =
    if b == 1 then a
    else a * pow a (b-1)

-- Multiplicação russa
multiRussa a b = multiRussaAux a b [(a, b)]

multiRussaAux a b s =
    if a == 1 then sum [b | (a, b) <- s, a `mod` 2 /= 0]
    else multiRussaAux a' b' ((a', b') : s)
    where
        a' = a `div` 2
        b' = b * 2
