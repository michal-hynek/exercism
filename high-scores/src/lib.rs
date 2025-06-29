use std::{cmp::Reverse, collections::BinaryHeap};

#[derive(Debug)]
pub struct HighScores {
    top_three: Vec<u32>,
    latest: Option<u32>,
    scores: Vec<u32>,
}

impl HighScores {
    pub fn new(scores: &[u32]) -> Self {
        let top_three = Self::top_n_scores(scores, 3);
        let latest = scores.last().copied();
        let scores = scores.to_owned();

        Self {
            top_three,
            latest,
            scores,
        }
    }

    pub fn scores(&self) -> &[u32] {
        &(self.scores)
    }

    pub fn latest(&self) -> Option<u32> {
        self.latest
    }

    pub fn personal_best(&self) -> Option<u32> {
        self.top_three.first().copied()
    }

    pub fn personal_top_three(&self) -> Vec<u32> {
        self.top_three.clone()
    }

    fn top_n_scores(scores: &[u32], n: usize) -> Vec<u32> {
        let mut min_heap: BinaryHeap<Reverse<&u32>> = BinaryHeap::new();

        for num in scores {
            if min_heap.len() == n && min_heap.peek().unwrap().0 < num {
                min_heap.pop().unwrap();
                min_heap.push(Reverse(num));
            } else if min_heap.len() < n {
                min_heap.push(Reverse(num));
            }
        }

        let mut top_scores = Vec::with_capacity(min_heap.len());

        while !min_heap.is_empty() {
            top_scores.push(*min_heap.pop().unwrap().0);
        }

        top_scores.reverse();

        top_scores
    }
}
