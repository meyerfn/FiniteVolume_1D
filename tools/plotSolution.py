import matplotlib.pyplot as plt
import numpy as np

data = np.loadtxt(
    "/media/fm/2881fd19-010f-4d7b-a148-a8973130f3311/fabian/cpp-coding/FV1d/example.txt"
)
plt.plot(data)
plt.show()
