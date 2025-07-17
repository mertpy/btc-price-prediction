#include "c++/header.h"
#include "c++/binance_api.h"
#include <cstdlib>

int main(){
    restKlinesGetSet("BTC",1000);

    system("python python/model.py");

    inputData("BTC",1);

    system("python python/predict.py");

    ifstream prediction("prediction.txt");
    string price;
    getline(prediction, price);
    cout<<"Predicted price is "<<price<<endl;

    int x=0;
    while(x!=1){
        cout<<"For exit enter \"1\"\n";
        cin>>x;
    }

    return 0;
}