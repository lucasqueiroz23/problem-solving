solve :: Int -> Int -> Int
solve e d
  | e > d = e + d
  | otherwise = 2 * (d - e)

main = do
  inputE <- getLine
  inputD <- getLine
  let e = read inputE :: Int
  let d = read inputD :: Int

  putStrLn $ show $ solve e d
