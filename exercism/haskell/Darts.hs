module Darts (score) where

score x y
  | distance >= 0 && distance <= 1 = 10
  | distance > 1 && distance <= 5 = 5
  | distance > 5 && distance <= 10 = 1
  | otherwise = 0
  where
    distance = sqrt (x ^ 2 + y ^ 2)
