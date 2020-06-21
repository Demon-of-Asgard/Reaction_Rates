#!/home/demon/anaconda3/bin/python3
import sys
import os
import matplotlib.pyplot as plt
import numpy as np

#========================================================================================
def plot(info, xcol, zcol, xlabel = None, zlabel = None):
    file = os.getcwd()+info
    data = np.genfromtxt(file) #("trajectory.dat124519")
    #========================================================================================
    plt.plot(data[:,xcol],data[:,zcol],"C0-",label = "$ray-n_{\\nu_e}$")
    plt.legend()
    plt.xlabel(xlabel)
    plt.ylabel(ylabel)
    plt.title(file)
    plt.show()
    #========================================================================================

def main():
    try:
        file = sys.argv[1]

        try:
            xcol = int(sys.argv[2])
        except:
            xcol = 0
        try:
            zcol = int(sys.argv[3])
        except:
            zcol = 1

        plot(file, xcol, zcol)

    except:
        print("File name is important for plotting !!!...\n")
        exit()

if __name__ == "__main__":
    main()
