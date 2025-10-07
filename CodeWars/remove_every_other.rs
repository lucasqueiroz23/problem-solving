fn remove_every_other(arr: &[u8]) -> Vec<u8> {
    let mut newVec: Vec<u8> = vec![];
    let mut i = 0;

    while i < arr.len() {
        newVec.push(arr[i]);
        i += 2;
    }

    newVec
}
