#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <utility>
#include <algorithm>
#include <fstream>
#include <ctime>

bool sortDescendingOrder(const std::pair<std::string, int>& a, const std::pair<std::string, int>& b);
std::string getCurrrentTime();

int main()
{
    std::string filePath = "";
    std::string albumToAdd;
    std::string fileName = "Albums - " + getCurrrentTime() + ".txt";
    std::ofstream AlbumFile;

    std::vector<std::pair<std::string, std::vector<std::string>>> albums;
    std::vector<int> albumsPoints;
    std::vector<std::string> comparedStrings;
    std::vector<std::pair<std::string, int>> sortedAlbums;

    char answer = ' ';

    std::cout << "Open album list from file (Y - Yes, N - No) ?" << '\n';
    std::cin >> answer;
    std::cin.ignore();

    if((answer == 'y') || (answer == 'Y'))
    {
        std::string path;
        std::string fileName;
        std::string newPath;
        std::cout << "Enter file path (Not Including file name): " << '\n';
        std::getline(std::cin, path);
        filePath = path;
        std::cout << "Enter file name (With Extension): " << '\n';
        std::getline(std::cin, fileName);
        newPath = path + "\\" + fileName; 
        std::ifstream inFile(newPath);

        if(inFile.is_open())
        {
            while(!inFile.eof())
            {
                std::string temp;
                std::getline(inFile, temp);
                albums.push_back(std::make_pair(temp, comparedStrings));
            }
        }
        else
        {
            std::cout << "Could not open file: " << path << '\n';
        }
    }
    else if((answer == 'n') || (answer == 'N'))
    {
        while(!(albumToAdd == "C" || albumToAdd == "c"))
        {
            std::cout << "Type album name to add or 'C' to continue: " << '\n';
            std::getline(std::cin, albumToAdd);

            if(!(albumToAdd == "C" || albumToAdd == "c"))
            {
                albums.push_back(std::make_pair(albumToAdd, comparedStrings));
            }
        }
    }
    else
    {
        std::cout << "Unexpected answer (Please Restart)";
    }

    AlbumFile.open(fileName.c_str());

    for (size_t i = 0; i < albums.size(); i++)
    {
        albumsPoints.push_back(0);
        if(AlbumFile.is_open())
        {
            AlbumFile << albums[i].first << '\n';
        }
    }

    AlbumFile.close();

    for (size_t i = 0; i < albums.size(); i++)
    {
        for(size_t j = 0; j < albums.size(); j++)
        {
            int chosenAlbum;
            bool repeated;
            repeated = false;

            for (size_t k = 0; k < albums[j].second.size(); k++)
            {
                if(albums[i].first == albums[j].second[k])
                {
                    repeated = true;
                }
            }

            if(albums[i] == albums[j] || repeated)
            {
                continue;
            }

            albums[i].second.push_back(albums[j].first);
            std::cout << "Type 1 for " << albums[i].first << "\nType 2 for " << albums[j].first << '\n';
            std::cin >> chosenAlbum;

            if(chosenAlbum == 1)
            {
                std::cout << "You choose " << albums[i].first << '\n' << '\n';
                albumsPoints[i] += 10;
            }
            else if(chosenAlbum == 2)
            {
                std::cout << "You choose " << albums[j].first << '\n' << '\n';
                albumsPoints[j] += 10;
            }
        }
    }

    for (size_t i = 0; i < albums.size(); i++)
    {
        sortedAlbums.push_back(std::make_pair(albums[i].first, albumsPoints[i]));
    }
    

    std::sort(sortedAlbums.begin(), sortedAlbums.end(), sortDescendingOrder);

    std::string RankedAlbumsFileName;
    if(filePath.size() == 0)
    {
        RankedAlbumsFileName = "RankedAlbums - " + getCurrrentTime() + ".txt";

    }
    else
    {
        filePath += '\\';
        RankedAlbumsFileName = filePath + "RankedAlbums - " + getCurrrentTime() + ".txt";
    }
    std::ofstream RankedAlbums;

    RankedAlbums.open(RankedAlbumsFileName.c_str());

    for (size_t i = 0; i < sortedAlbums.size(); i++)
    {
        std::cout << (i+1) << ": " << sortedAlbums[i].first << " - " << sortedAlbums[i].second << '\n';
        if(RankedAlbums.is_open())
        {
            RankedAlbums << (i+1) << ": " << sortedAlbums[i].first << " - " << sortedAlbums[i].second << '\n';
        }
    }

    RankedAlbums.close();

    return 0;
}

std::string getCurrrentTime()
{
    time_t rawTime;
    struct tm * timeinfo;
    char buffer[80];

    time (&rawTime);
    timeinfo= localtime(&rawTime);

    strftime(buffer, sizeof(buffer), "%d-%m-%Y %H-%M-%S", timeinfo);
    std::string str(buffer);

    return str;
}

bool sortDescendingOrder(const std::pair<std::string, int>& a, const std::pair<std::string, int>& b)
{
    return a.second > b.second;
}