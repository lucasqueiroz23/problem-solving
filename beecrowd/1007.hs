diferenca a b c d = (a * b) - (c * d)

main = do
  inputA <- getLine
  let a = read inputA :: Int
  inputB <- getLine
  let b = read inputB :: Int
  inputC <- getLine
  let c = read inputC :: Int
  inputD <- getLine
  let d = read inputD :: Int

  putStrLn $ "DIFERENCA = " ++ show (diferenca a b c d)
