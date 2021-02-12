// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<vector>
long long Factorial(long a)
{
    std::cout << "Computing Fact(" << a << ")\n";
    if (a <= 1)
        return 1;
    else
        return a * Factorial(a - 1);
}
int Mystery(int n)
{
    if (n < 10)
        return n * 10 + n;
    else
    {
        int a = Mystery(n / 10);
        int b = Mystery(n % 10);
        return a * 100 + b;
    }
}
bool isPalindrome(std::string s)
{
    if (s.size() <= 1)
        return true;
    else if (s[0] == s[s.size() - 1])
        return isPalindrome(s.substr(1, s.size()-2));
    else
        return false;
}
void TowersOfHanoi(int n, char from, char to, char aux)
{
    std::cout << "Moving" << n << "discs" << "from " << from << "to" << to << "\n";
    if (n == 0)
        return;
    TowersOfHanoi(n - 1, from, aux, to);
    std::cout << "Move disc " << n << "to" << to << "\n";
    TowersOfHanoi(n - 1, aux, to, from);  
}
void BinaryHelper(int n, std::string output)
{
//std:: cout << "Recursive call  n=  " << n << "\t"<<output<<"\n";
    if (n == 0)
        std::cout << output << "\n";
    else
    {
        BinaryHelper(n - 1, output + "0");
        BinaryHelper(n - 1, output + "1");
    }
}
/*Print all binary strings of length n*/
void printAllBinary(int n)
{
    BinaryHelper(n, "");//Recursion implemented in this helper function
}

   
template<typename T>
void printVector(std::vector<T> v )
{
    std::cout << "{";
    for (auto i : v)
        std::cout << i << ",";
    std::cout << "}\n";
}
void diceSumHelper(int n, int sum, std::vector<int>& v)
{
    if (n == 0 and sum==0) {
        printVector(v);
   
    }
    else if(sum >=n*1 and sum<n*6)
    {
        for (int i = 1; i <= 6; ++i)
        {
            v.push_back(i);
            diceSumHelper(n-1, sum-i, v);
            v.pop_back();

        }
             
    }
}

void diceSum(int dice, int sum)
{
    std::vector<int>v;
    diceSumHelper(dice, sum, v);
}
void permuteHelper(std::vector<std::string>& v, std::vector<std::string>& chosen)
{
    if (v.empty())
        printVector(chosen);
    else
    {
        for(int i=0;i<v.size();++i)
        {
            std::string s = v[i];

            chosen.push_back(s);
            v.erase(v.begin()+i);
            permuteHelper(v, chosen);
            chosen.pop_back();
            v.insert(v.begin()+i, s);
        }
    }

}
void permute(std::vector < std::string>v)
{
    std::vector<std::string> chosen;
    permuteHelper(v, chosen);

}
void subListHelper(std::vector<std::string>& v, std::vector<std::string>& chosen)
{
    if (v.empty())
        printVector(chosen);
    else
    {
        std::string s = v[0];
        v.erase(v.begin());
        subListHelper(v, chosen);
        chosen.push_back(s);
        subListHelper(v, chosen);
        chosen.pop_back();
        v.insert(v.begin(), s);
    }
}
void subList(std::vector<std::string>& v)
{
    std::vector<std::string> chosen;
    subListHelper(v, chosen);
}
int main( )
{
    
   
    printAllBinary(6);
    diceSum(3, 10);
    std::vector<std::string> v{ "A","B","C" };
    permute(v);
    std::vector < std::string> names{ "Darisa","Emile","Ange","Jeannette" };
    subList(names);
    
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
