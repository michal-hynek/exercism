fn is_separator(c: char) -> bool {
    c.is_whitespace() || c == '-'
}

pub fn abbreviate(phrase: &str) -> String {
    let mut acronym = Vec::<u8>::new();

    let mut add_to_acronym = true;
    let mut prev_lowercase = false;

    for byte in phrase.as_bytes() {
        let char = *byte as char;

        if prev_lowercase && char.is_ascii_uppercase() {
            add_to_acronym = true;
        }

        if add_to_acronym && char.is_alphabetic() {
            let uppercas_byte = char.to_ascii_uppercase() as u8;
            acronym.push(uppercas_byte);
            add_to_acronym = false;
        }

        if is_separator(char) {
            add_to_acronym = true;
        }

        prev_lowercase = char.is_ascii_lowercase();
    }

    String::from_utf8(acronym).unwrap()
}
