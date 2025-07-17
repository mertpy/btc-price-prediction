#include <iostream>
#include "json/nlohmann/json.hpp"
#include <string>
#include <cmath>
#include <math.h>
#include <clocale>
#include <vector>
#include <curl/curl.h>
#include <fstream>
#include <thread>
#pragma



using json = nlohmann::json;
using namespace std;


//for cURL
size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    ((string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

