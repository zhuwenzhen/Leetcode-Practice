//
//  main.cpp
//  PermutationString
//
//  Created by Wenzhen Zhu on 3/16/17.
//  Copyright © 2017 Wenzhen Zhu. All rights reserved.
//

// given a string, return its sequence number among its all permutations (assume unique chars)
// e.g.: ACDEILT(1st), CITADEL(1777th), TLIEDCA(7!th).

/**
 Maxim Piskunov:
	you need to reduce the problem from f(CITADEL) to f(ITADEL) + number
	where number is the number of strings of the type (<C)******
 Wenzhen Zhu:
	Do you mean DP way
	Dynamic programming?
	There is a hint 
    ACDEILT -> 1234567
    CITADEL -> 2571346
 return 1*6! + 3*5! + 4*4! + 0 + 0 + 0 + 0 (+ 1)
	But I don’t understand at all
	f(string)->what? Ranking?
 Maxim Piskunov:
	exactly
	yes
	the answer
	the hint is exactly what I was about to type
 Wenzhen Zhu:
	Can you explain the returning number
	Yes, Use DP or Yes the hint
 Maxim Piskunov:
	(number of letters in ITADEL smaller than C) * (length(ITADEL))! + (number of letters in TADEL smaller than I) * (length(TADEL))! + (number of letters in ADEL smaller than T) * (length(ADEL))! + (number of letters in DEL smaller than A) * (length(DEL))! + (number of letters in EL smaller than D) * (length(EL))! + (number of letters in L smaller than E) * (length(L))! + 1
 */

#include <iostream>
#include <string>

using namespace std;
class Solution{
public:
    int computeNum(string s, char c){
        int counter = 0;
        for(int i = 0; i < s.size(); i++){
            if (s[i] < c){
                counter++;
            }
        }
        return counter;
    }
    int factorial(int n){
        int factorial = 1;
        for(int i = 1; i <= n; i++){
            factorial *= i;
        }
        return factorial;
    }
    int computeRanking(string s){
        string curr;
        int f = 0;
        //  computeNum(curr, c) * length (curr)
        for(int i = 0; i < s.size(); i++){
            char c = s[i];
            curr = s.substr(i+1, s.size());
            int incre = computeNum(curr, c) * factorial((int)curr.size());
            f += incre;
            cout << i << "  s[i] = " << s[i] << "  curr = " << curr << " num = "<< computeNum(curr, c) << " length = " << (int)curr.size() << " , incre = " << incre << endl;
        }
        return f+1;
    }
};

int main(int argc, const char * argv[]) {
    string s1 = "citadel";
    string s2 = "acdeilt";
    Solution soln;
    cout << soln.computeRanking(s1) << endl;
    cout << soln.computeRanking(s2) << endl;
    return 0;
}
