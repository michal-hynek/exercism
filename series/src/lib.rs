pub fn series(digits: &str, len: usize) -> Vec<String> {
    if digits.len() < len {
        return Vec::new();
    }

    let mut nums = Vec::new(); 

    for start in 0..=(digits.len()-len) {
        nums.push(digits[start..start+len].to_owned());
    }

    nums
}
