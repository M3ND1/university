using System.Text;
using System.Collections.Generic;
using static System.Runtime.InteropServices.JavaScript.JSType;

namespace DJB_adler32
{
    public struct data
    {
        public string str;
        public uint adler;
        public uint djbhash;
    }
    public struct data2
    {
        public string str;
        public string str2;
        public uint hashValue;
    }
    internal class Program
    {
        static uint number_of_collisions = 0;
        static string searchedCollision = "";
        static List<data> collisions = new();

        static uint adler32(string str)
        {
            const uint m = 65521;
            uint a = 1, b = 0;

            foreach (char c in str)
            {
                a = (a + c);
                b = (b + a);
            }

            return ((b % m) << 16) | (a % m);
        }
        static uint DJBHash(string str)
        {
            uint hash = 5381;
            for (uint i = 0; i < str.Length; i++)
            {
                hash = ((hash << 5) + hash) + ((byte)str[(int)i]);
            }

            return hash;
        }

        static List<string> generateRandomStrings(int howLong,int size)
        {
            List<string> sol = new();
            Random rand = new Random();
            for (int i=0;i<size;i++)
            {
                StringBuilder newstring = new(howLong);
                for (int j=0;j<howLong;j++)
                {
                    int c = rand.Next(26) + 'a';
                    newstring.Append((char)c);
                }
                sol.Add(newstring.ToString());
            }
            return sol;
        }
        static List<data> calculateCheckSums_check(ref List<string> generatedstrings)
        {
            List<data> sol = new();

            foreach(string s in generatedstrings)
            {
                data d = new();
                d.str = s;
                d.adler = adler32(s);
                d.djbhash = DJBHash(s);
                sol.Add(d);
            }
            return sol;
        }
        static void searchForCollisions(ref List<data> checkSums)
        {
            int numberOfCollisionsAD = 0;
            int numberOfCollisionsDJ = 0;
            List<data2> solutionsAD = new();
            List<data2> solutionsDJ = new();
            bool foundAD = false;
            bool foundDJ = false;
            for (int i = 0; i < checkSums.Count-1; i++)
            {
                for (int j = i + 1; j < checkSums.Count; j++)
                {
                    if (checkSums[i].adler == checkSums[j].adler)
                    {
                        numberOfCollisionsAD++;
                        if (!foundAD)
                        {
                            foundAD = true;
                            data2 solution = new();
                            solution.str = checkSums[i].str;
                            solution.str2 = checkSums[j].str;
                            solution.hashValue = checkSums[j].adler;
                            solutionsAD.Add(solution);
                        }
                    }
                    if (checkSums[i].djbhash == checkSums[j].djbhash)
                    {
                        numberOfCollisionsDJ++;
                        if (!foundDJ)
                        {
                            foundDJ = true;
                            data2 solution = new();
                            solution.str = checkSums[i].str;
                            solution.str2 = checkSums[j].str;
                            solution.hashValue = checkSums[j].djbhash;
                            solutionsDJ.Add(solution);
                        }
                    }
                }
            }

            Console.WriteLine($"adler32 D={checkSums[0].str.Length} N= {checkSums.Count}\n{numberOfCollisionsAD} kolizji\n");

            if (solutionsAD.Count > 0)
            {
                data2 solution = solutionsAD[0];
                Console.WriteLine($"{solution.str} {solution.str2} {solution.hashValue}\n");
            }
            Console.WriteLine($"DJBHash D={checkSums[0].str.Length} N= {checkSums.Count}\n{numberOfCollisionsDJ} kolizji\n");
            if (solutionsDJ.Count > 0)
            {
                data2 solution = solutionsDJ[0];
                Console.WriteLine($"{solution.str} {solution.str2} {solution.hashValue}\n");
            }
        }
        static void Main(string[] args)
        {
            List<string> generatedStrings_eight = generateRandomStrings(8, 100000);
            List<data> checkSums = calculateCheckSums_check(ref generatedStrings_eight);
            searchForCollisions(ref checkSums);
            List<string> generatedStrings_hunderd = generateRandomStrings(100, 100000);
            List<data> checkSums_hundred = calculateCheckSums_check(ref generatedStrings_hunderd);
            searchForCollisions(ref checkSums_hundred);
        }
    }
}