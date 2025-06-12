preco :: Int -> Int
preco x
  | x <= 17 = 15
  | x > 17 && x < 60 = 30
  | otherwise = 20

main = do
  idadeA <- getLine
  idadeB <- getLine

  let a = read idadeA :: Int
  let b = read idadeB :: Int

  putStrLn $ show $ preco a + preco b
