import pandas as pd
import joblib

df=pd.read_csv("./csv/input.csv")

model=joblib.load("python/rf_model.pkl")

prediction=model.predict(df)[0]

with open("prediction.txt", "w") as f:
    f.write(f"{prediction:.2f}")