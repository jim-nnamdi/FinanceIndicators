// main.cpp
// Adapted from https://curl.haxx.se/libcurl/c/https.html
#include <iostream>
#include <curl/curl.h>

using namespace std;

struct curl_slist *headers;

int main(void)
{
  CURL *curl;
  CURLcode result;

  curl_global_init(CURL_GLOBAL_DEFAULT);

  curl = curl_easy_init();
  if (curl) {

    // headers = curl_slist_append(headers, "Content-Type:application/json");
    // headers = curl_slist_append(headers, "Authorization:Bearer xxx");

    // Set URL
    curl_easy_setopt(curl, CURLOPT_URL, "https://opensky-network.org/api/flights/arrival?airport=EDDF&begin=1517227200&end=1517230800");

    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
    // curl_easy_setopt(curl, CURLOPT_USERPWD, "midwestmetro:Metroboomin50");
    // If you want to set any more options, do it here, before making the request.

    // Perform the request which prints to stdout
    result = curl_easy_perform(curl);

    // Error check
    if (result != CURLE_OK) {
      std::cerr << "Error during curl request: " 
                << curl_easy_strerror(result) << std::endl;
    }

    curl_easy_cleanup(curl);
  } else {
    std::cerr << "Error initializing curl." << std::endl;
  }

  curl_global_cleanup();

  return 0;
}