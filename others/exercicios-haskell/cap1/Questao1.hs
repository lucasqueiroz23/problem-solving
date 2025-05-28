module Questao1 where

main = do
  print [11 ^ x | x <- [0 .. 6]]
  print [y | y <- [1 .. 40], y `mod` 4 /= 0]
  print ["A" ++ [z] ++ "BB" | z <- ['a' .. 'g']]
  print [3 + x | x <- [2, 5, 8, 14, 17, 23, 26, 29, 35, 38]] -- esse aqui foi gambiarra
  print [1 / (2 ^ x) | x <- [0 .. 5]]
  print [9 * x + 1 | x <- [0 .. 7]]

-- g) [2,4,8,10,12,16,18,22,24,28,30]
-- h) ['@','A','C','D','E','G','J','L']
