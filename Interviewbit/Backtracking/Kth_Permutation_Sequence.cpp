The set [1,2,3,…,n] contains a total of n! unique permutations.
By listing and labeling all of the permutations in order,
We get the following sequence (ie, for n = 3 ) :
1. "123"
2. "132"
3. "213"
4. "231"
5. "312"
6. "321"

Given n and k, return the kth permutation sequence.
For example, given n = 3, k = 4, ans = "231"

Good questions to ask the interviewer :
What if n is greater than 10. How should multiple digit numbers be represented in string?
    In this case, just concatenate the number to the answer.
    so if n = 11, k = 1, ans = "1234567891011" 

What's the maximum value of n and k?
    In this case, k will be a positive integer that's less than INT_MAX.
    n is reasonable enough to make sure the answer does not bloat up a lot.

Approach 
1. Recursive version. T(n) = O(n)  S(n) = O(n)

    Function Permutation() will find which digit of a given string will be correct at first position for given string and given K. 
    K starts from 1 but in my approach starts from 0.

    Suppose we fix X at 1st position then total permutation possible with first digit as X is (n - 1)!
    Suppose we fix X at 2nd position then total permutation possible with first digit as X is (n - 2)!

    So our aim is to find correct digit at 1st position given n numbers and K.
    If X is correct digit then (Total_Number_of_Digit_Less_Then_X * (n - 1)!) should be lesser than K.

    So, Total_Number_of_Digit_Less_Then_X = K / (n - 1)!
    So, correct digit = Number[Total_Number_of_Digit_Less_Then_X]
    As, index i = 2 then there would be 2 elements on it’s left.

    We finally get correct digit.

    Now new K = K - (Total_Number_of_Digit_Less_Then_X * (n - 1)!)
    As we covered Total_Number_of_Digit_Less_Then_X * (n - 1)!
    Or We can also write K = K % (n - 1)!

    Now we discard correct digit from number vector and call same function with updated vector and K for the next correct digits.

    So, current digit + Permutation(Number, K) will be our answer.

    Every function call is O(1) and we call it N times. And for N factorial we need O(N).
    So, O(N) + O(N)

    T(n) = O(N).
    S(n) = O(N). As we use recursion and at one time stack will have n function call.

    CODE:

    string Permutation(vector<string> &Number, int B, vector<int> &Fact)
    {
        if(B == 0) // Means we are at Kth position.
        {
            string str;
            str = accumulate(Number.begin(), Number.end(), str); // Used to convert string vector to 
    											                                     // single string
            return str;
        }
        
        int Combination_With_Next_Digits = Fact[Number.size() - 1];
        
        int Numbers_To_Skip = B / Combination_With_Next_Digits; // Means this many numbers we 
    											                             // can cover in K
        // int New_B = B - (Numbers_To_Skip * Combination_With_Next_Digits);
        int New_B = B % Combination_With_Next_Digits; // Sbutracting numbers we covered in K.
        
        string str;
        str += Number[Numbers_To_Skip]; // Discard and append correct digit
        Number.erase(Number.begin() + Numbers_To_Skip);  // Remove correct digit as we already 
    											        // used now.
        str += Permutation(Number, New_B, Fact); // Again call same function for remaining numbers.
        return str;
    }

    string Solution::getPermutation(int A, int B) {
        vector<int> Fact(A + 1, 1);
        vector<string> Number(A," ");
        
        for(int i = 2; i < A + 1; ++i)
        {
            if(i <= 12)
                Fact[i] = i * Fact[i - 1];
            else
                Fact[i] = INT_MAX;  //(i > 12)
                // this overflows in int. So, it’s definitely greater than k as k < INT_MAX.
                // which is all we care about. So, we return INT_MAX which
                // is also greater than k.
        }
        
        if(A == 0 || Fact[A] < (B - 1)) // As B - 1 <= n! Must. Otherwise invalid so return “”.
            return "";
        
        for(int i = 0; i < A; ++i)
            Number[i] = to_string(i + 1); // store string as number. We can store it as single string.
                                          //because we can’t differentiate 12 as 1 and 2 or 12.
            
        return Permutation(Number, B - 1, Fact);
    }
