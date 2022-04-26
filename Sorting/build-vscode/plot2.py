import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
import codecs
import pandas as pd

files = ['MRG_I_MS_RAND_200_20000.csv', 'MRG_R_MS_RAND_200_20000.csv', 'QS_1R_MS_RAND_200_20000.csv', 'QS_1R_MS_AO_200_20000.csv', 'QS_2R_MS_RAND_200_20000.csv', 'QS_2R_MS_AO_200_20000.csv', 'QS_FP_MS_RAND_200_20000.csv', 'QS_FP_MS_AO_200_20000.csv', 'RADIX_MS_RAND_200_20000.csv', 'STL_SORT_MS_RAND_200_20000.csv', 'STL_SORT_MS_AO_200_20000.csv']
headers = ['time', 'number_runs', 'vector_size', 'recursive_calls', 'depth_recursive_stack', 'custom']
datas = []
for i in range(len(files)):
    datas.append(pd.read_csv(files[i], header=None))

titles = ["MergeSort Iterativo (dados randômicos)", "MergeSort Recursivo (dados randômicos)", "QuickSort 1 recursão (dados randômicos)", "QuickSort 1 recursão (dados quase ordenados)", "QuickSort 2 recursões (dados randômicos)", "QuickSort 2 recursões (dados quase ordenados)", "QuickSort pivô fixo (dados randômicos)", "QuickSort pivô fixo (dados quase ordenados)", "RadixSort (dados randômicos)", "STL sort (dados randômicos)", "STL sort (dados quase ordenados)"]
fit_names = [0] * 11
fig = plt.figure(figsize=(8,8))
plt.title('QuickSort: 1 recursão X 2 recursões')
scats = [0] * 11
l_fit_scats = [0] * 11
legend_objs = []
legend_names = []
for i in [1,3,8]:
    data = datas[i]
    x = data[2].values
    y = data[3].values
    y2 = data[4].values
    if i == 0:
        scat = plt.scatter(x,y,marker='<', s=55)
    elif i == 8:
        scat = plt.scatter(x, y,marker='>', s = 15)
    else:
        scat = plt.scatter(x,y)
    scats[i] = scat
    plt.xlabel("Tamanho do vetor")
    plt.ylabel("Número de chamadas recursivas")
    
    x_i = x[0]
    x_f = x[-1]
    x_fit = np.linspace(x_i, x_f, 100000)    
    

    if i in [0]:
        fit_names[i] = 'Fit log(n)'
        fit_scat = np.polyfit(np.log(x), y, 1)
        a = fit_scat[0]
        b = fit_scat[1]
        print(fit_scat)
        y_fit_scat = a * np.log(x_fit) + b
    elif i == 7:
        fit_names[i] = 'Fit quadrático'
        fit_scat = np.polyfit(x, y, 2)
        a = fit_scat[0]
        b = fit_scat[1]
        c = fit_scat[2]
        print(fit_scat)
        y_fit_scat = a * np.multiply(x_fit, x_fit) + b * x_fit + c
    elif i  in [2,4]:
        fit_names[i] = 'Fit linear'
        fit_scat = np.polyfit(x, y, 1)
        a = fit_scat[0]
        b = fit_scat[1]
        print(fit_scat)
        y_fit_scat = a * x_fit + b
    else:
        fit_names[i] = 'Fit nlog(n)'
        fit_scat = np.polyfit(np.multiply(np.log(x), x), y, 1)
        a = fit_scat[0]
        b = fit_scat[1]
        print(fit_scat)
        y_fit_scat = a * np.multiply(np.log(x_fit), x_fit) + b

    y_i = y[0]
    y_f = y[-1]

    #straight_l, = plt.plot(x_fit, y_i + (x_fit - x_i)*(y_f - y_i)/(x_f - x_i))

    l_fit_scat, = plt.plot(x_fit, y_fit_scat)
    l_fit_scats[i] = l_fit_scat

    legend_objs.append(scats[i])
    legend_objs.append(l_fit_scats[i])
    legend_names.append(titles[i])
    legend_names.append(fit_names[i])

plt.legend(legend_objs, legend_names)
plt.show()

