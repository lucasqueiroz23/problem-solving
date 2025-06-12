module Questao1 where

import Data.Char

count :: String -> Int
count phrase = sum [if isLower $ last x then 1 else 0 | x <- words phrase]

inverses :: [Int] -> [Double]
inverses xs = [1 / fromIntegral x | x <- filter (/= 0) xs]

-- odds :: Int -> Int

palindromes :: String -> Int
palindromes phrase = sum [if x == reverse x then 1 else 0 | x <- words phrase]

-- isOctNumber :: Int -> Bool
