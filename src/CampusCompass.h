#pragma once
#include <string>
#include <vector>
#include <map>
#include <tuple>

using namespace std;

struct student {
    string name;
    int ID;
    int residenceID;
    vector<string> classCodes;
};

class campusCompass {
private:
    // Think about what member variables you need to initialize
    // perhaps some graph representation?
    // adjacency list of vertices
    // map of location names
    map<int, vector<pair<int, int>>> graph; // adjacency list, graph[from] = {to, weight}
    map<int, string> locNames; // map of location names, locNames[locationID] = name
    vector<student> students; // list of students
    map<string, tuple<int, int, int>> classList; // catalog of all courses possible, removeClass should remember to remove the class from every student
public:
    // Think about what helper functions you will need in the algorithm
    campusCompass(); // constructor
    bool ParseCSV(const string &edges_filepath, const string &classes_filepath);
    bool ParseCommand(const string &command);
    void insert(string studentName, int studentID);
};
