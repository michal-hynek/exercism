pub fn reverse(input: &str) -> String {
    if input.is_empty() {
        return input.to_string();
    }

    let chars = input.as_bytes();
    let mut reversed_chars: Vec<u8> = vec![0; input.len()];
    let mut left = 0;
    let mut right = input.len()-1;

    while left < right {
        reversed_chars[left] = chars[right];
        reversed_chars[right] = chars[left];

        left += 1;
        right -=1;
    }

    String::from_utf8_lossy(chars).to_string()
}
