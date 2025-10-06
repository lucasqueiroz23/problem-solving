fn century(year: u32) -> u32 {
    year / 100 + {
        let x = year % 100;
        if x != 0 { 1 } else { 0 }
    }
}
