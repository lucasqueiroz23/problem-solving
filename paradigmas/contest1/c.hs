import Data.List

printf = putStrLn . show

main = do
  input <- getLine
  let tomadas = [read n :: Int | n <- words input]
  printf $ sum (sort ([n - 1 | n <- tomadas])) + 1
