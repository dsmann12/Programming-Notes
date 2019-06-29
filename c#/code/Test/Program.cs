using System;

namespace Test
{
    class Program
    {
		public static string reverse (string s) {
            char[] arr = s.ToCharArray();
            Console.WriteLine(arr.ToString());
            int last = arr.Length - 1;
            for (int i = 0; i < arr.Length/2; i++) {
                char temp = arr[i];
                arr[i] = arr[last - i];
                arr[last - i] = temp;
            }

            foreach(char c in arr) {
                Console.WriteLine(c);
            }

			return new String(arr) 
		}

        static void Main(string[] args)
        {
            Console.WriteLine("Hello World!");
            string formattedString = string.Format("100000 in hex is {0:x}", 100000);
            string formattedPi = string.Format("PI with 9 decimal places is {0:f9}", 3.14598);
            Console.WriteLine(formattedString);
            Console.WriteLine(formattedPi);
            string rev = reverse("Madam, I'm Adam");
            Console.WriteLine(rev);
        }
    }
}
