use rand::Rng;

fn is_valid_key(key: &str) -> bool {
    !key.is_empty() && key.chars().all(|c| c.is_ascii_lowercase())
}

fn shift_char(char: u8, shift: u8) -> char {
    let char_code = b'a' + (char + shift - b'a') % 26;
    char_code as char
}

fn unshift_char(char: u8, unshift: u8) -> char {
    let char_code = b'a' + ((26 + char - unshift - b'a') % 26) % 26;
    char_code as char
}

fn generate_key(key_len: usize) -> String {
    let mut key = String::with_capacity(key_len);

    let mut rng = rand::rng();
    for _ in 0..key_len {
        let key_char = rng.sample(rand::distr::Alphabetic).to_ascii_lowercase();
        key.push(key_char as char);
    }

    key
}

fn encode_chars(key: &str, s: &str, encode_fn: impl Fn(u8, u8) -> char) -> Option<String> {
    if !is_valid_key(key) {
        return None;
    }

    let mut encoded_s = String::with_capacity(s.len());
    let key_chars = key.as_bytes();
    let mut key_char_index = 0;

    for char in s.bytes() {
        encoded_s.push(encode_fn(char, key_chars[key_char_index] - b'a'));
        key_char_index = (key_char_index + 1) % key_chars.len();
    }

    Some(encoded_s)
}

pub fn encode(key: &str, s: &str) -> Option<String> {
    encode_chars(key, s, shift_char)
}

pub fn decode(key: &str, s: &str) -> Option<String> {
    encode_chars(key, s, unshift_char)
}

pub fn encode_random(s: &str) -> (String, String) {
    let key = generate_key(100);

    (key.clone(), encode(&key, s).unwrap())
}
