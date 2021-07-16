import pandas as pd
import numpy as np
from scipy.optimize.zeros import results_c
file="vehicle_ADVISE_model/Solver/sim/Results_results.csv"
df = pd.read_csv(file, error_bad_lines=False, skiprows=37)

df.rename(columns={"Experiment 1":"Experiment"}, inplace=True)
df=df[["Experiment","Name", "Start Time", "Mean", "Confidence Interval"]]

ex=df.groupby(["Experiment"], as_index=False)["Experiment"].first()
ex=np.array(ex["Experiment"])

for t in ex:
    if(t[0]=='E'):
        data=df[df["Experiment"]==t]
        data=data[data["Name"]=="DoS"]
        print(data[["Start Time", "Mean",  "Confidence Interval"]])
