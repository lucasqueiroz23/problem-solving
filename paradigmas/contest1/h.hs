atendidos :: Int -> Int -> [Int] -> Char
atendidos p m xs
  | expected odd p && expected even m = 'S'
  | otherwise = 'N'
  where
    expected func n = length (filter func xs) == n

main = do
  n <- getLine
  tsinput <- getLine
  let ts = [read t :: Int | t <- words tsinput]

  pinput <- getLine
  let p = read pinput :: Int

  minput <- getLine
  let m = read minput :: Int

  putStrLn $ [atendidos p m ts]
