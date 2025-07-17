
# 🚀 BTC Price Prediction System (C++ + Python)

This project combines the power of **C++** and **Python** to fetch real-time BTC data from Binance and perform price prediction using a **RandomForestRegressor** model.

## 🔧 Tech Stack

- **C++** – For high-performance data retrieval
- **Python (scikit-learn, pandas)** – For machine learning and data processing
- **Binance API** – Real-time crypto market data
- **nlohmann/json** – JSON parsing in C++


## ⚙️ How It Works

1. `main.cpp` fetches the last 1000 1-minute BTC kline data from Binance.
2. The data is processed in `python/model.py` and trained using RandomForestRegressor.
3. New real-time data is fetched and a price prediction is made using `python/predict.py`.
4. The predicted price is displayed in the terminal and saved to `prediction.txt`.

## 🛠 Setup and Execution

### Requirements

For Python:

```
pandas
scikit-learn
```

For C++:

- `g++` or `clang++`
- `nlohmann/json` (header-only, included in project) 
- `libcurl`

### Running the Project

```bash
# Compile C++ code
g++ main.cpp -o main.exe -std=c++17 -lcurl

# Run the program
main.exe
```
