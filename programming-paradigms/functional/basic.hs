-- Return if a integer is even
isEven x = mod x 2 == 0

-- Return if a integer is odd
isOdd x = not (mod x 2 == 0)

-- Returns the absolute diference between n and 21, or double of n if it is bigger than 21
fn n
    | n <= 21 = mod n 21
    | otherwise = n * 2

-- Returns the triangle type if input is a valid triangle, or "Nao e triangulo" otherwise
verifyTriangle a b c = if abs (b-c) < a && a < b+c && abs (a-c) < b && b < a+c && abs (a-b) < c && c < a+b then verifyTriangleAux a b c else "nao e triangulo"

verifyTriangleAux a b c
    | a == b && a == c && b == c = "Equilatero"
    | a /= b && a /= c && b /= c = "Escaleno"
    | otherwise = "Isosceles"

-- Verifica se os 3 valores por input foram um triangulo de Pitagoras ou nao
verifyPitagoras a b c = if a^2 + b^2 == c^2 || a^2 + c^2 == b^2 || b^2 + c^2 == a^2 then "Eh uma tripla de Pitagoras" else "Nao eh uma tripla de Pitagoras"
