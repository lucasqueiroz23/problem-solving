import Data.List

idadeCamilaSorted :: [Int] -> Int
idadeCamilaSorted (_ : x : _) = x

main = do
  x <- getLine
  y <- getLine
  z <- getLine

  let idades = [read x :: Int, read y :: Int, read z :: Int]

  putStrLn $ show $ idadeCamilaSorted $ sort idades
