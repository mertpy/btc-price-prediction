void restKlinesGetSet(string symbol, int kline){


    string exchange="USDT";

    CURL* curl;
    CURLcode res;
    string readBuffer;

    string link1="https://api.binance.com/api/v1/klines?symbol=";
    string link2=exchange;
    string link3="&interval=1m&limit=";
    string link4=to_string(kline);
    string link=link1+symbol+link2+link3+link4;

        readBuffer.clear();
        curl = curl_easy_init();
        if (curl) {
            curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
            curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);

            curl_easy_setopt(curl, CURLOPT_URL, link.c_str());
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);

            res = curl_easy_perform(curl);
            curl_easy_cleanup(curl);

            if (res == CURLE_OK) {
                try {           
                    json dataset = json::parse(readBuffer); 
                    
                    ofstream file("csv/btc_usdt_kline.csv");
                    file<<"timestamp,open,high,low,close,volume\n";
                    for(int i=0;i<1000;i++){
                        file<<dataset[i][0]<<","
                            <<dataset[i][1]<<","
                            <<dataset[i][2]<<","
                            <<dataset[i][3]<<","
                            <<dataset[i][4]<<","
                            <<dataset[i][5]<<"\n";
                    }
                        
                }
                
                catch (json::parse_error& e) {
                    cerr << "JSON parse hatası: " << e.what() << endl;
                }
            }

            else {
                cerr << "curl_easy_perform() başarısız: " << curl_easy_strerror(res) << endl;
            }
        }

}

void inputData(string symbol, int kline){


    string exchange="USDT";

    CURL* curl;
    CURLcode res;
    string readBuffer;

    string link1="https://api.binance.com/api/v1/klines?symbol=";
    string link2=exchange;
    string link3="&interval=1m&limit=";
    string link4=to_string(kline);
    string link=link1+symbol+link2+link3+link4;

        readBuffer.clear();
        curl = curl_easy_init();
        if (curl) {
            curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
            curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);

            curl_easy_setopt(curl, CURLOPT_URL, link.c_str());
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);

            res = curl_easy_perform(curl);
            curl_easy_cleanup(curl);

            if (res == CURLE_OK) {
                try {           
                    json dataset = json::parse(readBuffer);
                    
                    ofstream file("csv/input.csv");
                    file<<"open,high,low,volume\n";
                    for(int i=0;i<1;i++){
                        file<<dataset[i][1]<<","
                            <<dataset[i][2]<<","
                            <<dataset[i][3]<<","
                            <<dataset[i][5]<<"\n";
                    }
                        
                }
                
                catch (json::parse_error& e) {
                    cerr << "JSON parse hatası: " << e.what() << endl;
                }
            }

            else {
                cerr << "curl_easy_perform() başarısız: " << curl_easy_strerror(res) << endl;
            }
        }

    

}