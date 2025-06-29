fn contains_non_digits(code: &str) -> bool {
    code.chars().any(|c| !c.is_ascii_digit())
}

fn strip_whitespace(code: &str) -> String {
    String::from_utf8_lossy(
        &code.bytes()
            .filter(|c| !c.is_ascii_whitespace())
            .collect::<Vec<_>>()
    ).to_string()
}

fn double_second_digits(code: &str) -> String {
    let mut code = code.to_owned();

    let digits = unsafe {
        let digits = code.as_bytes_mut();
        digits.reverse();

        for i in (1..digits.len()).step_by(2) {
            let double = if (digits[i] - b'0') * 2 >= 10 {
                (digits[i] - b'0')*2 - 9
            } else {
                (digits[i] - b'0')*2
            };

            digits[i] = b'0' + double;
        }

        digits
    };

    String::from_utf8_lossy(digits).to_string()
}

fn sum_digits(digits: &str) -> usize {
    let sum = digits.bytes()
        .map(|d| (d - b'0') as usize)
        .sum();
    
    sum
}

/// Check a Luhn checksum.
pub fn is_valid(code: &str) -> bool {
    let code = strip_whitespace(code);
    if code.len() == 1 || contains_non_digits(&code) {
        return false;
    }

    sum_digits(&double_second_digits(&code)) % 10 == 0
}
