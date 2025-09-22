namespace hellmath {

// account types: `troll`, `guest`, `user`, and `mod`.
enum class AccountStatus {
    troll,
    guest,
    user,
    mod
};

// permission types: `read`, `write`, and `remove`.
enum class Action {
    read,
    write,
    remove
};

// Task 2 - Implement the `display_post` function, that gets two arguments
// of `AccountStatus` and returns a `bool`. The first argument is the status of
// the poster, the second one is the status of the viewer.
bool display_post(AccountStatus poster_status, AccountStatus viewer_status) {
    if (poster_status == AccountStatus::troll && viewer_status == AccountStatus::troll) {
        return true;
    } else {
        return poster_status != AccountStatus::troll;
    }
}

// Task 3 - Implement the `permission_check` function, that takes an
// `Action` as a first argument and an `AccountStatus` to check against. It
// should return a `bool`.
bool permission_check(Action action, AccountStatus status) {
    if (status == AccountStatus::guest) {
        return action == Action::read;
    }
    if (status == AccountStatus::user || status == AccountStatus::troll) {
        return action == Action::read || action == Action::write;
    }

    return status == AccountStatus::mod;
}

// Task 4 - Implement the `valid_player_combination` function that
// checks if two players can join the same game. The function has two parameters
// of type `AccountStatus` and returns a `bool`.
bool valid_player_combination(AccountStatus status1, AccountStatus status2) {
    if (status1 == AccountStatus::guest || status2 == AccountStatus::guest) {
        return false;
    } else if (status1 != AccountStatus::troll && status2 != AccountStatus::troll) {
        return true;
    } else {
        return status1 == AccountStatus::troll && status2 == AccountStatus::troll;
    }
}

// Task 5 - Implement the `has_priority` function that takes two
// `AccountStatus` arguments and returns `true`, if and only if the first
// account has a strictly higher priority than the second.
bool has_priority(AccountStatus status1, AccountStatus status2) {
    switch (status1) {
        case AccountStatus::troll:
            return false;
        case AccountStatus::guest:
            return status2 == AccountStatus::troll;
        case AccountStatus::user:
            return status2 == AccountStatus::troll || status2 == AccountStatus::guest;
        case AccountStatus::mod:
            return status2 != AccountStatus::mod;
        default:
            return false;
    }
}

}  // namespace hellmath