use std::io;

type ll = i64;
type vi = Vec<i32>;
type ii = (i32, i32);
type vii = Vec<ii>;

fn read_int() -> usize {
    let mut input: String = String::new();
    io::stdin().read_line(&mut input).unwrap();
    return input.trim().parse().unwrap();
}

fn read_vector() -> Vec<i32> {
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    return input
        .trim()
        .split_whitespace()
        .map(|x| x.parse().unwrap())
        .collect();
}

fn main() {}
