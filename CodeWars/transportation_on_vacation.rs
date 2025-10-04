fn get_discount(d: u32) -> u32 {
    if d >= 3 && d < 7 {
        return 20;
    } else if d >= 7 {
        return 50;
    }

    return 0;
}

fn rental_car_cost(d: u32) -> u32 {
    return 40 * d - get_discount(d);
}
