module LeapYear (isLeapYear) where

isLeapYear :: Integer -> Bool

dividesFour n = rem n 4 == 0

dividesHundred n = rem n 100 == 0

dividesFourHundred n = rem n 400 == 0

isLeapYear year = (not (dividesHundred year) && dividesFour year) || (dividesHundred year && dividesFourHundred year)
