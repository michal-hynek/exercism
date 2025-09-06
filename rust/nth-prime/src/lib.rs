fn is_prime(x: u32) -> bool {
    if x < 2 {
        return false;
    }

    let mut i = 2;
    while i*i <= x {
        if x % i == 0 {
            return false;
        }

        i += 1;
    }

    true
}

pub fn nth(n: u32) -> u32 {
    let mut nth = 0;

    for i in 2..1_000_000 {

        if is_prime(i) {
            if nth == n {
                return i;
            }

            nth += 1;
        }
    }

    0
}
