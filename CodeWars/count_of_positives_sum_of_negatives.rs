fn count_positives_sum_negatives(input: Vec<i32>) -> Vec<i32> {
    if input.len() == 0 {
        return vec![];
    }

    let mut positives = 0;
    let mut sum_negatives = 0;

    for val in input {
        if val > 0 {
            positives += 1;
        }
        if val < 0 {
            sum_negatives += val
        }
    }

    return vec![positives, sum_negatives];
}
