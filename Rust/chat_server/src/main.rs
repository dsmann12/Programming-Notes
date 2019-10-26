use std::io;
use std::io::Write;

#[derive(Debug)]
struct User {
    username: String,
    password: String,
    login_count: u32,
    logged_in: bool,
    role: Role
}

impl User {
    fn debug_print(&self) {
        println!("{:#?}", self);
    }

    fn from(user: &User) -> User {
        User {
            username: String::from(&user.username),
            password: String::from(&user.password),
            login_count: 1,
            logged_in: true,
            role: Role::Normal
        }
    }
}

#[derive(Debug)]
enum Role {
    Normal,
    Moderator(String),
    Admin
}

fn get_default_user() -> String {
    String::from("default")
}

fn get_default_password() -> String {
    String::from("pass123")
}

fn print_default_info() {
    let default_user = get_default_user();
    let default_pass = get_default_password();

    println!("Default user is {}\nDefault password is {}", default_user, default_pass);
}

fn print_user_info(username: &str, password: &str) {
    println!("Username is: {}\nPassword is: {}", username, password);
}

fn print_user(user: &User) {
    println!("Username is: {}\nPassword is {}\nLogged in {} times.", user.username, user.password, user.login_count);

    match &user.role {
        Role::Admin => println!("User is an admin!"),
        Role::Moderator(channel) => println!("User is a moderator of {}", channel),
        _ => ()
    }
}

fn print_channels(channels: &[&str]) {
    for channel in channels.iter() {
        println!("Channel: {}", channel);
    }
}

fn login() -> User {
    print!("Username: ");
    io::stdout().flush()
        .expect("Error flushing stdout");

    let mut username = String::new();

    io::stdin().read_line(&mut username)
        .expect("Failed to read the line");

    let username = String::from(username.trim());

    print!("Choose a password: ");
    io::stdout().flush()
        .expect("Error flushing stdout");

    let mut password = String::new();
    io::stdin().read_line(&mut password)
        .expect("Failed to read the line");

    let password = String::from(password.trim());

    let role = match &username as &str {
        "dsmann12" => Role::Admin,
        "lelib" => Role::Moderator(String::from("Radical")),
        _ => Role::Normal
    };


    User {
        username,
        password,
        login_count: 1,
        logged_in: true,
        role
    }
}

fn main() {
    // CONSTANTS
    // port
    const PORT: u16 = 13337;

    let user = login();
    let user1 = User::from(&user);
    let username = &user.username;
    let password = &user.password;

    // let user_tuple: (&str, &str) = (username, password);

    // arrays
    let channels: [&str; 3] = ["Standard", "Alternative", "Radical"];
    // let threes = [3; 5] // 5 threes

    // tuples
    // let (u, p) = &user_tuple;
    // println!("Username is: {}\nPassword is: {}", u, p);
    // println!("Can also be written as {} and {}", user_tuple.0, user_tuple.1);

    // functions
    user.debug_print();
    user1.debug_print();
    print_user_info(username, password);
    print_user(&user);
    print_default_info();
    print_channels(&channels);

    // equivalent of ternary
    let is_me = if username == "dsmann12" { true } else { false };

    if is_me {
        println!("DSMANN12 IS IN THE BUILDING");
    } else {
        println!("Just some shlub");
    }

    println!("First channel after passing to function: {}", channels[0]);

    print_channels(&channels);
}
