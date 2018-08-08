fn main() {
	let a: [i32; 10];
	
	for i in 0..10 {
		let mut line = String::new();
		let input = std::io::stdin().read_line(&mut line);
		let guess:i32 = input.ok().map_or(-1, |_| line.trim().parse().ok());
		a[i] = guess;
	}
}
