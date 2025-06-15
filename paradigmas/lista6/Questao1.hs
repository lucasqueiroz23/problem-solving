module Questao1 where

second :: [a] -> Maybe a
second xs
  | length xs < 2 = Nothing
  | otherwise = Just $ head . tail $ take 2 xs

body :: [a] -> Maybe [a]
body xs
  | length xs < 3 = Nothing
  | otherwise = Just $ take (len xs) (tail xs)
  where
    len arr = length arr - 2

median :: [a] -> Maybe a
median xs
  | null xs = Nothing
  | even (length xs) = Just $ xs !! ((length xs `div` 2) - 1)
  | otherwise = Just $ xs !! (length xs `div` 2)
