#!python
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import matplotlib.cm as cm
import matplotlib
file="vehicle_ADVISE_model/Solver/sim/Results_results.csv"
info = pd.read_csv(file, header=None, error_bad_lines=False, skiprows=32, nrows=4)
info=np.array(info)
df = pd.read_csv(file, error_bad_lines=False, skiprows=37)
df.rename(columns={"Experiment 1":"Experiment"}, inplace=True)
df=df[["Experiment","Result Type","Name", "Start Time", "Mean", "Confidence Interval"]]

ex=df.groupby(["Experiment"], as_index=False)["Experiment"].first()
ex=np.array(ex["Experiment"])
cmap=cm.get_cmap("rainbow")
goals=["DoS", "vehicleUndesideredBehaviour", "dataBreach"]
p_colors=cmap(np.linspace(0, 1 ,20))
font = {'size'   : 13}
matplotlib.rc('font', **font)
for t in ex:
    if(t[0]!='E'):
        continue
    data=df[df["Experiment"]==t]
    if(info==[]):
        info=np.array( np.empty((4,4)), np.chararray)
        inf=data[["Experiment","Result Type","Name", "Start Time"]]
        info[0]=np.array(inf[inf["Name"]=="IDSsensitivity"])
        info[1]=np.array(inf[inf["Name"]=="attacker"])
        info[2]=np.array(inf[inf["Name"]=="codeObfuscation"])
        info[3]=np.array(inf[inf["Name"]=="firewallSensitivity"])
    if(info[1,3]=="'H'"):
        plot=1
        attacker="Hacker"
    if(info[1,3]=="'P'"):
        plot=2
        attacker="Physical Intruder"
    if(info[1,3]=="'I'"):
        attacker="Insider"
        plot=3
    for i in range(0,3):
        plt.figure(plot+i*3)
        prob=data[data["Name"]==goals[i]]
        prob=np.array(prob[["Start Time", "Mean",  "Confidence Interval"]]).astype(float)
        plt.title(attacker+" "+goals[i])
        plt.xlabel("time")
        plt.xticks(np.arange(0,220,20))
        plt.ylabel("probability")
        plt.yticks(np.arange(0,11,0.1))
        label=info[0,2]+"= "+info[0,3]+"\n"
        label+=info[2,2]+"= "+info[2,3]+"\n"
        label+=info[3,2]+"= "+info[3,3]
        plt.errorbar(x=prob[:,0], y=prob[:,1], yerr=prob[:,2], capsize=3, linestyle="solid",
               marker='s', markersize=3, mfc="black", mec="black", label=label)
        plt.legend(title="Experiments", loc='lower center', bbox_to_anchor=(0.87,0.19))
        print(t)
        print(info)
    info=[]

plt.show()
