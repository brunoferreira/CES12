import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
import codecs

X = []
x = []
y = []
z = []
with codecs.open('torusALUg.asc', encoding='utf-8-sig') as f:
    for line in f:
        s = line.split()
        X.append([float(s[i]) for i in range(3)])
        x.append(float(s[0]))
        y.append(float(s[1]))
        z.append(float(s[2]))

fig = plt.figure(figsize=(8,8))
ax = fig.add_subplot(111, projection='3d')
#ax.scatter(x, y, z)
ax.scatter3D(x, y, z, c=x, cmap='Greens')
ax.set_title("Pontos do torusALUg.asc")
ax.set_xlabel("Coordenada x")
ax.set_ylabel("Coordenada y")
ax.set_zlabel("Coordenada z")
plt.show()