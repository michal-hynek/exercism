use std::cmp::{Ordering, Ord};

pub fn find<T: Ord>(array: impl AsRef<[T]>, key: T) -> Option<usize> {
    let array = array.as_ref();

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
