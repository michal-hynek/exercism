fn is_opening_bracket(c: char) -> bool {
    c == '(' || c == '{' || c == '['
}

fn is_closing_bracket(c: char) -> bool {
    c == ')' || c == '}' || c == ']'
}

fn is_matching_bracket(opening: char, closing: char) -> bool {
    if opening == '(' {
        closing == ')'
    } else if opening == '{' {
        closing == '}'
    } else if opening == '[' {
        closing == ']'
    } else {
        false
    }
}

fn push(c: char, stack: &mut Vec<char>, stack_top: &mut usize) {
    if *stack_top < (*stack).len() {
        stack[*stack_top] = c;
    } else {
        stack.push(c);
    }

    *stack_top += 1;
}

pub fn brackets_are_balanced(string: &str) -> bool {
    let mut open_brackets = Vec::new();
    let mut open_brackets_num = 0;

    for c in string.chars() {
        if is_opening_bracket(c) {
            push(c, &mut open_brackets, &mut open_brackets_num);
        } else if is_closing_bracket(c) &&
            open_brackets_num > 0 &&
            is_matching_bracket(*(open_brackets.get(open_brackets_num-1).unwrap()), c) {
            open_brackets_num -= 1;
        } else if is_closing_bracket(c) {
            return false;
        }
    }

    open_brackets_num == 0
}
