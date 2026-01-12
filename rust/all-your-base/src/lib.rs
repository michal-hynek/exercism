#[derive(Debug, PartialEq, Eq)]
pub enum Error {
    InvalidInputBase,
    InvalidOutputBase,
    InvalidDigit(u32),
}

///
/// Convert a number between two bases.
///
/// A number is any slice of digits.
/// A digit is any unsigned integer (e.g. u8, u16, u32, u64, or usize).
/// Bases are specified as unsigned integers.
///
/// Return the corresponding Error enum if the conversion is impossible.
///
///
/// You are allowed to change the function signature as long as all test still pass.
///
///
/// Example:
/// Input
///   number: &[4, 2]
///   from_base: 10
///   to_base: 2
/// Result
///   Ok(vec![1, 0, 1, 0, 1, 0])
///
/// The example corresponds to converting the number 42 from decimal
/// which is equivalent to 101010 in binary.
///
///
/// Notes:
///  * The empty slice ( "[]" ) is equal to the number 0.
///  * Never output leading 0 digits, unless the input number is 0, in which the output must be `[0]`.
///    However, your function must be able to process input with leading 0 digits.
///
pub fn convert(number: &[u32], from_base: u32, to_base: u32) -> Result<Vec<u32>, Error> {
    if !is_valid_base(from_base) {
        return Err(Error::InvalidInputBase);
    }

    if !is_valid_base(to_base) {
        return Err(Error::InvalidOutputBase);
    }

    if let Some(digit) = invalid_digit(number, from_base) {
        return Err(Error::InvalidDigit(digit));
    }

    let dec_value = to_dec_value(number, from_base);
    let result = from_dec_value(&dec_value, to_base);

    Ok(result)
}

fn is_valid_base(base: u32) -> bool {
    base > 1
}

fn invalid_digit(number: &[u32], base: u32) -> Option<u32> {
    for &digit in number {
        if digit >= base {
            return Some(digit)
        }

    }

    None
}

fn to_dec_value(number: &[u32], from_base: u32) -> u32 {
    let mut dec_value = 0;
    let mut exp = 1;

    for &digit in number.iter().rev() {
        dec_value += digit * exp;
        exp *= from_base;
    }

    dec_value
}

fn from_dec_value(number: &u32, to_base: u32) -> Vec<u32> {
    let mut number = *number;

    if number == 0 {
        return vec![0];
    }

    let mut result = Vec::new();

    while number > 0 {
        result.push(number % to_base);
        number /= to_base;
    }

    result.reverse();

    result
}