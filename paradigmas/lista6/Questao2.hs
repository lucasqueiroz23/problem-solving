module Questao2 where

parity :: Int -> Int
parity 0 = 0
parity 1 = 1
parity n = parity (n - 2)

remainder :: Int -> Int -> Int
remainder _ 0 = 0
remainder a b = if a `mod` b == 0 then 0 else 1 + remainder (a - 1) b

quotient :: Int -> Int -> Int
quotient _ _ = 0

semifactorial :: Int -> Int
semifactorial 1 = 1
semifactorial 0 = 1
semifactorial n = n * semifactorial (n - 2)

power :: Int -> Int -> Int
power _ 0 = 1
power a n = a * power a (n - 1)

sum_of_first_n :: Int -> Int
sum_of_first_n 0 = 0
sum_of_first_n n = n + sum_of_first_n (n - 1)

sum_of_first_n_squares :: Int -> Int
sum_of_first_n_squares 0 = 0
sum_of_first_n_squares n = (n * n) + sum_of_first_n_squares (n - 1)

arithmetic_progression_sum :: Int -> Int -> Int -> Int
arithmetic_progression_sum _ _ 0 = 0
arithmetic_progression_sum a r n = a + (arithmetic_progression_sum (a + r) r (n - 1))

count_vowels :: String -> Int
count_vowels [] = 0
count_vowels (x : xs) = isVowel x + count_vowels xs
  where
    isVowel y = case y of
      'a' -> 1
      'e' -> 1
      'i' -> 1
      'o' -> 1
      'u' -> 1
      _ -> 0
