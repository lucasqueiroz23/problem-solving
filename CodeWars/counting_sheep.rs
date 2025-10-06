fn count_sheep(sheep: &[bool]) -> u8 {
    sheep
        .iter()
        .fold(0, |acc, s| if *s { acc + 1 } else { acc })
}
