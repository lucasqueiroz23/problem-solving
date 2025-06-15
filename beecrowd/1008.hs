import Text.Printf

getSalary :: Int -> Double -> Double
getSalary h v = fromIntegral h * v

main = do
  n <- getLine
  h <- getLine
  v <- getLine

  let number = read n :: Int
  let hours = read h :: Int
  let valuePerHour = read v :: Double
  putStrLn $ "NUMBER = " ++ show number
  printf "SALARY = U$ %.2f\n" (getSalary hours valuePerHour)
