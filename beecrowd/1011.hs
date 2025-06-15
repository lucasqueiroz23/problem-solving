import Text.Printf

getVolume :: Int -> Double
getVolume radius = 4 / 3 * pi * (fromIntegral radius ** 3)
  where
    pi = 3.14159

main = do
  r <- getLine
  let radius = read r :: Int
  printf "VOLUME = %.3f\n" $ getVolume radius
