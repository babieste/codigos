-- Return if a integer is even
isEven x = mod x 2 == 0

-- Return if a integer is odd
isOdd x = not (mod x 2 == 0)

-- Returns the absolute diference between n and 21, or double of n if it is bigger than 21
fn n
    | n <= 21 = mod n 21
    | otherwise = n * 2
