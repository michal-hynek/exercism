use std::collections::BTreeMap;

pub fn transform(h: &BTreeMap<i32, Vec<char>>) -> BTreeMap<char, i32> {
    let mut char_tree = BTreeMap::new();

    for (value, chars) in h {
        for c in chars {
            char_tree.insert((*c).to_ascii_lowercase(), *value);
        }
    }
    
    char_tree
}
