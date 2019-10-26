// use statements
use std::fs;
use std::error::Error;
use std::env;

pub struct Config {
    pub query: String,
    pub filename: String,
    pub case_sensitive: bool
}

impl Config {
    pub fn new(args: &[String]) -> Result<Config, String> {
        if args.len() < 3 {
            return Err(format!("Error: User must supply two arguments\nUsage: {} [QUERY] [FILENAME]", args[0]));
        }

        let query = String::from(&args[1]);
        let filename = String::from(&args[2]);
        let case_sensitive = env::var("CASE_INSENSITIVE").is_err();

        Ok (Config {
            query,
            filename,
            case_sensitive
        })
    }
}

pub fn run(config: Config) -> Result<(), Box<dyn Error>> {
    let contents = fs::read_to_string(config.filename)?;

    let results = if config.case_sensitive {
        search(&config.query, &contents)
    } else {
        search_case_insensitive(&config.query, &contents)
    };

    for line in results {
        println!("{}", line);
    }

    Ok(())
}

pub fn search<'a>(query: &str, contents: &'a str) -> Vec<&'a str> {
    let mut matches: Vec<&'a str> = Vec::new();

    for line in contents.lines() {
        if line.contains(query) {
            matches.push(line);
        }
    }

    matches
}

pub fn search_case_insensitive<'a>(query: &str, contents: &'a str) -> Vec<&'a str> {
    let query = query.to_lowercase();
    let mut matches: Vec<&'a str> = Vec::new();
    for line in contents.lines() {
        if line.to_lowercase().contains(&query) {
            matches.push(line);
        }
    }

    matches
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn case_sensitive() {
        let query = "duct";
        let contents = "Rust:\nsafe, fast, productive.\nPick three.\nDuct tape";
        println!("{}", contents);
        let lines = search(query, contents);
        for line in lines {
            println!("{}", line);
        }
        assert_eq!(vec!["safe, fast, productive."], search(query, contents));
    }

    #[test]
    fn case_insensitive() {
        let query = "rUsT";
        let contents = "Rust:\nsafe, fast, productive.\nPick three.\nTrust me";
        println!("{}", contents);
        let lines = search_case_insensitive(query, contents);
        for line in lines {
            println!("{}", line);
        }
        assert_eq!(vec!["Rust:", "Trust me"], search_case_insensitive(query, contents));
    }
}
