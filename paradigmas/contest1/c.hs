import Data.List

main = do
  input <- getLine
  let tomadas = [read n :: Int | n <- (words input)]
  putStrLn $ show $ (sum (sort ([n - 1 | n <- tomadas])) + 1)
