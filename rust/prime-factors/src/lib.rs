pub fn factors(n: u64) -> Vec<u64> {
    let mut result = Vec::new();

    if n < 2 {
        return result;
    }

    let mut i = 2;
    while i*i <= n {
        if n % i == 0 {
            result.push(i);

            let mut remaining_factors = factors(n/i);
            result.append(&mut remaining_factors);

            break;
        }

        i += 1;
    }

    if result.is_empty() {
        result.push(n);
    }

    result
}
