#include "CampusCompass.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

campusCompass::campusCompass() {
    // initialize your object
}

bool campusCompass::ParseCSV(const string &edges_filepath, const string &classes_filepath) {
    ifstream file1(classes_filepath); // load class catalog
    if (!file1.is_open()) {
        cerr << "File " << classes_filepath << "failed to open." << endl;
        return false;
    }
    string classesRow;
    string tok1, tok2, tok3, tok4, tok5;
    string stHours, stMinutes, endHours, endMinutes;
    string skipHeader;
    getline(file1, skipHeader);
    while (getline(file1, classesRow)) {
        istringstream stream(classesRow);
        getline(stream, tok1, ',');
        getline(stream, tok2, ',');
        getline(stream, stHours, ':');
        getline(stream, stMinutes, ',');
        getline(stream, endHours, ':');
        getline(stream, endMinutes, ',');
        tuple classData{stoi(tok2), (stoi(stHours) * 60 + stoi(stMinutes)), (stoi(endHours) * 60 + stoi(endMinutes))};
        classList[tok1] = classData; // start and end times stored as minutes after midnight
    }
    file1.close();

    ifstream file2(edges_filepath);
    if (!file2.is_open()) {
        cerr << "File " << edges_filepath << "failed to open." << endl;
        return false;
    }
    string edgesRow;
    getline(file2, skipHeader);
    while (getline(file2, edgesRow)) {
        istringstream stream(edgesRow);
        getline(stream, tok1, ',');
        getline(stream, tok2, ',');
        getline(stream, tok3, ',');
        getline(stream, tok4, ',');
        getline(stream, tok5, ',');
        graph[stoi(tok1)].push_back(make_pair(stoi(tok2), stoi(tok5))); // graph[from].push_back(to, weight)
        locNames[stoi(tok1)] = tok3;
        locNames[stoi(tok2)] = tok4;
    }
    file2.close();

    // return boolean based on whether parsing was successful or not
    return true;
}

bool campusCompass::ParseCommand(const string &command) {
    // do whatever regex you need to parse validity
    // hint: return a boolean for validation when testing. For example:
    bool is_valid = true; // replace with your actual validity checking

    return is_valid;
}

void campusCompass::insert(string studentName, int studentID) {

}



