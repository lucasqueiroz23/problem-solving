use either::Either;

fn sum_mix(arr: &[Either<i32, String>]) -> i32 {
    arr.iter()
        .map(|x| match x {
            Either::Left(x) => *x,
            Either::Right(x) => x.parse::<i32>().unwrap(),
        })
        .sum()
}
