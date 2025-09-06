pub fn square(s: u32) -> u64 {
    if !(1..=64).contains(&s) {
        panic!("square {s} is invalid.  it has to be in the <1,64> range");
    }

    2_u64.pow(s-1)
}

pub fn total() -> u64 {
    (1..=64).map(square).sum()
}
