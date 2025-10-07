fn summation(n: i32) -> i32 {
    (1..=n).collect::<Vec<i32>>().iter().fold(0, |acc, x| acc + x)
}
