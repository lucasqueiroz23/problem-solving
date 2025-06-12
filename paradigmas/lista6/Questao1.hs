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
  | odd $ length xs = Just $ xs !! (length xs `div` 2)
  | otherwise = Just $ xs !! ((length xs `div` 2) - 1)
