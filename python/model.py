import pandas as pd
from sklearn.ensemble import RandomForestRegressor
from sklearn.model_selection import train_test_split
import joblib

df=pd.read_csv("./csv/btc_usdt_kline.csv")
df["timestamp"]=pd.to_datetime(df["timestamp"], unit="ms")
df["target"] = df["close"].shift(-1)
df=df.dropna()

y=df["target"]
x=df.drop(columns=["target","timestamp","close"])

train_size = int(len(df) * 0.77)
x_train, x_test = x[:train_size], x[train_size:]
y_train, y_test = y[:train_size], y[train_size:]

rfr=RandomForestRegressor(n_estimators=200, max_depth=5, random_state=11)
model=rfr.fit(x_train,y_train)

joblib.dump(model, "python/rf_model.pkl")

