fn odd_or_even(numbers: Vec<i32>) -> String {
    if numbers.iter().sum::<i32>() % 2 == 0 {
        String::from("even")
    } else {
        String::from("odd")
    }
}
