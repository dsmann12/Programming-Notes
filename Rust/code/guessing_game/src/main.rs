// external library crate
// external dependency
// Equivalent of calling use rand (also)
extern crate rand;

// io is a part of std library
// By default, rust only bring a few types into the scope of every program
// in the *prelude*
use std::io;
// For comparisons
// An enum. Greater, Less, Equal. Three values when comparing
use std::cmp::Ordering;
// Rng "trait" defines methods than RNGs impelement.
// Must be in scope to use those methods. 
use rand::Rng;

fn main() { 
    // thread_rng() gives particular rng to be used
    // one that is local to current thread of execution and seeded by OS
    // Call gen_range on rng. Defined by Rng trait.
    // Takes two arguments and generates a random number between them.
    // Inclusive lower bound, exclusive upper bound
    let secret_number = rand::thread_rng().gen_range(1, 101);
    //println!("The secret number is {}", secret_number);
    //
    // had problem when guess was outside loop
    // read_line() appended to guess
    // but could not reassign string guess after shadow
    loop {
        println!("Guess the number!");
        println!("Please input your guess:");

        // let statement is used to create a variable
        // let foo = bar;
        // variables immutable by default in Rust
        // let mut bar = 5;
        // :: -> denotes associated (static) function
        let mut guess = String::new();
            
        // read_line returns io::Result - an enum
        // which can be Ok or Err. 
        // If Err, expect() writes string to stderr
        // and crashes. Otherwise, returns return value in Ok
        // &mut guess -> mutable reference. 
        // References immutable by default.
        io::stdin().read_line(&mut guess)
            .expect("Failed to read line");

        println!("{}", guess);

        // trim white space and parse string as int
        // Shadowing allows you to use a variable name for other type
        // instead of making multiple variables. 
        let guess: u32 = match guess.trim().parse() {
            // .expect("Please type a number!")
                Ok(num) => num,
                // _ is catchall value. All errors match
                Err(_) => continue,
            }; 

        println!("You guessed: {}", guess);

        // cmp compares two values and can be called on anything that can 
        // be compared. Takes a reference to whatever want to compare
        // match expression decides what to do next based on which variant
        // of Ordering was returned. 
        // match expression made up of arms.
        // Arm consists of a pattern and the code that should be run if the
        // value given to the begining of the match expression that arm's
        // pattern.
        // Checks every arm. Ends when it gets a match in this scenario. 
        // Can't compare different types
        match guess.cmp(&secret_number) {
            Ordering::Less => println!("Too small!"),
            Ordering::Greater => println!("Too big!"),
            Ordering::Equal => { 
                println!("You win!");
                break;
            },
        }
    }

    /*
    let x = 5;
    let y = 10;

    println!("Showing how to use placeholders");
    println!("x = {}, y = {}", x, y);
    */
}
