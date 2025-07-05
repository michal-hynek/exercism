use std::cmp::Ordering;

pub fn find(array: &[i32], key: i32) -> Option<usize> {
    let mut left: i32 = 0;
    let mut right: i32 = (array.len() as i32)-1;

    while left <= right {
        let middle = left + (right - left) / 2;

        match array[middle as usize].cmp(&key) {
            Ordering::Equal => {
                return Some(middle as usize);
            },

            Ordering::Less => {
                left = middle+1;
            },

            Ordering::Greater => {
                right = middle-1;
            },
        };
    }

    None
}
