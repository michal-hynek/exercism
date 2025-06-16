fn student_offset(student: &str) -> usize {
    let first_char = student.bytes().next().unwrap();
    ((first_char - b'A') * 2) as usize
}

fn student_plants(diagram: &str, offset: usize) -> Vec<char> {
    let mut plants = Vec::with_capacity(4);
    let lines = diagram.lines().collect::<Vec<_>>();

    plants.push(lines.first().unwrap().chars().nth(offset).unwrap());
    plants.push(lines.first().unwrap().chars().nth(offset+1).unwrap());
    plants.push(lines.get(1).unwrap().chars().nth(offset).unwrap());
    plants.push(lines.get(1).unwrap().chars().nth(offset+1).unwrap());

    plants
}

fn translate(plants: Vec<char>) -> Vec<&'static str> {
    plants.iter().map(|plant| {
        if *plant == 'G' {
            "grass"
        } else if *plant == 'C' {
            "clover"
        } else if *plant == 'R' {
            "radishes"
        } else {
            "violets"
        }
    }).collect()
}

pub fn plants(diagram: &str, student: &str) -> Vec<&'static str> {
    let student_offset = student_offset(student);
    let student_plants = student_plants(diagram, student_offset);

    translate(student_plants)
}
