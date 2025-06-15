import Text.Printf

getRate :: Int -> Double -> Double
getRate a b = (fromIntegral a) / b

main = do
  input1 <- getLine
  input2 <- getLine

  let a = read input1 :: Int
  let b = read input2 :: Double

  printf "%.3f km/l\n" $ getRate a b
