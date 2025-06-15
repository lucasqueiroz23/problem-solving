import Data.List

main = do
  input <- getLine
  let nums = [read x :: Int | x <- words input]
  putStrLn $ show (last $ sort nums) ++ " eh o maior"
