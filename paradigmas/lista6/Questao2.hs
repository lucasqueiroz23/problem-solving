module Questao2 where

semifactorial :: Int -> Int
semifactorial 1 = 1
semifactorial 0 = 1
semifactorial n = n * semifactorial (n - 2)

power :: Int -> Int -> Int
power _ 0 = 1
power a n = a * power a (n - 1)

sum_of_first_n :: Int -> Int
sum_of_first_n 1 = 1
sum_of_first_n x = x + sum_of_first_n (x - 1)

sum_of_first_n_squares :: Int -> Int
sum_of_first_n_squares 1 = 1
sum_of_first_n_squares x = x * x + sum_of_first_n_squares (x - 1)
