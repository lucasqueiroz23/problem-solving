module Questao3 where

reversedList :: [String] -> [String]
reversedList xs = [reverse x | x <- xs]
