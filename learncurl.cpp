#include<iostream>
#include<curl/curl.h>

int main(){
    CURL *curl;
    CURLcode result;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    curl_easy_setopt(curl, CURLOPT_URL, "hello");
    curl_easy_setopt(curl, CURLOPT_USERNAME, "midwestmetro");
    curl_easy_setopt(curl, CURLOPT_USERPWD, "Metroboomin50");

    curl_global_cleanup();
}