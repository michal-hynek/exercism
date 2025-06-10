fn capitalize(s: String) -> String {
    if s.is_empty() {
        s
    } else {
        let (first, rest) = s.split_at(1);
        format!("{}{}", first.to_uppercase(), rest)
    }
}

fn num_word(num: u32) -> String {
    if num == 10 {
        "ten".to_string()
    } else if num == 9 {
        "nine".to_string()
    } else if num == 8 {
        "eight".to_string()
    } else if num == 7 {
        "seven".to_string()
    } else if num == 6 {
        "six".to_string()
    } else if num == 5 {
        "five".to_string()
    } else if num == 4 {
        "four".to_string()
    } else if num == 3 {
        "three".to_string()
    } else if num == 2 {
        "two".to_string()
    } else if num == 1 {
        "one".to_string()
    } else {
        "no".to_string()
    }
}

fn bottle_word(bottles: u32) -> String {
    if bottles == 1 {
        "bottle".to_string()
    } else {
        "bottles".to_string()
    }
}

fn paragraph(bottles: u32) -> String {
    let verse1 = format!("{} green {} hanging on the wall", capitalize(num_word(bottles)), bottle_word(bottles));
    let verse2 = "And if one green bottle should accidentally fall";
    let verse3 = format!("There'll be {} green {} hanging on the wall", num_word(bottles-1), bottle_word(bottles-1));

    format!("{verse1},\n{verse1},\n{verse2},\n{verse3}.")
}

pub fn recite(start_bottles: u32, take_down: u32) -> String {
    let mut song = String::new();

    for bottles in (start_bottles-take_down+1..=start_bottles).rev() {
        song.push_str(&paragraph(bottles));
        song.push_str("\n\n");
    }

    song.trim().to_string()
}
