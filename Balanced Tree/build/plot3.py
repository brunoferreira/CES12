import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
import codecs


passo = []
n = []
t_search_stl = []
t_search_alu = []
t_add_stl = []
t_add_alu = []
with codecs.open('oak_search.csv', encoding='utf-8-sig') as f:
    for line in f:
        s = line.split(', ')
        passo.append(float(s[0]))
        n.append(float(s[1]))
        t_search_stl.append(float(s[2]))
        t_search_alu.append(float(s[3]))
        t_add_stl.append(float(s[4]))
        t_add_alu.append(float(s[5]))

fig = plt.figure(figsize=(8,8))
alu = plt.scatter(n, t_add_alu)
stl = plt.scatter(n, t_add_stl)
plt.title("Tempo de inserção")
plt.xlabel("#elementos inseridos")
plt.ylabel("Tempo em microssegundos")

fit_alu = np.polyfit(np.log(n), t_add_alu, 1)
fit_stl = np.polyfit(np.log(n), t_add_stl, 1)
x_i = n[0]
x_f = n[-1]

x_fit = np.linspace(x_i, x_f, 1000)
y_fit_alu = fit_alu[0] * np.log(x_fit) + fit_alu[1]
y_fit_stl = fit_stl[0] * np.log(x_fit) + fit_stl[1]

l_fit_alu, = plt.plot(x_fit, y_fit_alu)
l_fit_stl, = plt.plot(x_fit, y_fit_stl)
plt.legend((alu, stl, l_fit_alu, l_fit_stl), ('Tempo implementação Aluno', 'Tempo implementação STL', 'Fit logarítmico implementação Aluno', 'Fit logarítmico implementação STL'))
plt.show()