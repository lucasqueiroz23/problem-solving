fn invert(values: &[i32]) -> Vec<i32> {
    values.iter().map(|&x| (-1) * x).collect::<Vec<i32>>()
}
