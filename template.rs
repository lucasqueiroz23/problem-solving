use std::io;

fn take_int() -> usize {
    let mut input: String = String::new();
    io::stdin().read_line(&mut input).unwrap();
    return input.trim().parse().unwrap();
}

fn main() {}
