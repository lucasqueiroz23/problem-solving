duplo n = ((n + 1) * (n + 2)) `div` 2

main = do
  input <- getLine
  let n = (read input :: Int)
  putStrLn $ (show . duplo) n
