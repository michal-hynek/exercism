/// Return the Hamming distance between the strings,
/// or None if the lengths are mismatched.
pub fn hamming_distance(s1: &str, s2: &str) -> Option<usize> {
    if s1.len() != s2.len() {
        return None;
    }

    let s1 = s1.as_bytes();
    let s2 = s2.as_bytes();

    let mut diff = 0;
    for i in 0..s1.len() {
        if s1[i] != s2[i] {
            diff += 1;
        }
    }

    Some(diff)
}
