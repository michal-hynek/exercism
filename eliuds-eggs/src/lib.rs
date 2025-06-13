pub fn egg_count(display_value: u32) -> usize {
    let binary_string = format!("{:b}", display_value);

    binary_string.bytes().filter(|digit| *digit == b'1').count()
}
