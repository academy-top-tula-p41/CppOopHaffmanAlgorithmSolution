#pragma once
#include <iostream>
#include <algorithm>
#include <ranges>

#include <vector>
#include <deque>
#include <list>

#include <set>
#include <map>

class Examples
{
public:

	static void ContainresExample()
	{
        const int size{ 10 };
        int arrayInit[size]{ 30, 10, 60, 20, 90, 40, 50, 70, 80, 50 };

        auto actionCout = [](auto item) { std::cout << item << " "; };

        // VECTOR
        std::vector<int> vectorInt;
        for (int i{}; i < size; i++)
            vectorInt.push_back(arrayInit[i]);

        std::for_each(vectorInt.begin(),
            vectorInt.end(),
            actionCout);
        std::cout << "\n";

        std::ranges::for_each(vectorInt, actionCout);
        std::cout << "\n";

        std::ranges::for_each(vectorInt.begin() + 2,
            vectorInt.begin() + 7,
            actionCout);
        std::cout << "\n";

        vectorInt.insert(vectorInt.begin() + 3, 100);
        std::ranges::for_each(vectorInt, actionCout);
        std::cout << "\n";

        // DEQUE
        std::deque<int> dequeInt(vectorInt.begin() + 3, vectorInt.end() - 1);
        std::ranges::for_each(dequeInt, actionCout);
        std::cout << "\n";

        // LIST
        std::list<int> listInt(dequeInt.begin(), dequeInt.end());

        // SET
        std::set<int> setInt;
        std::ranges::for_each(vectorInt,
            [&setInt](auto item)
            {
                setInt.insert(item);
            });
        std::ranges::for_each(setInt, actionCout);
        std::cout << "\n";

        // MAP
        std::map<int, std::string> regions;

        regions.insert({ 71, "Tula" });
        regions.insert(std::pair(59, "Perm"));

        regions[38] = "Ivanovo";

        regions.insert(std::make_pair(73, "Ulyanovsk"));
        regions.insert({ 44, "Kostroma" });

        regions[38] = "Irkutsk";

        std::ranges::for_each(regions,
            [](auto region) {
                std::cout << region.first << ": " << region.second << "\n";
            });
        std::cout << "\n";
	}
};

