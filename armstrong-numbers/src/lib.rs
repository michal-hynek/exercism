fn get_digits(num: u32) -> Vec<u32> {
    let mut num = num;
    let mut digits = Vec::new();

   while num > 0 {
        digits.push(num%10);
        num /= 10;
    }

    digits
}

pub fn is_armstrong_number(num: u32) -> bool {
    if num == 0 {
        return true;
    }

    let digits = get_digits(num);
    let digit_sum = digits.iter().map(|d| d.pow(digits.len() as u32)).sum::<u32>();

    digit_sum == num
}
