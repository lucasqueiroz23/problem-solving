getValues :: Int -> Int -> Int -> IO Int
getValues _ 0 _ = return (-1)
getValues day numberOfDaysLeft numberOfAccessUntilNow = do
  x <- getLine
  let accessesToday = read x :: Int
  let accesses = accessesToday + numberOfAccessUntilNow

  otherDays <- getValues (day + 1) (numberOfDaysLeft - 1) accesses

  return $ if accesses >= 1000000 then day else otherDays

main = do
  numberOfDays <- getLine
  let n = read numberOfDays :: Int

  daysPassed <- getValues 0 n 0

  let x = if daysPassed /= (-1) then daysPassed + 1 else 0

  putStrLn $ show $ x
