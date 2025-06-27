#[derive(Debug, PartialEq, Eq)]
pub enum Comparison {
    Equal,
    Sublist,
    Superlist,
    Unequal,
}

fn are_equal(first_list: &[i32], second_list: &[i32]) -> bool {
    if first_list.len() != second_list.len() {
        return false;
    }

    for i in 0..first_list.len() {
        if first_list[i] != second_list[i] {
            return false;
        }
    }

    true
}

fn contains(first_list: &[i32], second_list: &[i32]) -> bool {
    if second_list.len() > first_list.len() {
        return false;
    }

    let mut start = 0;
    while start <= (first_list.len() - second_list.len()) {
        if are_equal(&first_list[start..start+second_list.len()], second_list) {
            return true;
        }

        start += 1;
    }

    false
}

fn is_contained(first_list: &[i32], second_list: &[i32]) -> bool {
    contains(second_list, first_list)
}

pub fn sublist(first_list: &[i32], second_list: &[i32]) -> Comparison {
    if are_equal(first_list, second_list) {
        Comparison::Equal
    } else if contains(first_list, second_list) {
        Comparison::Superlist
    } else if is_contained(first_list, second_list) {
        Comparison::Sublist
    } else {
        Comparison::Unequal
    }
}
