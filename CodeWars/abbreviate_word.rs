fn abbrev_name(name: &str) -> String {
    name.split(" ")
        .collect::<Vec<&str>>() // this is not needed
        .iter() // this is only needed if above line is present
        .map(|w| w.chars().nth(0).unwrap().to_uppercase().to_string())
        .collect::<Vec<String>>()
        .join(".")
}
