/**
 * @file UTest.h
 * @author Mahmoud Gadallah (mahmoudgadallah876@gmail.com)
 * @brief this is simple library to unit_test for competitive programming
 * @version 0.1
 * @date 2023-02-20
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef UTEST_H
#define UTEST_H

#include <bits/stdc++.h>

using namespace std;
class UTest {
    private:
        /**
         * @brief check the equality of 2 variables 
         * 
         * @tparam T 
         * @param out output value
         * @param exp expected output value
         * @return true out == exp
         * @return false out != exp
         */
        template <typename T>
        bool eq(T out, T exp) {
            return out == exp;
        }

        /**
         * @brief check the equality of 2 vectors
         * 
         * @tparam T type of elements in vector
         * @param out ouput vector
         * @param exp expected output vector
         * @return true if out have the same elements of exp
         * @return false if out doesn't have the same elements of exp
         */
        template <typename T>
        bool eqV(vector<T> &out, vector<T> &exp) {
            int n = out.size();
            if (n != exp.size())       return false;

            for (int i = 0; i < n; ++i)
                if (!eq(out[i], exp[i]))
                    return false;
            
            return true;
        }

        /**
         * @brief print passedMsg of current testcase
         * 
         * @param cnt current number of testcase
         */
        void passedMsg(int &cnt) {
            cout << "test No." << ++cnt << " passed✅" << "\n" << flush;
            cout << "------------------\n" << flush;
        }

        /**
         * @brief 
         * 
         * @tparam T type of element
         * @param out ouput value
         * @param exp expected outputvalue
         * @param cnt number of testcases
         * @param n total number of testcases
         */
        template <typename T>
        void failedMsg(T out, T exp,int &cnt, int &n) {
            cout << "test No." << cnt+1 << " failed❌" << "\n"
                << "your output✖️ " << out << '\n'
                << "Expected✔️ " << exp << '\n' << flush;
                
            cout << "------------------\n" << flush;
            cout << cnt << "/" << n << " tests passed✅\n" << flush;
        }

        /**
         * @brief convert types to string using to_string
         * 
         * @tparam T type of element
         * @param x type wanted to convert to string
         * @return string element converted to string
         */
        template <typename T>
        string toString (T x) {
            return to_string(x);
        }

        string toString(string x) {
            return x;
        }

        /**
         * @brief convert vector to string 
         * 
         * @tparam T type of elements in vector
         * @param v vecotr will be converted
         * @return string [e1, e2, e3]
         */
        template <typename T>
        string vec2Str(vector<T> &v) {
            int n = v.size();
            string ans = "[";
            
            for (int i = 0; i < n; ++i) {
                if (i)
                    ans += ", ";
                ans += toString(v[i]);
            }

            return ans+"]";
        }

        /**
         * @brief failed test of tests its type vector
         * 
         * @tparam T type of elements in vector
         * @param out output vector
         * @param exp expected output vector
         * @param cnt current testnumber
         * @param n all test numbers
         */
        template <typename T>
        void failedMsg(vector<T> out, vector<T> exp,int &cnt, int &n) {
            cout << "test No." << cnt+1 << " failed❌" << "\n"
                << "your output✖️ " << vec2Str(out) << '\n'
                << "Expected✔️ " << vec2Str(exp) << '\n' << flush;
                
            cout << "------------------\n" << flush;
            cout << cnt << "/" << n << " tests passed✅\n" << flush;
        } 

    public:
        /**
         * @brief passing out of functions and expected output and then check it
         * 
         * @tparam T type of tests
         * @param testStream vector of pair<out, exp> out: is output of the function we want to test and exp: is expected output
         */
        template <typename T>
        void test(vector<pair<T, T>> &testStream) {
            cout << "Testing.....\n..................\n" << flush;
            int cnt = 0, n = testStream.size();
            for (auto &tst : testStream) {
                if (eq(tst.first, tst.second))
                    passedMsg(cnt);
                else
                    return failedMsg(tst.first, tst.second, cnt, n);
            }

            cout << cnt << "/" << n << " tests passed✅👏\n" << flush;
        }

        /**
         * @brief passing out of functions and expected output and then check it
         * 
         * @tparam T type of element in vecotr of tests
         * @param testStream vector of pair that contains output vector and expected vector  wanted to test
         */
        template <typename T>
        void test(vector<pair<vector<T>, vector<T>>> &testStream) {
            cout << "Testing.....\n..................\n" << flush;
            int cnt = 0, n = testStream.size();
            for (auto &tst : testStream) {
                if (eqV(tst.first, tst.second))
                    passedMsg(cnt);
                else
                    return failedMsg(tst.first, tst.second, cnt, n);
            }

            cout << cnt << "/" << n << " tests passed✅👏\n" << flush;
        }
};

#endif