atendidos :: Int -> Int -> [Int] -> Char
atendidos p m xs
  | expected odd p && expected even m = 'S'
  | otherwise = 'N'
  where
    expected criteria n = length (filter criteria xs) == n

main = do
  n <- getLine
  tsinput <- getLine
  let ts = [read t :: Int | t <- words tsinput]

  pinput <- getLine
  let p = read pinput :: Int

  minput <- getLine
  let m = read minput :: Int

  putChar $ atendidos p m ts
  putChar '\n'
