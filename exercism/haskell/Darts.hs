module Darts (score) where

insideInnerCircle x y = a >= 0 && a <= 1 && b >= 0 && b <= 1
  where
    a = abs x
    b = abs y

insideMiddleCircle x y = a > 1 && a <= 5 && b > 1 && b <= 5
  where
    a = abs x
    b = abs y

insideOuterCircle x y = a > 5 && a <= 10 && b > 5 && b <= 10
  where
    a = abs x
    b = abs y

innerCircle x y = if insideInnerCircle x y then 10 else 0

middleCircle x y = if insideMiddleCircle x y then 5 else 0

outerCircle x y = if insideOuterCircle x y then 1 else 0

score :: Float -> Float -> Int
score x y = (innerCircle x y) + (middleCircle x y) + (outerCircle x y)
