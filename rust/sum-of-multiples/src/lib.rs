use std::collections::HashSet;

fn get_multiples(limit: u32, factors: &[u32]) -> HashSet<u32> {
    let mut multiples = HashSet::new();

    factors.iter().for_each(|factor| {
        if *factor == 0 {
            return;
        }

        for i in (0..limit).step_by(*factor as usize) {
            multiples.insert(i);
        }
    });

    multiples
}

pub fn sum_of_multiples(limit: u32, factors: &[u32]) -> u32 {
    get_multiples(limit, factors).iter().sum()
}
