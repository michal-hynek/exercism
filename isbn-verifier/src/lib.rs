/// Determines whether the supplied string is a valid ISBN number
pub fn is_valid_isbn(isbn: &str) -> bool {
    if isbn.chars().any(|c| !c.is_ascii_digit() && c != '-' && c != 'X') {
        return false;
    }

    if let Some(x_pos) = isbn.chars().position(|c| c == 'X') {
        if x_pos != isbn.len() - 1 {
            return false;
        }
    }

    let digits = isbn.bytes()
        .filter(|c| c.is_ascii_digit() || *c == b'X')
        .map(|c| {
            if c == b'X' {
                10u8
            } else {
                c - b'0'
            }
        })
        .collect::<Vec<_>>();

    if digits.len() != 10 {
        return false;
    }

    let sum = digits.into_iter()
        .zip((1u8..=10).rev())
        .map(|(x,y)| (x as u32)*(y as u32))
        .sum::<u32>();

    sum % 11 == 0
}
