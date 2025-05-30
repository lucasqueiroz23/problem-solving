module Questao1 where

second :: [a] -> Maybe a
second xs
  | length xs >= 2 = Just $ head $ drop 1 xs
  | otherwise = Nothing

body :: [a] -> Maybe [a]
body xs
  | tam > 2 = Just $ take (tam - 2) $ drop 1 xs
  | otherwise = Nothing
  where
    tam = length xs

median :: [a] -> Maybe a
median xs
  | null xs = Nothing
  | otherwise = Just $ xs !! (length xs `div` 2)

main = do
  print $ second [1, 2, 3, 4, 5]
  print $ second [1]
  print $ second [2, 1]
  print $ body [1, 2, 3, 4, 5]
  print $ body [1]
  print $ body [1, 2]
  print $ body [1, 2, 3]
  print $ median [1, 2, 3]
  print $ median [1]
  print $ median [1, 2, 3, 4]
