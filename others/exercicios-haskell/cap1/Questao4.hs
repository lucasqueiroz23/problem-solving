module Questao4 where

getOddSizes :: [String] -> [Int]
getOddSizes xs = filter odd [length x | x <- xs]
