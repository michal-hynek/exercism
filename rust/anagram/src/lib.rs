use std::collections::{HashSet, HashMap};

fn are_equal(word1: &str, word2: &str) -> bool {
    word1.to_lowercase() == word2.to_lowercase()
}

fn char_counts(word: &str) -> HashMap<char, usize> {
    let mut counts= HashMap::new();

    for char in word.to_lowercase().chars() {
        match counts.get_mut(&char) {
            Some(count) => {
                *count += 1;
            },

            None => {
                counts.insert(char.to_owned(), 1);
            }
        }
    }

    counts 
}

fn is_anagram(word1: &str, word2: &str) -> bool {
    let word1_chars = char_counts(word1);
    let word2_chars = char_counts(word2);

    if word1_chars.len() != word2_chars.len() {
        return false;
    }

    for (char, count) in word1_chars {
        if !word2_chars.contains_key(&char) || *(word2_chars.get(&char).unwrap()) != count {
            return false;
        }
    }

    true
}

pub fn anagrams_for<'a>(word: &str, possible_anagrams: &[&'a str]) -> HashSet<&'a str> {
    let mut anagrams = HashSet::new();

    for anagram in possible_anagrams {
        if !are_equal(word, anagram) && is_anagram(word, anagram) {
            anagrams.insert(*anagram);
        }
    }

    anagrams
}
