pub fn collatz(n: u64) -> Option<u64> {
    if n == 0 {
        return None;
    }

    let mut x = n;
    let mut steps = 0;

    while x != 1 {
        if x % 2 == 0 {
            x /= 2;
        } else {
            x = x*3 + 1;
        }

        steps += 1
    }

    Some(steps)
}
