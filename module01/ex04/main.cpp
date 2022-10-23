/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsarhan <hsarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 09:07:20 by hsarhan           #+#    #+#             */
/*   Updated: 2022/10/23 16:33:54 by hsarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <fstream>
#include <iostream>

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cerr << "Invalid arguments!!" << std::endl;
        return (EXIT_FAILURE);
    }
    const std::string fileName = argv[1];
    const std::string str1 = argv[2];
    const std::string str2 = argv[3];

    // Checking if file names are invalid
    if (fileName.length() == 0)
    {
        std::cerr << "Invalid filename!!" << std::endl;
        return (EXIT_FAILURE);
    }
    if (str1.length() == 0)
    {
        std::cerr << "str1 cannot be empty!!" << std::endl;
        return (EXIT_FAILURE);
    }
    if (str1 == str2)
    {
        std::cerr << "str1 cannot be equal to str2!!" << std::endl;
        return (EXIT_FAILURE);
    }
    std::string contents;
    char c;
    std::ifstream inStream(fileName.c_str(), std::ifstream::in);
    // Checking if input file can be opened
    if (!inStream.good())
    {
        std::cerr << "Could not open file for reading" << std::endl;
        inStream.close();
        return (EXIT_FAILURE);
    }
    // Reading characters into a string
    while (inStream.good())
    {
        inStream.get(c);
        if (inStream.good())
            contents.push_back(c);
    }
    inStream.close();
    // If input file is empty just create an empty output file
    if (contents.length() == 0)
    {
        std::ofstream outStream((fileName + ".replace").c_str(),
                                std::ofstream::out | std::ofstream::trunc);
        outStream.close();
        return (EXIT_SUCCESS);
    }
    // Keep replacing each occurence of the string until it is not there anymore
    while (contents.find(str1) != std::string::npos)
    {
        std::string before = contents.substr(0, contents.find(str1));
        std::string after =
            contents.substr(contents.find(str1) + str1.length(), contents.length());
        contents = before + str2 + after;
    }
    // Create an output file
    std::ofstream outStream((fileName + ".replace").c_str(),
                            std::ofstream::out | std::ofstream::trunc);
    // Check if output file has been created properly
    if (!outStream.good())
    {
        std::cerr << "Could not open file for wrting" << std::endl;
        outStream.close();
        return (EXIT_FAILURE);
    }
    // Write string to output file
    outStream << contents;
    outStream.close();
    return (EXIT_SUCCESS);
}

// ./str_replace bible.txt God god
// ./str_replace bible.txt "" god
// ./str_replace bible.txt God ""
// ./str_replace bible.txt "" ""
// ./str_replace bible.txt " God " "god"
// ./str_replace bible.txt "evening" "night"

// Example file
// 1:1 In the beginning God created the heaven and the earth.
// 1:2 And the earth was without form, and void; and darkness was upon
// the face of the deep. And the Spirit of God moved upon the face of the
// waters.
// 1:3 And God said, Let there be light: and there was light.
// 1:4 And God saw the light, that it was good: and God divided the light
// from the darkness.
// 1:5 And God called the light Day, and the darkness he called Night.
// And the evening and the morning were the first day.
// 1:6 And God said, Let there be a firmament in the midst of the waters,
// and let it divide the waters from the waters.
// 1:7 And God made the firmament, and divided the waters which were
// under the firmament from the waters which were above the firmament:
// and it was so.
// 1:8 And God called the firmament Heaven. And the evening and the
// morning were the second day.
// 1:9 And God said, Let the waters under the heaven be gathered together
// unto one place, and let the dry land appear: and it was so.
// 1:10 And God called the dry land Earth; and the gathering together of
// the waters called he Seas: and God saw that it was good.
// 1:11 And God said, Let the earth bring forth grass, the herb yielding
// seed, and the fruit tree yielding fruit after his kind, whose seed is
// in itself, upon the earth: and it was so.
// 1:12 And the earth brought forth grass, and herb yielding seed after
// his kind, and the tree yielding fruit, whose seed was in itself, after
// his kind: and God saw that it was good.
// 1:13 And the evening and the morning were the third day.
// 1:14 And God said, Let there be lights in the firmament of the heaven
// to divide the day from the night; and let them be for signs, and for
// seasons, and for days, and years: 1:15 And let them be for lights in
// the firmament of the heaven to give light upon the earth: and it was
// so.
