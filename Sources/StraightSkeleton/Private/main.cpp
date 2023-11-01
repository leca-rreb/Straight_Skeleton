#include <iostream>

#include "../Public/StraightSKeletonBuilder.h"

void DisplayHelp()
{
    std::cerr << "./sskel [INPUT] [OUTPUT]\n";
    std::cerr << "INPUT is a text file containing a list of 2D points which\n"
                 "make up a 2D simple polygon. OUTPUT is a file of your\n"
                 "choice that will be overwritten with the result, i.e. the\n"
                 "straight skeleton of the polygon in INPUT.\n";
    // TODO: Define the format the input file must have.
}

int main(int argc, char const* argv[])
{

    if (argc == 2)
    {
        std::string option { argv[1] };
        if (option == "-h")
        {
            DisplayHelp();
            return EXIT_SUCCESS;
        }
    }
    
    if (argc != 3)
    {
        std::cerr << "Error: invalid number of arguments.\n";
        DisplayHelp();
        return EXIT_FAILURE;
    }

    // Read input file.
    Polygon polygon { { } };

    std::vector<Bone> sskel { StraightSkeletonBuilder::Skeletonize(polygon) };

    return EXIT_SUCCESS;
}
