<<<<<<< HEAD
//
// Created by 26236 on 2023/5/4.
//
#include <bits/stdc++.h>
using namespace std;

double average(vector<int>& salary);

int main(){
    vector<int> my_salaries = {4000,3000,1000,2000};
    double my_average = average(my_salaries);
    printf("the average salary: %f\n", my_average);
}

double average(vector<int>& salary){
    auto max_salary_index = max_element(salary.begin(), salary.end());
    salary.erase(max_salary_index);
    auto min_salary_index = min_element(salary.begin(), salary.end());
    salary.erase(min_salary_index);
    double average = accumulate(salary.begin(), salary.end(), 0.0)/salary.size();
    return average;
}

=======
//
// Created by 26236 on 2023/5/4.
//
#include <bits/stdc++.h>
using namespace std;

double average(vector<int>& salary);

int main(){
    vector<int> my_salaries = {4000,3000,1000,2000};
    double my_average = average(my_salaries);
    printf("the average salary: %f\n", my_average);
}

double average(vector<int>& salary){
    auto max_salary_index = max_element(salary.begin(), salary.end());
    salary.erase(max_salary_index);
    auto min_salary_index = min_element(salary.begin(), salary.end());
    salary.erase(min_salary_index);
    double average = accumulate(salary.begin(), salary.end(), 0.0)/salary.size();
    return average;
}

>>>>>>> 0f624ce6372e51a14920d90879008100a776bbc5
