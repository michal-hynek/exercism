use std::fmt::Display;

#[derive(Debug, PartialEq, Eq)]
pub struct Clock {
    hours: i32,
    minutes: i32,
}

impl Display for Clock {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        write!(f, "{:02}:{:02}", self.hours, self.minutes)
    }
}

impl Clock {
    pub fn new(hours: i32, minutes: i32) -> Self {
        let extra_hours = if minutes >= 0 || minutes % 60 == 0 {
            minutes / 60
        } else {
            (minutes / 60) - 1
        };
        let hours = ((hours + extra_hours) % 24 + 24) % 24;
        let minutes = ((minutes % 60) + 60) % 60;

        Self { hours, minutes }
    }

    pub fn add_minutes(&self, minutes: i32) -> Self {
        Clock::new(self.hours, self.minutes + minutes)
    }
}
