module SpaceAge (Planet (..), ageOn) where

data Planet
  = Mercury
  | Venus
  | Earth
  | Mars
  | Jupiter
  | Saturn
  | Uranus
  | Neptune

secondsToYears seconds = seconds / (60 * 60 * 24 * 365.25)

convert (Mercury m) seconds = 0.2408467 * secondsToYears seconds

ageOn :: Planet -> Float -> Float
ageOn planet seconds = convert planet seconds
