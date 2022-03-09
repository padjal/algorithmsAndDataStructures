/*
 * Implementation of the Knuth–Morris–Pratt algorithm.
 * The aim of this algorithm is to find substrings in
 * a given string. It among the most famous ones for
 * performing such a task and is based on the idea of a
 * first analyzing the given substring before searching
 * its occurrences in the given string.
 */

#include <iostream>
#include <string>
#include <vector>

/*
 * Code reference: https://habr.com/ru/post/113266/
 */
std::vector<int> calc_prefix_function(const std::string & str)
{
    const size_t str_length = str.size();

    std::vector<int> prefix_func(str_length);

    if (0 == str_length)
        return prefix_func;

    prefix_func[0] = 0;

    for (size_t current = 1; current < str_length; ++current)
    {
        size_t matched_prefix = current - 1;
        size_t candidate = prefix_func[matched_prefix];
        while (candidate != 0 && str[current] != str[candidate])
        {
            matched_prefix = prefix_func[matched_prefix] - 1;
            candidate = prefix_func[matched_prefix];
        }

        if (candidate == 0)
            prefix_func[current] = str[current] == str[0] ? 1 : 0;
        else
            prefix_func[current] = candidate + 1;
    }
}

std::vector<int> getBorders(std::string line){
    std::vector<int> result;

    if(line.empty()){
        return result;
    }

    result.push_back(0);

    for (size_t i = 1; i < line.size(); ++i) {
        //char current_char = line.at(i);
        if(line.at(i) == line.at(result.at(i - 1))){
            // Next character is the same as the character after the longest previous border.
            result.push_back(result.at(i - 1) + 1);
        }else{
            char candidate = line.at(result.at(i - 1));
            while (candidate != line.at(i)){
                //candidate = line.at()
            }
            result.push_back(0);
        }
    }

    return result;
}

int KMP (std::string first_string, std::string second_string, std::vector<int> borders){
    int count = 0;
    int k = 0;
    for (int i = 0; i < first_string.size(); ++i){
        while ((k > 0) && second_string[k + 1] != first_string[i]) {
            k = borders[k];
        }

        if (first_string[k + 1] = second_string[i]){
            k++;
        }
        if (k == second_string.size()){
            //вывод "P входит в T с позиции", i – m + 1;
            count++;
            k = borders[second_string.size()];
        }
    }

    return count;
}

template <typename T>
void printVector(const std::vector<T>& v){
    for(auto e : v){
        std::cout << e << " ";
    }
}

int main() {
    // Take input
    std::string first_string;
    std::string second_string;

    std::getline(std::cin, first_string);

    std::getline(std::cin, second_string);

    std::vector<int> second_string_borders;
    second_string_borders = calc_prefix_function(second_string);

    std::cout << KMP(first_string, second_string, second_string_borders);

    //printVector(second_string_borders);

    // Print out how many times the second substring enters the first string.

    return 0;
}
