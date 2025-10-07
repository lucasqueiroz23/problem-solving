fn to_alternating_case(s: &str) -> String {
    let mut new_string: String = String::new();

    for char in s.chars() {
        new_string.push(if char.is_uppercase() {
            char.to_ascii_lowercase()
        } else {
            char.to_ascii_uppercase()
        })
    }

    new_string
}
