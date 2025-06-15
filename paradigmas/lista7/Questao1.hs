module Questao1 where

import Data.Char

count :: String -> Int
count = length . filter isLower . map head . map reverse . words

inverses :: [Int] -> [Double]
inverses = map (\x -> 1 / fromIntegral x) . filter (/= 0)

odds :: Int -> Int
odds = length . filter (odd . digitToInt) . show

palindromes :: String -> Int
palindromes = length . filter (\w -> w == reverse w) . words

isOctNumber :: Int -> Bool
isOctNumber = foldr (&&) True . map (<= 7) . map digitToInt . show
