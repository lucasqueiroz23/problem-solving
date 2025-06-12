switchState :: Int -> Int
switchState n = abs (n - 1)

nextState :: (Int, Int) -> Int -> (Int, Int)
nextState st d
  | d == 1 = (switchState $ fst st, snd st)
  | otherwise = (switchState $ fst st, switchState $ snd st)

getState :: [Int] -> (Int, Int) -> (Int, Int)
getState xs st
  | null xs = st
  | otherwise = getState (drop 1 xs) (nextState st (head xs))

main = do
  _ <- getLine
  input <- getLine
  let xs = [read x :: Int | x <- words input]
  let initialState = (0, 0)

  let finalState = getState xs initialState
  putStrLn $ show $ fst finalState
  putStrLn $ show $ snd finalState
