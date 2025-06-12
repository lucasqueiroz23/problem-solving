getMonthlyQuota :: IO Int
getMonthlyQuota = do
  input <- getLine
  let retval = read input :: Int

  return retval

getRemainingMegabytes :: Int -> Int -> IO Int
getRemainingMegabytes quota 0 = return quota
getRemainingMegabytes quota meses = do 
  monthlyQuota <- getMonthlyQuota
  remainingValues <- getRemainingMegabytes quota (meses - 1)
  return $ quota - monthlyQuota + remainingValues

main = do
  quota <- getLine
  let x = read quota :: Int

  meses <- getLine
  let n = read meses :: Int

  megabytesInMonthN <- getRemainingMegabytes x n 

  putStrLn $ show $ megabytesInMonthN
