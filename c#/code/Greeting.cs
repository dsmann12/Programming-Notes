using System;

public class Greeting {
	public static void Main() {
		Console.Write("What is your name: ");
		string name = Console.ReadLine();
		Console.WriteLine("Hey, {0}!", name);
	}
}
