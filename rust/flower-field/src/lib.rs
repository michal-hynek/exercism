fn count_flowers(row: usize, col: usize, garden: &[&str]) -> u8 {
    let is_valid = |x: i32, y: i32| {
        y >= 0 && y < garden.len() as i32 && x >= 0 && x < garden[0].len() as i32
    };

    let neighbor_directions = vec![
        (0, -1), (1, 0), (0, 1), (-1, 0),
        (-1, -1), (1, -1), (1, 1), (-1, 1),
    ];

    let mut flowers = 0;
    for (x, y) in neighbor_directions {
        let next_x = x + col as i32;
        let next_y = y + row as i32;

        if is_valid(next_x, next_y) && garden[next_y as usize].as_bytes()[next_x as usize] == b'*' {
            flowers += 1;
        }
    }

    if flowers > 0 {
        flowers + b'0'
    } else {
        b' '
    }
}

pub fn annotate(garden: &[&str]) -> Vec<String> {
    if garden.is_empty() {
        return Vec::new();
    }

    let rows = garden.len();
    let cols = garden[0].len();
    let mut annotated_garden = vec![" ".repeat(cols); rows];

    for (i, &row) in garden.iter().enumerate() {
        for (j, cell) in row.bytes().enumerate() {
            let annotated_cell = if cell == b'*' {
                cell
            } else {
                count_flowers(i, j, garden)
            };

            unsafe {
                annotated_garden[i].as_bytes_mut()[j] = annotated_cell;
            }
        }
    }

    annotated_garden
}
