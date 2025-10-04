fn string_to_number(s: &str) -> i32 {
    match s.parse() {
        Ok(num) => num,
        _ => unreachable!(),
    }
}
