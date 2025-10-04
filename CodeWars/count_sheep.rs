fn count_sheep(n: u32) -> String {
    (1..=n).map(|x| format!("{x} sheep...")).collect::<String>()
}
