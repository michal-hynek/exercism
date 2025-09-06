enum Prompt {
    Question,
    Yell,
    YellQuestion,
    Silence,
    Generic,
}

fn is_question(message: &str) -> bool {
    !message.is_empty() && message.trim().ends_with("?")
}

fn is_all_caps(message: &str) -> bool {
    message.chars().any(|c| c.is_uppercase()) &&
    message.chars().all(|c| c.is_uppercase() || !c.is_ascii_alphabetic())
}

fn is_empty(message: &str) -> bool {
    message.chars().all(|c| c.is_whitespace())
}

fn classify_message(message: &str) -> Prompt {
    let all_caps = is_all_caps(message);
    let question = is_question(message);
    let empty = is_empty(message);

    if empty {
        Prompt::Silence
    } else if all_caps && question {
        Prompt::YellQuestion
    } else if all_caps {
        Prompt::Yell
    } else if question {
        Prompt::Question
    } else {
        Prompt::Generic
    }
}

pub fn reply(message: &str) -> &str {
    match classify_message(message) {
        Prompt::Question=> "Sure.",
        Prompt::Yell => "Whoa, chill out!",
        Prompt::YellQuestion => "Calm down, I know what I'm doing!",
        Prompt::Silence => "Fine. Be that way!",
        Prompt::Generic => "Whatever.",
    }
}
