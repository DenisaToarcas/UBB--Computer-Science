using System;

namespace prime
{
    public class SieveErathosthenes
    {
        public static void SieveOfErathosthene(int n)
        {
            int cnt = 0;
            bool[] ifPrimeNumbers = new bool[n + 1];

            for (int i = 0; i <= n; i++)
                ifPrimeNumbers[i] = true;

            for (int p = 2; p * p <= n; p++)
            {
                if (ifPrimeNumbers[p] == true)
                {
                    for (int i = p * p; i <= n; i += p)
                        ifPrimeNumbers[i] = false;
                }
            }

            int number = 0;
            for (int i = 0; i <= n; i++)
            { if (ifPrimeNumbers[i] == true)
                {
                    number = i;
                    cnt++;
                }
                if (cnt == 10001)
                    break;
            }

            Console.WriteLine("The 10001st prime number is: " + number);

        }

       public static void Main()
        {
            int n = 200000;
            SieveOfErathosthene(n);
        }
    }
}