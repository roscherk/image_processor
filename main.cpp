#include "BMP.h"
#include "FilterFactory.h"
#include <iostream>
#include <queue>


const std::string HELP_MESSAGE =
    "usage:  image_processor [--help] {input_file_path} {output_file_path}\n"
    "\t\t\t[-crop {uint new_width} {uint new_height}] [-gs] [-neg] [-sharp]\n\t\t\t[-edge {uint threshold}] [-blur "
    "{uint sigma}] [-custom "
    "{uint distortion_degree}]\n\n"
    "Available filters:\n"
    "\tcrop:   resizes the input image to new_width x new_height pixels\n"
    "\tgs:     converts the input image to grayscale\n"
    "\tneg:    inverts the colors in the input image\n"
    "\tsharp:  increases the sharpness of the input image\n"
    "\tedge:   identifies edges and curves in the input image\n"
    "\t\tthreshold (positive integer) controls the noise sensitivity\n"
    "\tblur:   blurs the input image (gaussian blur)\n"
    "\t\tsigma (positive integer) controls the degree of blur\n"
    "\tcustom: creates the triggered version of the input image\n"
    "\t\tdistortion_degree (positive integer) controls the degree of distortion";

bool IsInt(const std::string& string) {
    // принимает на вход непустую строку; возвращает true, если строка является положительным целым числом
    for (size_t i = 0; i < string.size(); ++i) {
        if (!std::isdigit(string[i])) {
            return false;
        }
    }
    return true;
}

int main(int argc, char** argv) {
    if (argc == 1 || (argc == 2 && std::string(argv[1]) == "--help")) {
        std::cout << HELP_MESSAGE << std::endl;
    } else if (argc > 2) {
        std::string in_path = std::string(argv[1]);
        std::string out_path = std::string(argv[2]);
        BMP file;
        std::queue<std::unique_ptr<Filter>> filters;
        try {
            Image image = file.Read(in_path);
            for (int i = 3; i < argc; ++i) {
                // collect filters
                std::string arg(argv[i]);
                if (arg == "-crop") {
                    if (i + 2 >= argc) {
                        throw std::invalid_argument("Too few parameters for -crop");
                    } else if (!IsInt(argv[i + 1]) || !IsInt(argv[i + 2])) {
                        throw std::invalid_argument("Invalid parameters for -crop: 2 uint parameters required");
                    }
                    filters.push(FilterFactory::CreateFilter(FilterFactory::FilterType::CROP, atoi(argv[i + 1]),
                                                             atoi(argv[i + 2])));
                    i += 2;
                } else if (arg == "-gs") {
                    filters.push(FilterFactory::CreateFilter(FilterFactory::FilterType::GRAYSCALE));
                } else if (arg == "-neg") {
                    filters.push(FilterFactory::CreateFilter(FilterFactory::FilterType::NEGATIVE));
                } else if (arg == "-sharp") {
                    filters.push(FilterFactory::CreateFilter(FilterFactory::FilterType::SHARPENING));
                } else if (arg == "-edge") {
                    if (i + 1 >= argc) {
                        throw std::invalid_argument("Too few parameters for -edge");
                    } else if (!IsInt(argv[i + 1])) {
                        throw std::invalid_argument("Invalid parameter for -edge: 1 uint parameter required");
                    }
                    filters.push(
                        FilterFactory::CreateFilter(FilterFactory::FilterType::EDGE_DETECTION, atoi(argv[i + 1])));
                    ++i;
                } else if (arg == "-blur") {
                    if (i + 1 >= argc) {
                        throw std::invalid_argument("Too few parameters for -blur");
                    } else if (!IsInt(argv[i + 1])) {
                        throw std::invalid_argument("Invalid parameter for -blur: 1 uint parameter required");
                    }
                    filters.push(
                        FilterFactory::CreateFilter(FilterFactory::FilterType::GAUSSIAN_BLUR, atoi(argv[i + 1])));
                    ++i;
                } else if (arg == "-custom") {
                    if (i + 1 >= argc) {
                        throw std::invalid_argument("Too few parameters for -custom");
                    } else if (!IsInt(argv[i + 1])) {
                        throw std::invalid_argument("Invalid parameter for -custom: 1 uint parameter required");
                    }
                    filters.push(FilterFactory::CreateFilter(FilterFactory::FilterType::CUSTOM, atoi(argv[i + 1])));
                    ++i;
                } else {
                    throw std::invalid_argument("Unknown command: " + arg);
                }
            }
            while (!filters.empty()) {
                // apply filters
                try {
                    filters.front()->Apply(image);
                } catch (const std::exception& exception) {
                    throw std::runtime_error(exception.what());
                }
                filters.pop();
            }
            file.Write(out_path, image);
        } catch (const std::ios_base::failure& exception) {
            std::cout << "Error! File \"" << in_path << "\": " << exception.what() << std::endl;
        } catch (const std::invalid_argument& exception) {
            std::cout << "Error! Command prompt: " << exception.what() << std::endl;
        } catch (const std::domain_error& exception) {
            std::cout << "Error! Function " << exception.what() << std::endl;
        } catch (const std::runtime_error& exception) {
            std::cout << "Error! " << exception.what() << std::endl;
        }
    }
    return 0;
}
